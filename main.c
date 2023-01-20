#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#import "fishhook.h"

static int (*original_stat)(const char *restrict path, struct stat *restrict buf);

static int my_stat(const char *restrict path, struct stat *restrict buf) {
  printf("Intecepted the stat call\n");
  printf("Checking for path: %s\n", path);
  return original_stat(path, buf);
}



int main(int argc, char *argv[]) {
    rebind_symbols((struct rebinding[1]){{"stat", my_stat, (void *)&original_stat}}, 1);
    struct stat sb;
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &sb) == 0) {
        printf("File %s exists\n", argv[1]);
    } else {
        printf("File %s does not exist\n", argv[1]);
    }

    return 0;
}
