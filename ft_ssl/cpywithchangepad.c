#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
// #include <swapByteOrder.h>

#define F fg.f
#define G fg.g
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

typedef struct s_r
{
    uint32_t f;
    uint32_t g;
}t_r;

t_r f(uint32_t b, uint32_t c, uint32_t d, size_t i)
{
    return (t_r){(b & c) | (~b & d), i};
}

t_r g(uint32_t b, uint32_t c, uint32_t d, size_t i)
{
    return (t_r){(b & d) | (c & ~d), ((5 * i + 1) % 16)};
}

t_r h(uint32_t b, uint32_t c, uint32_t d, size_t i)
{
    return (t_r){(b ^ c ^ d), ((3 * i + 5) % 16)};
}

t_r i(uint32_t b, uint32_t c, uint32_t d, size_t i)
{
    return (t_r){(c ^ (b | ~d)), ((7 * i) % 16)};
}

/**
 * Normalement, c'est impossible d'avoir un nombre impair de bit dans un message
 */

// typedef t_r (*rounds)( int );

/**
 * ATTENTION PROBABLEMENT UN SOUCIS AVEC LA TAILLE DU TABLEAU
 */

t_r (*rounds[64])(uint32_t, uint32_t, uint32_t, size_t) = 
{
    f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, 
    g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, 
    h, h, h, h, h, h, h, h, h, h, h, h, h, h, h, h, 
    i, i, i, i, i, i, i, i, i, i, i, i, i, i, i, i
};


uint32_t k[] = 
{
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

uint32_t s[] = 
{
    7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
    5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
    4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
    6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
};





// typedef struct md5_chunk
// {
//     char *message;
//     uint32_t *padding;
// }

// [<---------->]

void printBinary(void *arr, int len)
{
    char sp[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'};
    int i;
    char *ar = arr;
    for(int j = 0; j < len; ar++)
    {
        /* perform bitwise AND for every bit of the character */
        for(i = 7; i >= 0; --i) 
            (*ar & 1 << i) ? putchar('1') : putchar('0');

        putchar(sp[j % 11]);
        j++;
    }
}


/**
 * Faire attention au /0 dans le message ??
 */

/**
 * In BIT
 */
int padding_size(int messageSize)
{
    return (448 - ((messageSize + 64) % 512)) + 64;
}

int inBits(int toBits)
{
    return toBits * 8;
}

int inBytes(int toBits)
{
    return toBits / 8;
}


void uint64_to_char_buffer(uint64_t number, uint8_t* buffer)
{
    buffer[0] = (uint8_t) ((number >> 56) & 0xff);
    buffer[1] = (uint8_t) ((number >> 48) & 0xff);
    buffer[2] = (uint8_t) ((number >> 40) & 0xff);
    buffer[3] = (uint8_t) ((number >> 32) & 0xff);
    buffer[4] = (uint8_t) ((number >> 24) & 0xff);
    buffer[5] = (uint8_t) ((number >> 16) & 0xff);
    buffer[6] = (uint8_t) ((number >> 8) & 0xff);
    buffer[7] = (uint8_t) ((number >> 0) & 0xff);
}

typedef struct s_md5 
{
    u_int8_t *message;
    size_t len;
}           t_md5;


// typedef struct s_chunk
// {
//     u_int8_t chunk[64];
// }           t_chunk;

// typedef struct s_sub_block
// {
//     u_int32_t chunk[16];
// }  t_sub_block;

// t_md5 pad_message(char *message)
// {
//     size_t messageSizeInBytes = strlen(message);
//     uint8_t originalSize[8];
//     unsigned int paddingInBits = padding_size(inBits(messageSizeInBytes));
//     unsigned int padded_size = inBytes(paddingInBits) + messageSizeInBytes + 8;


//     uint64_to_char_buffer(inBits(messageSizeInBytes), originalSize);
    
//     #ifdef DEBUG
//     printf("The message contains %d bits. The message will be padded to make it 448 mod 512 bits long. Since your message is %d bits we will add: %d\n", inBits(messageSizeInBytes), inBits(messageSizeInBytes), paddingInBits);
//     #endif
    
//     uint8_t *paddedMessage = malloc(padded_size);
    
//     #ifdef DEBUG
//     printf("The paddedsize is: %d\n", padded_size * 8 - 64);
//     #endif

//     memset(paddedMessage, 0, padded_size);
//     memcpy(paddedMessage, message, padded_size);
//     memcpy(paddedMessage + (padded_size - 8), originalSize, 8);

//     paddedMessage[messageSizeInBytes] = (char)(1 << 7);
    
//     #ifdef DEBUG
//     printBinary(paddedMessage, padded_size);
//     #endif

//     return ((t_md5){paddedMessage, padded_size * 8});
// }


void md5(u_int8_t *msg, size_t len)
{
    u_int32_t wordBuffer[4] = {0};
    u_int32_t f_compute;
    uint32_t *chunk;
    t_r fg;
    // t_chunk *chunk;
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xefcdab89;
    uint32_t h2 = 0x98badcfe;
    uint32_t h3 = 0x10325476;

    for (size_t offset = 0; offset < len; offset += 64)
    {
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        chunk = (uint32_t *) (msg + offset);
        for (size_t i = 0; i < 63; i++)
        {
            fg = rounds[i](b, c, d, i);
            f_compute = F + a + k[i] + chunk[G];
            a = d;
            d = c;
            c = b;
            b += LEFTROTATE(F, s[i]);
        }
        printf("%x\n%x\n%x\n%x\n\n", a, b, c, d);
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }
    uint8_t *p;
    p=(uint8_t *)&h0;
    printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
 
    p=(uint8_t *)&h1;
    printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
 
    p=(uint8_t *)&h2;
    printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
 
    p=(uint8_t *)&h3;
    printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    // printf("%x\n%x\n%x\n%x\n\n", A0, B0, C0, D0);
     
    
}

int main(int argc, char **argv)
{
    // int nb = atoi(argv[1]);
    // static char p[] = (char []){"lol5"};
    // printf("%zu\n", sizeof(p));
    // printf("%zu\n", strlen(argv[1]));
    // printf("%d\n", padding_size(strlen("123") * 8));

    // char *tamer = (char []){'a', '\0'};
    // printBinary(tamer);
    // t_md5 ctx = pad_message("The quick brown fox jumps over the lazy dog.");
    #ifdef DEBUG
    printf("\n %zu padded length || Chunk count : %d", ctx.len, ctx.len / 512);
    #endif
    size_t initial_len = strlen(argv[1]);
    uint8_t *msg = NULL;  
    int new_len = ((((initial_len + 8) / 64) + 1) * 64) - 8;
 
    msg = calloc(new_len + 64, 1); // also appends "0" bits 
                                   // (we alloc also 64 extra bytes...)
    memcpy(msg, argv[1], initial_len);
    msg[initial_len] = 128; // write the "1" bit
 
    uint32_t bits_len = 8*initial_len; // note, we append the len
    memcpy(msg + new_len, &bits_len, 4);           // in bits at the end of the buffer

    md5(msg, new_len);
    
}
