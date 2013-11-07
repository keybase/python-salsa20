import argparse
import salsa20
import binascii

parser = argparse.ArgumentParser()
parser.add_argument("-k", "--key", type=str, help="the encryption key", default="0123456789abcdef"*4)
parser.add_argument("-n", "--nonce", type=str, help="the nonce", default="0123456789abcdef"*3)
parser.add_argument("-l", "--length", type=int, help="the length of the output", default=64)
args = parser.parse_args()

stream = salsa20.XSalsa20_keystream(args.length, binascii.unhexlify(args.nonce), binascii.unhexlify(args.key))
print binascii.hexlify(stream)