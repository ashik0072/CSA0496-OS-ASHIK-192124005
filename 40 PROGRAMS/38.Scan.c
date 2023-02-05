#include <stdio.h>

#define MAX_SIZE 50

void scan(int arr[], int size, int head) {
    int temp[MAX_SIZE], i, j = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] >= head) {
            temp[j] = arr[i];
            j++;
        }
    }
    for (i = 0; i < size; i++) {
        if (arr[i] < head) {
            temp[j] = arr[i];
            j++;
        }
    }

    int total_movement = abs(temp[0] - head);
    for (i = 1; i < size; i++) {
        total_movement += abs(temp[i] - temp[i-1]);
    }

    printf("Order of access: ");
    for (i = 0; i < size; i++) {
        printf("%d ", temp[i]);
    }
    printf("\nTotal head movement: %d\n", total_movement);
}

int main() {
    int arr[MAX_SIZE], size, head;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    printf("Enter the queue: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    scan(arr, size, head);
    return 0;
}
