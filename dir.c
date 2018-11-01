#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  DIR * d = opendir("directory");
  struct stat *s = malloc(sizeof(struct stat));
  stat("directory", s);

  printf("Statistics for directory: \n");
  printf("Directory size: %ld Bytes\n", s->st_size);
  struct dirent *entry = readdir(d);
  printf("Directories: \n");
  while (entry) {
    if (entry->d_type == DT_DIR) printf("%s\n", entry->d_name);
    entry = readdir(d);
  }
  closedir(d);
  d = opendir("directory");

  printf("Files: \n");
  while (entry) {
    if (entry->d_type == DT_REG) printf("%s\n", entry->d_name);
    entry = readdir(d);
  }
  closedir(d);
  return 0;
}
