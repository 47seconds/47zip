#include "../include/archiver.h"
#include "../include/files.h"
#include "../util/common.h"
#include <stdio.h>
#include <stdlib.h>

char *archive_files(char **argv) {
  if (check_if_exist(argv[2]) == -1) {
    fprintf(stderr, "ERROR: %s not exist.\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  char *output = "output.47a";
  if (argv[2]) output = add_extension(argv[2], ".47a");

  return output;
}
