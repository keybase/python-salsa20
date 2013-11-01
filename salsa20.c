/*-
 * Copyright 2013 Keybase
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
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
