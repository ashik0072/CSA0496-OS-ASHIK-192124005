#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 4096
#define NUM_BLOCKS 1000

struct Block {
    int data[BLOCK_SIZE];
    int next;
};

struct File {
    int first;
    int last;
};

struct Disk {
    struct Block blocks[NUM_BLOCKS];
    struct File files[100];
    int freeList;
};

struct Disk disk;

void init() {
    int i;

    // Initialize all blocks to be free
    for (i = 0; i < NUM_BLOCKS - 1; i++) {
        disk.blocks[i].next = i + 1;
    }
    disk.blocks[NUM_BLOCKS - 1].next = -1;

    disk.freeList = 0;
}

int allocateBlock() {
    int blockNum;

    if (disk.freeList == -1) {
        printf("Error: out of disk space\n");
        return -1;
    }

    blockNum = disk.freeList;
    disk.freeList = disk.blocks[blockNum].next;

    return blockNum;
}

void freeBlock(int blockNum) {
    disk.blocks[blockNum].next = disk.freeList;
    disk.freeList = blockNum;
}

int createFile() {
    int i;

    for (i = 0; i < 100; i++) {
        if (disk.files[i].first == -1) {
            disk.files[i].first = allocateBlock();
            disk.files[i].last = disk.files[i].first;
            return i;
        }
    }

    printf("Error: no more file slots available\n");
    return -1;
}

void deleteFile(int fileNum) {
    int nextBlock, currentBlock;

    currentBlock = disk.files[fileNum].first;
    while (currentBlock != -1) {
        nextBlock = disk.blocks[currentBlock].next;
        freeBlock(currentBlock);
        currentBlock = nextBlock;
    }

    disk.files[fileNum].first = -1;
    disk.files[fileNum].last = -1;
}

void writeFile(int fileNum, int data) {
    int blockNum;

    blockNum = allocateBlock();
    disk.blocks[disk.files[fileNum].last].next = blockNum;
    disk.files[fileNum].last = blockNum;
    disk.blocks[blockNum].data[0] = data;
}

int main() {
    init();

    int fileNum = createFile();
    if (fileNum == -1) {
        return 1;
    }

    writeFile(fileNum, 42);
    writeFile(fileNum, 27);
    writeFile(fileNum, 15);

    deleteFile(fileNum);

    return 0;
}
