#include "../include/files.h"
#include <stdio.h>

int check_if_exist(char *file_path) {
  fprintf(stdout, "found: %s\n", file_path);
  return 1;
}
