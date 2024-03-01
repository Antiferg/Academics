#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Process {
    int id;            
    int arrival_time;  
    int burst_time;
    int remaining_time; 
    int waiting_time;
    int turnaround_time;
};


int findShortestProcess(struct Process* processes, int n, int current_time) {
    int shortest = -99999;
    int shortest_time = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_time && processes[i].remaining_time > 0) {
            shortest = i;
            shortest_time = processes[i].remaining_time;
        }
    }

    return shortest;
}


void SRTF(struct Process* processes, int n) {
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        int shortest_process = findShortestProcess(processes, n, current_time);

        if (shortest_process == -99999) {
            current_time++;
        } else {
            processes[shortest_process].remaining_time--;
            current_time++;

            printf("Process[%d] executes at time %d\n", processes[shortest_process].id, current_time);


            if (processes[shortest_process].remaining_time == 0) {
                completed_processes++;
                processes[shortest_process].turnaround_time = current_time - processes[shortest_process].arrival_time;
                processes[shortest_process].waiting_time = processes[shortest_process].turnaround_time - processes[shortest_process].burst_time;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Shortest Remaining Time First (SRTF) Scheduling:\n");
    SRTF(processes, n);


    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}
