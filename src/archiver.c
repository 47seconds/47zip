#include "../include/archiver.h"
#include "../util/common.h"

char *archive_files(char **argv) {
  char *output = "output.47a";
  if (argv[2]) output = add_extension(argv[2], ".47a");

  return output;
}
