#include <stdio.h>

struct Process {
    int id;           
    int burst_time;   
    int remaining_time; 
};


void roundRobin(struct Process* processes, int n, int time_quantum) {
    int remaining_processes = n;
    int current_time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                int execute_time = (processes[i].remaining_time < time_quantum) ? processes[i].remaining_time : time_quantum;
                processes[i].remaining_time -= execute_time;
                current_time += execute_time;
                printf("P[%d] executes for %d units at time %d\n", processes[i].id, execute_time, current_time);

                if (processes[i].remaining_time == 0) {
                    remaining_processes--;
                }
            }
        }
    }
}

int main() {
    int n, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for p[%d]: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Round Robin Scheduling:\n");
    roundRobin(processes, n, time_quantum);

    return 0;
}
