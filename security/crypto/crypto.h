#ifndef _CRYPTO_
#define _CRYPTO_

#ifdef __cplusplus
extern "C" {
#endif

/*
This file merges the header files md2.h md5.h and rc4.h
See those files for disclaimers.
*/

/*----------------------------------------------------------------------------
MD5 -- from md5.h
----------------------------------------------------------------------------*/
/*added cuz had problems compiling*/
typedef unsigned long ULONG;

/* Data structure for MD5 (Message-Digest) computation */
typedef struct {
  ULONG i[2];                          /* number of _bits_ handled mod 2^64 */
  ULONG buf[4];                                           /* scratch buffer */
  unsigned char in[64];                                     /* input buffer */
  unsigned char digest[16];            /* actual digest after MD5Final call */
} MD5_CTX;

#define MD5_LEN 16

static void MD5Init(MD5_CTX * pThis)
{
    return;
}
static void MD5Update(MD5_CTX * pThis, unsigned char * Data, unsigned int Len)
{
    return;
}

static void MD5Final(MD5_CTX * pThis)
{
    return;
}

/*----------------------------------------------------------------------------
MD2 -- from md2.h
----------------------------------------------------------------------------*/
/* Data structure for MD2 (Message Digest) computation */
typedef struct {
  /* buffer for forming md into.  Actual digest is buf[0]...buf[15] */
  unsigned char buf[48];
  unsigned char mac[16];                                    /* mac register */
  unsigned char i;                    /* number of bytes handled, modulo 16 */
  unsigned char lastMac;                            /* last mac value saved */
} MD2_CTX;

#define MD2_LEN 16

static void MD2Init(MD2_CTX * pThis)
{
    return;
}
static void MD2Update(MD2_CTX * pThis, unsigned char * Data, unsigned int Len)
{
    return;
}

static void MD2Final(MD2_CTX * pThis)
{
    return;
}



/*----------------------------------------------------------------------------
RC4 -- from rc4.h
----------------------------------------------------------------------------*/
/* Key structure */
typedef struct _RC4_KEYSTRUCT{
//   unsigned char m[256];		/* State table */
//   unsigned char i,j;		/* Indices */

  int x, y, m[256]; 

} RC4_KEYSTRUCT;

void rc4_key(RC4_KEYSTRUCT *, int, unsigned char*);
void rc4    (RC4_KEYSTRUCT *, int, unsigned char*);


#ifdef __cplusplus
}
#endif

#endif
/*CRYPTO_*/



