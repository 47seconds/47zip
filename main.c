#include "include/files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "ERROR: use 47zip --help for usage\n");
    return EXIT_FAILURE;
  } else if (argc == 2 && !strcmp(argv[1], "--help")) {
    fprintf(stdout, "usage: 47zip <option> <file/directory> <(optional) output>\n");
    fprintf(stdout, "option:\n");
    fprintf(stdout, "\tarchive: archives the directory/file into one file with <output>.47a (<filename>.47a if output not parsed)\n");
    return EXIT_SUCCESS;
  } else if (argc == 2 && strcmp(argv[1], "archive") && strcmp(argv[1], "--help")) {
    fprintf(stderr, "ERROR: unknown option input.\n");
    return EXIT_FAILURE;
  } else if (argc == 2 && !(strcmp(argv[1], "archive") && strcmp(argv[1], "--help"))) {
    fprintf(stderr, "ERROR: filepath missing for %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  printf("Operations!\n");
  if (!check_if_exist(argv[2])) {
    fprintf(stderr, "ERROR: $s not exist.\n");
  }

  return EXIT_SUCCESS;
}
