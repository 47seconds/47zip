#include "include/files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("command: 47zip --help for help and usage\n");
    return EXIT_FAILURE;
  } else if (argc > 1 && !strcmp(argv[1], "--help")) {
    printf("usage: 47zip <option> <file/directory> <(optional) output>\n");
    printf("option:\n");
    printf("\tarchive: archives the directory/file into one file with <output>.47a (<filename>.47a if output not parsed)\n");
    return EXIT_SUCCESS;
  }

  printf("Operations!\n");

  return EXIT_SUCCESS;
}
