#include "../include/zipper.h"
#include "../util/common.h"

char *zip_compress(char *archived_file) {
  char *output = add_extension(archived_file, ".47z");

  return output;
}
