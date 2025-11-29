#include "../include/files.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

struct stat get_file_metadata(char *file_path) {
  struct stat st;

  if (stat(file_path, &st)) {
    fprintf(stdout, "ERROR: file or directory %s doesn't exist.\n", file_path);
    exit(EXIT_FAILURE);
  }

  return st;
}

int check_if_exist(char *file_path) {
  struct stat st;
 
  if (stat(file_path, &st)) {
    fprintf(stdout, "ERROR: file or directory %s doesn't exist.\n", file_path);
    exit(EXIT_FAILURE);
  }

  uint8_t type = 2;  // other type
  if (S_ISDIR(st.st_mode)) type = 1;  // directory
  else if (S_ISREG(st.st_mode)) type = 0;  // file
  
  char *return_type = "other";
  if (!type) return_type = "file";
  else if (type == 1) return_type = "directory";

  fprintf(stdout, "%s exists!\n", file_path);
  fprintf(stdout, "type: %s\n", return_type);
  return 1;
}
