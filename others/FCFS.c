#include<stdio.h>
#include<stdlib.h>

struct Process {
    int id; 
    int arrivalTime;
    int burstTime;
};

void WaitingTime(struct Process* processes, int* waitingTime, int n) {
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
    }
}

void TurnaroundTime(struct Process* processes, int* waitingTime, int* turnaroundTime, int n) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }
}

void avgTUT_WT(int* waitingTime, int* turnaroundTime, int n) {
    double avgturnaroundTime = 0.0, avgwaitingTime = 0.0; 
    for (int i = 0; i < n; i++) {
        avgwaitingTime += waitingTime[i];
        avgturnaroundTime += turnaroundTime[i];
    }
    avgturnaroundTime = avgturnaroundTime / (double)n; 
    avgwaitingTime = avgwaitingTime / (double)n;       
    printf("avgTurnaround Time= %.2lf\n", avgturnaroundTime); 
    printf("avgWaiting Time= %.2lf\n", avgwaitingTime);       
}


void FCFS(struct Process* processes, int n) {
    printf("Process Execution Order:\n");
    
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t", processes[i].id);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    int waitingTime[n];
    int turnaroundTime[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process P[%d]: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for process P[%d]: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    WaitingTime(processes, waitingTime, n);
    TurnaroundTime(processes, waitingTime, turnaroundTime, n);

    printf("Process\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\n", processes[i].id, waitingTime[i], turnaroundTime[i]);
    }
    FCFS(processes, n);
    avgTUT_WT(waitingTime, turnaroundTime, n);

    return 0;
}
