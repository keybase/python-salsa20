python-salsa20
==============

Bindings for the NaCL implementation of Salsa20 and XSalsa20 by D. J. Bernstein (taken from libsodium).

Compatible with Python 2 and 3.

`pip install https://github.com/keybase/python-salsa20/zipball/master`

```python
def Salsa20_keystream(length, nonce, key)
def Salsa20_encrypt(message, nonce, key)

def XSalsa20_keystream(length, nonce, key)
def XSalsa20_encrypt(message, nonce, key)
```
