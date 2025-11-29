#include "../include/archiver.h"
#include "../include/files.h"
#include "../include/header.h"
#include "../include/data.h"
#include "../util/common.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void append_file_to_archive(char *file, FILE *output) {
  write_header(file, output);
  write_data(file, output);
}

char *archive_files(char **argv) {
  short file_type = 2;
  file_type = check_if_exist(argv[2]);
  if (file_type == -1) {
    fprintf(stderr, "ERROR: %s not exist.\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  char *output = "output.47a";
  if (argv[2]) output = add_extension(argv[2], ".47a");

  FILE *archive_output_file;
  archive_output_file = fopen(output, "wb");

  if (!archive_output_file) {
    fprintf(stderr, "ERROR: failed to open and write archive file.\n");
    exit(EXIT_FAILURE);
  }

  if (!file_type) append_file_to_archive(argv[2], archive_output_file);
  else fprintf(stdout, "coming soon...");

  return output;
}
