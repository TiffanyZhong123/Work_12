#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char * argv[]) {
  char str[256];
  if (argc == 1) {
    printf("Please name a directory: ");
    scanf("%s", str);
    printf("%s\n", str);
    int i = 0;
    while (str[i] != '\n') {
      i++;
    }
    str[i] = 0;
  }
  DIR * d = opendir(str);
  struct stat *s = malloc(sizeof(struct stat));
  stat(d, s);

  printf("Statistics for directory: \n");
  printf("Directory size: %ld Bytes\n", s->st_size);
  struct dirent *entry = readdir(d);
  printf("Directories: \n");
  while (entry) {
    if (entry->d_type == DT_DIR) printf("%s\n", entry->d_name);
    entry = readdir(d);
  }
  closedir(d);
  d = opendir(str);

  printf("Files: \n");
  while (entry) {
    if (entry->d_type == DT_REG) printf("%s\n", entry->d_name);
    entry = readdir(d);
  }
  closedir(d);
  return 0;
}
