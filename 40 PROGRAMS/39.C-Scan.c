#include <stdio.h>

#define MAX_REQUESTS 200

void c_scan(int requests[], int num_requests, int head) {
    int seek_time = 0;
    int diff;
    int i, j;
    int temp[MAX_REQUESTS];

    for (i = 0; i < num_requests; i++) {
        temp[i] = requests[i];
    }

    for (i = 0; i < num_requests - 1; i++) {
        for (j = i + 1; j < num_requests; j++) {
            if (temp[i] > temp[j]) {
                int temp_val = temp[i];
                temp[i] = temp[j];
                temp[j] = temp_val;
            }
        }
    }

    for (i = 0; i < num_requests; i++) {
        if (temp[i] == head) {
            break;
        }
    }

    for (j = i; j < num_requests; j++) {
        diff = temp[j] - head;
        seek_time += diff;
        head = temp[j];
    }

    for (j = 0; j < i; j++) {
        diff = temp[j] - head;
        seek_time += diff;
        head = temp[j];
    }

    printf("Total seek time: %d\n", seek_time);
}

int main() {
    int requests[MAX_REQUESTS];
    int num_requests;
    int head;

    printf("Enter the number of requests: ");
    scanf("%d", &num_requests);

    printf("Enter the requests (in cylinders): ");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    c_scan(requests, num_requests, head);

    return 0;
}
