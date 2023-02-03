#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int priority;
    int burst_time;
} Process;

void schedule(Process processes[], int num_processes) {
    int i, j, highest_priority_index;
    Process temp;

    // Sort processes by priority
    for (i = 0; i < num_processes - 1; i++) {
        highest_priority_index = i;
        for (j = i + 1; j < num_processes; j++) {
            if (processes[j].priority > processes[highest_priority_index].priority) {
                highest_priority_index = j;
            }
        }
        temp = processes[i];
        processes[i] = processes[highest_priority_index];
        processes[highest_priority_index] = temp;
    }

    // Execute processes
    for (i = 0; i < num_processes; i++) {
        printf("Executing process %d with priority %d and burst time %d\n", 
                processes[i].id, processes[i].priority, processes[i].burst_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES] = {
        {1, 2, 10},
        {2, 3, 5},
        {3, 1, 8},
        {4, 4, 7},
        {5, 5, 2}
    };
    int num_processes = 5;
    schedule(processes, num_processes);
    return 0;
}
