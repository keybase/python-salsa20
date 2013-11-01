/*
version 20080913
derived from work by D. J. Bernstein
Public domain.
*/

/* int crypto_stream_salsa20(                       // generate the salsa20 keystream
        unsigned char *c,unsigned long long clen,   // empty allocated destination buffer of len clen
  const unsigned char *n,                           // 8byte nonce
  const unsigned char *k                            // 32byte key
) */
int crypto_stream_salsa20(unsigned char *,unsigned long long,const unsigned char *,const unsigned char *);

/* int crypto_stream_salsa20_xor(                   // encrypt a message under a salsa20 keystream
        unsigned char *c,                           // empty allocated destination buffer of len mlen
  const unsigned char *m,unsigned long long mlen,   // the message and its length
  const unsigned char *n,                           // 8byte nonce
  const unsigned char *k                            // 32byte key
) */
int crypto_stream_salsa20_xor(unsigned char *,const unsigned char *,unsigned long long,const unsigned char *,const unsigned char *);


/* int crypto_stream_xsalsa20(                      // generate the xsalsa20 keystream
        unsigned char *c,unsigned long long clen,   // empty allocated destination buffer of len clen
  const unsigned char *n,                           // 24byte nonce
  const unsigned char *k                            // 32byte key
) */
int crypto_stream_xsalsa20(unsigned char *,unsigned long long,const unsigned char *,const unsigned char *);

/* int crypto_stream_xsalsa20_xor(                  // encrypt a message under a xsalsa20 keystream
        unsigned char *c,                           // empty allocated destination buffer of len mlen
  const unsigned char *m,unsigned long long mlen,   // the message and its length
  const unsigned char *n,                           // 24byte nonce
  const unsigned char *k                            // 32byte key
) */
int crypto_stream_xsalsa20_xor(unsigned char *,const unsigned char *,unsigned long long,const unsigned char *,const unsigned char *);
