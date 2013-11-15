/*
 * This file is part of Python Salsa20
 * a Python bridge to the libsodium C [X]Salsa20 library
 *
 * Released under The BSD 3-Clause License
 * Copyright (c) 2013 Keybase
 *
 * Bridge C module
 */

#include <Python.h>

#include "salsa20.h"

#if !defined(DL_EXPORT)

#if defined(HAVE_DECLSPEC_DLL)
#define DL_EXPORT(type) __declspec(dllexport) type
#else
#define DL_EXPORT(type) type
#endif

#endif


/* Exported trampolines */
DL_EXPORT(int) exp_stream_salsa20(unsigned char * c,unsigned long long clen,const unsigned char * n,const unsigned char * k) {
    /* int crypto_stream_salsa20(                       // generate the salsa20 keystream
            unsigned char *c,unsigned long long clen,   // empty allocated destination buffer of len clen
      const unsigned char *n,                           // 8byte nonce
      const unsigned char *k                            // 32byte key
    ) */
    return crypto_stream_salsa20(c, clen, n, k);
}

DL_EXPORT(int) exp_stream_salsa20_xor(unsigned char *c, const unsigned char *m,unsigned long long mlen, const unsigned char *n, const unsigned char *k) {
    /* int crypto_stream_salsa20_xor(                   // encrypt a message under a salsa20 keystream
            unsigned char *c,                           // empty allocated destination buffer of len mlen
      const unsigned char *m,unsigned long long mlen,   // the message and its length
      const unsigned char *n,                           // 8byte nonce
      const unsigned char *k                            // 32byte key
    ) */
    return crypto_stream_salsa20_xor(c, m, mlen, n, k);
}

DL_EXPORT(int) exp_stream_xsalsa20(unsigned char * c,unsigned long long clen,const unsigned char * n,const unsigned char * k) {
    /* int crypto_stream_xsalsa20(                      // generate the xsalsa20 keystream
            unsigned char *c,unsigned long long clen,   // empty allocated destination buffer of len clen
      const unsigned char *n,                           // 24byte nonce
      const unsigned char *k                            // 32byte key
    ) */
    return crypto_stream_xsalsa20(c, clen, n, k);
}

DL_EXPORT(int) exp_stream_xsalsa20_xor(unsigned char *c, const unsigned char *m,unsigned long long mlen, const unsigned char *n, const unsigned char *k) {
    return crypto_stream_xsalsa20_xor(c, m, mlen, n, k);
}

/*
  We need a stub init_salsa20 function so the module will link as a proper module.
  Do not import _salsa20 from python; it will not work since _salsa20 is not a *real* module
*/
PyMODINIT_FUNC init_salsa20(void) { }
PyMODINIT_FUNC PyInit__salsa20(void) { }
