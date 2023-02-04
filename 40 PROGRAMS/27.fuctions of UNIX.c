#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void print_permissions(mode_t mode) {
    printf( (mode & S_IRUSR) ? "r" : "-");
    printf( (mode & S_IWUSR) ? "w" : "-");
    printf( (mode & S_IXUSR) ? "x" : "-");
    printf( (mode & S_IRGRP) ? "r" : "-");
    printf( (mode & S_IWGRP) ? "w" : "-");
    printf( (mode & S_IXGRP) ? "x" : "-");
    printf( (mode & S_IROTH) ? "r" : "-");
    printf( (mode & S_IWOTH) ? "w" : "-");
    printf( (mode & S_IXOTH) ? "x" : "-");
}

void print_file_details(char* path) {
    struct stat file_info;
    if (stat(path, &file_info) != 0) {
        printf("Error getting file information\n");
        return;
    }

    print_permissions(file_info.st_mode);
    printf(" %d", file_info.st_nlink);
    printf(" %s", getpwuid(file_info.st_uid)->pw_name);
    printf(" %s", getgrgid(file_info.st_gid)->gr_name);
    printf(" %d", file_info.st_size);
    printf(" %s", ctime(&file_info.st_mtime));
    printf(" %s\n", path);
}

int main(int argc, char* argv[]) {
    DIR* d;
    struct dirent* dir;
    char* path = ".";
    if (argc > 1) {
        path = argv[1];
    }
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.') {
                char new_path[255];
                strcpy(new_path, path);
                strcat(new_path, "/");
                strcat(new_path, dir->d_name);
                print_file_details(new_path);
            }
        }
        closedir(d);
    }
    return 0;
}
