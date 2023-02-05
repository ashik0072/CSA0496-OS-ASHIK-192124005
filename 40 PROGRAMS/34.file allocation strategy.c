#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_RECORDS_PER_FILE 100

struct File {
    int num_records;
    char records[MAX_RECORDS_PER_FILE][256];
};

struct FileSystem {
    int num_files;
    struct File files[MAX_FILES];
};

void init_file_system(struct FileSystem *fs) {
    fs->num_files = 0;
}

int create_file(struct FileSystem *fs, char records[][256], int num_records) {
    if (fs->num_files == MAX_FILES) {
        printf("Error: Cannot create more files.\n");
        return -1;
    }

    int file_id = fs->num_files++;
    struct File *file = &fs->files[file_id];
    file->num_records = num_records;

    for (int i = 0; i < num_records; i++) {
        strcpy(file->records[i], records[i]);
    }

    return file_id;
}

void read_file(struct FileSystem *fs, int file_id) {
    if (file_id < 0 || file_id >= fs->num_files) {
        printf("Error: Invalid file id.\n");
        return;
    }

    struct File *file = &fs->files[file_id];
    for (int i = 0; i < file->num_records; i++) {
        printf("Record %d: %s\n", i + 1, file->records[i]);
    }
}

int main() {
    struct FileSystem fs;
    init_file_system(&fs);

    char records[3][256] = {
        "Record 1",
        "Record 2",
        "Record 3"
    };

    int file_id = create_file(&fs, records, 3);
    printf("File created with id: %d\n", file_id);

    read_file(&fs, file_id);

    return 0;
}
