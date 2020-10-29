#ifndef MD5_H
#define MD5_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


typedef struct s_r
{
    uint32_t f;
    uint32_t g;
}t_r;

typedef struct s_md5 
{
    u_int8_t *message;
    size_t len;
}           t_md5;

t_r f(uint32_t b, uint32_t c, uint32_t d, uint32_t i);
t_r g(uint32_t b, uint32_t c, uint32_t d, uint32_t i);
t_r h(uint32_t b, uint32_t c, uint32_t d, uint32_t i);
t_r i(uint32_t b, uint32_t c, uint32_t d, uint32_t i);
u_int64_t padding_size(size_t messageSize);
t_md5 pad_message(char *message);
// int inBits(int toBits);
// int inBytes(int toBits);

#define F fg.f
#define G fg.g
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

extern t_r (*rounds[64])(uint32_t, uint32_t, uint32_t, uint32_t);
extern uint32_t s[];
extern uint32_t k[];

#endif
