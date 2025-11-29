#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>
#include <stdio.h>

extern const uint8_t HEADER_SIZE;

// https://www.gnu.org/software/tar/manual/html_node/Standard.html
typedef struct {
  char name[100];       // File path/name (null-terminated)
  char mode[8];         // File permissions (ASCII octal: "0000755")
  char uid[8];          // Owner user ID (ASCII octal)
  char gid[8];          // Owner group ID (ASCII octal)
  char size[12];        // File size in bytes (ASCII octal)
  char mtime[12];       // Modification time (UNIX timestamp in ASCII octal)
  char checksum[8];     // Header checksum (ASCII octal), spaces while calculating
  char typeflag;  ;     // File type ('0' = file, '5' = directory, etc.)
  char linkname[100];   // For symbolic links (path to target)
  char magic[6];        // Format identifier "ustar\0"
  char version[2];      // Usually "00"
  char uname[32];       // Owner username
  char gname[32];       // Owner group name
  char devmajor[8];     // Device major number (for special files)
  char devminor[8];     // Device minor number
  char prefix[155];     // If filename > 100 chars, store leading path here
  char padding[12];     // Unused, must be zero
} HEADER;

void write_header(char *output, FILE *file);

#endif 
