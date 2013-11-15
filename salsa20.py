"""
This file is part of Python Salsa20
a Python bridge to the libsodium C [X]Salsa20 library

Released under The BSD 3-Clause License
Copyright (c) 2013 Keybase

Python module and ctypes bindings
"""

import imp
import sys

from ctypes import (cdll,
                    c_char_p, c_int, c_uint64,
                    create_string_buffer)

_salsa20 = cdll.LoadLibrary(imp.find_module('_salsa20')[1])


_stream_salsa20 = _salsa20.exp_stream_salsa20
_stream_salsa20.argtypes = [  c_char_p,  # unsigned char * c
                              c_uint64,  # unsigned long long clen
                              c_char_p,  # const unsigned char * n
                              c_char_p   # const unsigned char * k
                           ]
_stream_salsa20.restype = c_int

_stream_salsa20_xor = _salsa20.exp_stream_salsa20_xor
_stream_salsa20_xor.argtypes = [  c_char_p,  # unsigned char * c
                                  c_char_p,  # const unsigned char *m
                                  c_uint64,  # unsigned long long mlen
                                  c_char_p,  # const unsigned char * n
                                  c_char_p   # const unsigned char * k
                               ]
_stream_salsa20_xor.restype = c_int

_stream_xsalsa20 = _salsa20.exp_stream_xsalsa20
_stream_xsalsa20.argtypes = [  c_char_p,  # unsigned char * c
                               c_uint64,  # unsigned long long clen
                               c_char_p,  # const unsigned char * n
                               c_char_p   # const unsigned char * k
                            ]
_stream_xsalsa20.restype = c_int

_stream_xsalsa20_xor = _salsa20.exp_stream_xsalsa20_xor
_stream_xsalsa20_xor.argtypes = [  c_char_p,  # unsigned char * c
                                   c_char_p,  # const unsigned char *m
                                   c_uint64,  # unsigned long long mlen
                                   c_char_p,  # const unsigned char * n
                                   c_char_p   # const unsigned char * k
                                ]
_stream_xsalsa20_xor.restype = c_int


IS_PY2 = sys.version_info < (3, 0, 0, 'final', 0)

def _ensure_bytes(data):
    if (IS_PY2 and not isinstance(data, str)) or (not IS_PY2 and not isinstance(data, bytes)):
        raise TypeError('can not encrypt/decrypt unicode objects')


def Salsa20_keystream(length, nonce, key):
    _ensure_bytes(nonce)
    _ensure_bytes(key)
    if not len(key) == 32: raise ValueError('invalid key length')
    if not len(nonce) == 8: raise ValueError('invalid nonce length')
    if not length > 0: raise ValueError('invalid length')

    outbuf = create_string_buffer(length)
    _stream_salsa20(outbuf, length, nonce, key)
    return outbuf.raw

def Salsa20_xor(message, nonce, key):
    _ensure_bytes(nonce)
    _ensure_bytes(key)
    _ensure_bytes(message)
    if not len(key) == 32: raise ValueError('invalid key length')
    if not len(nonce) == 8: raise ValueError('invalid nonce length')
    if not len(message) > 0: raise ValueError('invalid message length')

    outbuf = create_string_buffer(len(message))
    _stream_salsa20_xor(outbuf, message, len(message), nonce, key)
    return outbuf.raw


def XSalsa20_keystream(length, nonce, key):
    _ensure_bytes(nonce)
    _ensure_bytes(key)
    if not len(key) == 32: raise ValueError('invalid key length')
    if not len(nonce) == 24: raise ValueError('invalid nonce length')
    if not length > 0: raise ValueError('invalid length')

    outbuf = create_string_buffer(length)
    _stream_xsalsa20(outbuf, length, nonce, key)
    return outbuf.raw

def XSalsa20_xor(message, nonce, key):
    _ensure_bytes(nonce)
    _ensure_bytes(key)
    _ensure_bytes(message)
    if not len(key) == 32: raise ValueError('invalid key length')
    if not len(nonce) == 24: raise ValueError('invalid nonce length')
    if not len(message) > 0: raise ValueError('invalid message length')

    outbuf = create_string_buffer(len(message))
    _stream_xsalsa20_xor(outbuf, message, len(message), nonce, key)
    return outbuf.raw


def self_test():
    import binascii, hashlib

    key = binascii.unhexlify('1b27556473e985d462cd51197a9a46c76009549eac6474f206c4ee0844f68389')
    nonce = binascii.unhexlify('69696ee955b62b73cd62bda875fc73d68219e0036b7a0b37')

    output = XSalsa20_keystream(4194304, nonce, key)
    assert hashlib.sha256(output).hexdigest() == '662b9d0e3463029156069b12f918691a98f7dfb2ca0393c96bbfc6b1fbd630a2'

    message = binascii.unhexlify('0000000000000000000000000000000000000000000000000000000000000000be075fc53c81f2d5cf141316ebeb0c7b5228c52a4c62cbd44b66849b64244ffce5ecbaaf33bd751a1ac728d45e6c61296cdc3c01233561f41db66cce314adb310e3be8250c46f06dceea3a7fa1348057e2f6556ad6b1318a024a838f21af1fde048977eb48f59ffd4924ca1c60902e52f0a089bc76897040e082f937763848645e0705')

    output = XSalsa20_xor(message, nonce, key)
    assert output[32:] == binascii.unhexlify('8e993b9f48681273c29650ba32fc76ce48332ea7164d96a4476fb8c531a1186ac0dfc17c98dce87b4da7f011ec48c97271d2c20f9b928fe2270d6fb863d51738b48eeee314a7cc8ab932164548e526ae90224368517acfeabd6bb3732bc0e9da99832b61ca01b6de56244a9e88d5f9b37973f622a43d14a6599b1f654cb45a74e355a5')

    key = binascii.unhexlify('dc908dda0b9344a953629b733820778880f3ceb421bb61b91cbd4c3e66256ce4')
    nonce = binascii.unhexlify('8219e0036b7a0b37')

    output = Salsa20_keystream(4194304, nonce, key)
    assert hashlib.sha256(output).hexdigest() == '662b9d0e3463029156069b12f918691a98f7dfb2ca0393c96bbfc6b1fbd630a2'



self_test()
