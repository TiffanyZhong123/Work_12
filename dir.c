#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char * argv[]) {
  char str[256];
  if (argc == 1) {
    printf("Please name a directory: ");
    fgets(str, 256, stdin);
    str[strlen(str)-1] = 0;
  }
  else strcpy(str, argv[1]);
  DIR *d = opendir(str);
  struct stat *s = malloc(sizeof(struct stat));
  stat(str, s);

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
  entry = readdir(d);
  printf("Files: \n");
  while (entry) {
    if (entry->d_type == DT_REG) printf("%s\n", entry->d_name);
    entry = readdir(d);
  }
  closedir(d);
  return 0;
}
