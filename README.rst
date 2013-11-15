python-salsa20
==============

Bindings for the NaCL implementation of Salsa20 and XSalsa20 by D. J. Bernstein (taken from libsodium).

Compatible with Python 2.6, 2.7 and 3.3.

The library performs a self-test at each import.

Installation
------------

::

  pip install salsa20

Usage
-----

::

  def Salsa20_keystream(length, nonce, key)
  def Salsa20_xor(message, nonce, key)

  def XSalsa20_keystream(length, nonce, key)
  def XSalsa20_xor(message, nonce, key)

Use ``[X]Salsa20_keystream`` to generate a keystream of the desired length, or pass ``[X]Salsa20_xor`` a plaintext or a ciphertext to have it XOR'd with the keystream.

Being a stream cipher, ``[X]Salsa20_xor`` does both encryption and decryption.

All values must be binary strings (``str`` on Python 2, ``bytes`` on Python 3)

Example
-------

>>> from salsa20 import XSalsa20_xor
>>> from os import urandom
>>> IV = urandom(24)
>>> KEY = b'*secret**secret**secret**secret*'
>>> ciphertext = XSalsa20_xor(b"IT'S A YELLOW SUBMARINE", IV, KEY)
>>> print(XSalsa20_xor(ciphertext, IV, KEY).decode())
IT'S A YELLOW SUBMARINE
