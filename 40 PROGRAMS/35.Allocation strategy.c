#include <stdio.h>
#include <string.h>
#define MAX_FILES 10
#define BLOCK_SIZE 512

struct File {
    char name[100]; 
    int size; 
    int blocks; 
    int index_block[MAX_FILES]; 
};


struct File files[MAX_FILES];
int num_files = 0; 

void add_file(char *name, int size) {
    if (num_files == MAX_FILES) {
        printf("Error: maximum number of files reached\n");
        return;
    }

    int blocks = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) {
        blocks++;
    }

    int available_blocks = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].index_block[i] == 0) {
            available_blocks++;
        }
    }
    if (available_blocks < blocks) {
        printf("Error: not enough available blocks\n");
        return;
    }

 
    int file_index = num_files;
    strcpy(files[file_index].name, name);
    files[file_index].size = size;
    files[file_index].blocks = blocks;
    int block_index = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].index_block[i] == 0) {
            files[file_index].index_block[block_index] = i;
            block_index++;
            if (block_index == blocks) {
                break;
            }
        }
    }
    num_files++;
    printf("File %s added to file system\n", name);
}


void read_file(char *name) {
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Error: file not found\n");
        return;
    }

    printf("File %s:\n", name);
    for (int i = 0; i < files[file_index].blocks; i++) {
        int block_index = files[file_index].index_block[i];
       
    }
}
