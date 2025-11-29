#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>
#include <stdio.h>

extern const uint8_t HEADER_SIZE;

void write_header(char *output, FILE *file);

#endif 
