#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

void error(char *fun_name) {
    printf("%s: error no %d\n", fun_name, errno);
    exit(-1);
}

int main() {
    const char *path = "./my_dir";
    mode_t mode = S_IRUSR | S_IWUSR | S_IXUSR;
    int result = mkdir(path, mode);
    if (result == -1) {
        error("mkdir");
    }
    const char *path2 = "my_renamed_dir";
    result = rename(path, path2);
    if (result == -1) {
        error("rename");
    }
    result = remove(path2);
    if (result == -1) {
        error("remove");
    }
}
