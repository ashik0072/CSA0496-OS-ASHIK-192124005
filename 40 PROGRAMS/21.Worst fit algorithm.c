#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100
#define MAX_MEMORY 1000

int memory[MAX_MEMORY];
int blocks[MAX_BLOCKS];
int block_size[MAX_BLOCKS];

void init_memory() {
    int i;
    for (i = 0; i < MAX_MEMORY; i++) {
        memory[i] = -1;
    }
}

void init_blocks() {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        blocks[i] = -1;
        block_size[i] = -1;
    }
}

void display_memory() {
    int i;
    for (i = 0; i < MAX_MEMORY; i++) {
        printf("%d ", memory[i]);
    }
    printf("\n");
}

void worst_fit(int process_size) {
    int i, j, k, max_block = -1, max_block_size = -1;
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (blocks[i] == -1) {
            if (block_size[i] > max_block_size && block_size[i] >= process_size) {
                max_block = i;
                max_block_size = block_size[i];
            }
        }
    }
    if (max_block != -1) {
        j = blocks[max_block];
        for (k = 0; k < process_size; k++) {
            memory[j++] = 1;
        }
        block_size[max_block] -= process_size;
    } else {
        printf("Error: Not enough memory\n");
    }
}

int main() {
    int i, n, process_size;
    init_memory();
    init_blocks();
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    printf("Enter size of each block: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &block_size[i]);
    }
    for (i = 0; i < n; i++) {
        blocks[i] = i;
        for (j = 0; j < block_size[i]; j++) {
            memory[j] = 0;
        }
    }
    printf("Enter process size: ");
    scanf("%d", &process_size);
    worst_fit(process_size);
    display_memory();
    return 0;
}
