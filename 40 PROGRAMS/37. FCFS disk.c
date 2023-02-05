#include <stdio.h>

#define MAX_REQUESTS 20

int main() {
    int requests[MAX_REQUESTS];
    int num_requests;
    int head, total_distance = 0;
    int i;

    printf("Enter the number of disk requests: ");
    scanf("%d", &num_requests);

    printf("Enter the disk requests:\n");
    for(i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    for(i = 0; i < num_requests; i++) {
        total_distance += abs(head - requests[i]);
        head = requests[i];
    }

    printf("Total distance: %d\n", total_distance);

    return 0;
}
