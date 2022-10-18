#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void) {
    //const char *path = "./my_dir/my_sub_dir";
    const char *path = "./my_dir";
    mode_t mode = S_IRUSR | S_IWUSR | S_IXUSR;
    int result = mkdir(path, mode);
    if (result == -1) {
        perror("mkdir");
        return -1;
    }
    const char *path2 = "my_renamed_dir";
    result = rename(path, path2);
    if (result == -1) {
        perror("rename");
        return -1;
    }
    result = remove(path2);
    if (result == -1) {
        perror("remove");
        return -1;
    }
    return 0;
}
