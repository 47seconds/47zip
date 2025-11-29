#include "common.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned int NAME_BUFFER_SIZE = 256;

char *concat_2_char_ptr(char *s1, char *s2, uint32_t size) {
  const uint32_t total_size = strlen(s1) + strlen(s2);
  size = size >= total_size ? total_size : size;
  
  char *output = malloc(size * sizeof(char));
  if (!output) {
    fprintf(stderr, "ERROR: failed to allocate space for adding 2 names string.");
    return NULL;
  }

  strcpy(output, s1);
  strcat(output, s2);

  return output;
}

// one bug: if filename near 256 and .47a already there, then final name could be glichy like abc..z.47.47z
char *add_extension(char *str, char* ext) {
  const uint32_t total_size = strlen(str) + strlen(ext);
  uint32_t size = total_size >= NAME_BUFFER_SIZE ? (uint32_t)NAME_BUFFER_SIZE : total_size;

  char *output = malloc(size * sizeof(char));
  if (!output) {
    fprintf(stderr, "ERROR: failed to allocate space for adding extension string.");
    return NULL;
  }


  strcpy(output, str);
  strcat(output, ext);  

  return output;
}
