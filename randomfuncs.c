#include "randomfuncs.h"

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define BUFF_SIZE 4

int err() {
  printf("\x1b[31m errno %d\x1b[0m\n", errno);
  printf("%s\n", strerror(errno));
  exit(1);
}

int random_random() {
  int r_file = open("/dev/random", O_RDONLY, 0);
  if (r_file == -1) err();
  int bytes;
  int read_result = read(r_file, &bytes, sizeof(bytes));
  if (read_result == - 1) err();
  return bytes;
}

int random_urandom() {
  int r_file = open("/dev/urandom", O_RDONLY, 0);
  if (r_file == -1) err();
  int bytes;
  int read_result = read(r_file, &bytes, sizeof(bytes));
  if (read_result == - 1) err();
  return bytes;
}