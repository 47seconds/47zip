#include "include/files.h"
#include "include/archiver.h"
#include "include/zipper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc == 1) {
    fprintf(stderr, "ERROR: use 47zip --help for usage\n");
    return EXIT_FAILURE;
  } else if (argc == 2 && !strcmp(argv[1], "--help")) {
    fprintf(stdout, "usage: 47zip <option> <file/directory> <(optional) output>\n");
    fprintf(stdout, "option:\n");
    fprintf(stdout, "\tarchive: archives the directory/file into one file with <output>.47a (<filename>.47a if output not parsed)\n");
    fprintf(stdout, "\tzip: zips directory/file into a compressed archive with <output>.47z (<filename>.47z if output not parsed)\n)");
    return EXIT_SUCCESS;
  } else if (argc == 2 && strcmp(argv[1], "archive") && strcmp(argv[1], "--help")) {
    fprintf(stderr, "ERROR: unknown option input.\n");
    return EXIT_FAILURE;
  } else if (argc == 2 && !(strcmp(argv[1], "archive") && strcmp(argv[1], "--help"))) {
    fprintf(stderr, "ERROR: filepath missing for %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  if (!check_if_exist(argv[2])) {
    fprintf(stderr, "ERROR: %s not exist.\n", argv[2]);
  }

  char *output_file = archive_files(argv);
  if (!strcmp(argv[1], "zip")) output_file = zip_compress(output_file);

  fprintf(stdout, "Operation performed successfully!\n");
  fprintf(stdout, "output: %s\n", output_file);

  return EXIT_SUCCESS;
}
