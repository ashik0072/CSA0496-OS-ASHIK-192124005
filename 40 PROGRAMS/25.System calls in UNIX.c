#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int fd;
    struct stat sb;
    DIR *dir;
    struct dirent *ent;

    if ((fd = open("file.txt", O_RDONLY)) == -1) {
        perror("open");
        return 1;
    }
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl F_GETFL");
        return 1;
    }
    flags |= O_APPEND;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        perror("fcntl F_SETFL");
        return 1;
    }
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    if ((fd = open("file.txt", O_RDONLY)) == -1) {
        perror("open");
        return 1;
    }
    off_t offset = lseek(fd, 10, SEEK_SET);
    if (offset == -1) {
        perror("lseek");
        return 1;
    }
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    if (stat("file.txt", &sb) == -1) {
        perror("stat");
        return 1;
    }
    printf("File size: %ld bytes\n", sb.st_size);

    if ((dir = opendir("/path/to/directory")) == NULL) {
        perror("opendir");
        return 1;
    }
    while ((ent = readdir(dir)) != NULL) {
        printf("%s\n", ent->d_name);
    }
    if (closedir(dir) == -1) {
        perror("closedir");
        return 1;
    }

    return 0;
}
