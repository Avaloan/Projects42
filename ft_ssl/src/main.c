#include "../md5.h"

t_r f(uint32_t b, uint32_t c, uint32_t d, uint32_t i)
{
    return (t_r){(b & c) | (~b & d), i};
}

t_r g(uint32_t b, uint32_t c, uint32_t d, uint32_t i)
{
    return (t_r){(b & d) | (c & ~d), ((5 * i + 1) % 16)};
}

t_r h(uint32_t b, uint32_t c, uint32_t d, uint32_t i)
{
    return (t_r){(b ^ c ^ d), ((3 * i + 5) % 16)};
}

t_r i(uint32_t b, uint32_t c, uint32_t d, uint32_t i)
{
    return (t_r){(c ^ (b | ~d)), ((7 * i) % 16)};
}



t_r (*rounds[64])(uint32_t, uint32_t, uint32_t, u_int32_t) = 
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

// void printBinary(void *arr, int len)
// {
//     char sp[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'};
//     int i;
//     char *ar = arr;
//     for(int j = 0; j < len; ar++)
//     {
//         /* perform bitwise AND for every bit of the character */
//         for(i = 7; i >= 0; --i) 
//             (*ar & 1 << i) ? putchar('1') : putchar('0');

//         putchar(sp[j % 11]);
//         j++;
//     }
// }


/**
 * Faire attention au /0 dans le message ??
 */

/**
 * In BIT
 */
u_int64_t padding_size(size_t messageSize)
{
    return (448 - ((messageSize + 64) % 512)) + 64;
}


t_md5 pad_message(char *message)
{
    size_t originalLength = strlen(message);
    u_int64_t paddingInBits = padding_size(originalLength * 8);
    u_int64_t padded_size = (paddingInBits / 8) + originalLength + 8;

    uint8_t *paddedMessage = calloc(padded_size, 1);
    
    memcpy(paddedMessage, message, originalLength);
    u_int64_t test = originalLength * 8;
    memcpy(paddedMessage + (padded_size - 8), &test, 8);

    paddedMessage[originalLength] = 128;

    return ((t_md5){paddedMessage, padded_size});
}


/**
 * Refacto les for loops
 * remettre le 4 wordBuffer
 * 
 * Sortir l'output
 * Done.
 */
void md5(u_int8_t *msg, size_t len)
{
    // u_int32_t wordBuffer[4] = {0};
    uint32_t *chunk;
    t_r fg;
    // t_chunk *chunk;
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xefcdab89;
    uint32_t h2 = 0x98badcfe;
    uint32_t h3 = 0x10325476;
    uint32_t i;

    // printf("???????????? new len %d\n", len);

    for (size_t offset = 0; offset < len; offset += 64)
    {
        // printf("INSIDE MAIN LOOP %d\n", offset);
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        chunk = (uint32_t *)(msg + offset);
        for (i = 0; i < 64; i++)
        {
            fg = rounds[i](b, c, d, i);
            uint32_t temp = d;
            d = c;
            c = b;
            b = b + LEFTROTATE((a + F + k[i] + chunk[G]), s[i]);
            a = temp;
        }
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
    (void)argc;
    // int nb = atoi(argv[1]);
    // static char p[] = (char []){"lol5"};
    // printf("%zu\n", sizeof(p));
    // printf("%zu\n", strlen(argv[1]));
    // printf("%d\n", padding_size(strlen("123") * 8));

    // char *tamer = (char []){'a', '\0'};
    // printBinary(tamer);
    t_md5 ctx = pad_message(argv[1]);
    #ifdef DEBUG
    printf("\n %zu padded length || Chunk count : %d", ctx.len, ctx.len / 512);
    #endif
    md5(ctx.message, ctx.len);
    
}
