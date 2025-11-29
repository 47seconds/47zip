#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
extern const unsigned int NAME_BUFFER_SIZE;

char *concat_2_char_ptr(char *s1, char *s2, uint32_t size);
char *add_extension(char *str, char* ext);

#endif
