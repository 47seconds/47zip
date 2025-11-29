#ifndef FILES_H
#define FILES_H

#include <sys/stat.h>

int check_if_exist(char *file_path);
struct stat get_file_metadata(char *file_path);

#endif
