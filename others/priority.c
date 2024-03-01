#include <stdio.h>

struct Process {
    int id;
    int priority;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}


void priorityScheduling(struct Process* processes, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority < processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    printf("Process\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", processes[i].id, processes[i].priority);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i+1 ;
        printf("Enter the priority for Process[%d]: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    priorityScheduling(processes, n);

    return 0;
}
