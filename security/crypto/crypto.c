
#include "crypto.h"

void rc4_makey(unsigned char *key, int keylength)   
{
    long i = 0;
    //由于RC4算法加密是采用的xor，所以，一旦子密钥序列出现了重复，
    //密文就有可能被破解。RC4算法生成的子密钥序列是否会出现重复呢
    //经过我的测试，存在部分弱密钥，使得子密钥序列在不到100万字节
    //内就发生了完全的重复，如果是部分重复，则可能在不到10万字节
    //内就能发生重复，因此，推荐在使用RC4算法时，必须对加密密钥进
    //行测试，判断其是否为弱密钥。

    //有办法让他不重复。但是也觉得没有必要   
    //srand(GetTickCount());   
    //生成密钥   
    for (i = 0; i < keylength; i++)   
    {
        //try
        {
            key[i] = GetTickCount()%256; //rand()%256;//怕数组越界
        }   
        // catch (...)
        {
         //   break;
        }
    }
}

void rc4_key( RC4_KEYSTRUCT *s, unsigned char *key,  int length )
{
    int i, j, k, *m, a;
    s->x = 0;
    s->y = 0;
    m = s->m;

    for( i = 0; i < 256; i++ )
    {
        m[i] = i;
    }

    j = k = 0;

    for( i = 0; i < 256; i++ )
    {
        a = m[i];
        j = (unsigned char) ( j + a + key[k] );
        m[i] = m[j];
        m[j] = a;
        if( ++k >= length )
            k = 0;
    }
}

void rc4( RC4_KEYSTRUCT *s, unsigned char *data, int length )
{
    int i, x, y, *m, a, b;
    x = s->x;
    y = s->y;
    m = s->m;

    for( i = 0; i < length; i++ )
    {
        x = (unsigned char)( x + 1 );
        a = m[x];
        y = (unsigned char)( y + a );
        m[x] = b = m[y];
        m[y] = a;
        data[i] ^= m[(unsigned char) ( a + b )];
    }

    s->x = x;
    s->y = y;
}  