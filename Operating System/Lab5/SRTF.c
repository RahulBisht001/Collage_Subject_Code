#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    bool completed;
};

void findWaitingTime(struct Process processes[], int n, int waitingTime[]) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burst_time;
        waitingTime[i] = 0;
    }
    
    int currentTime = 0;
    int completed = 0;
    
    while (completed < n) {
        int minTime = 9999;
        int shortestProcess = -1;
        
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrival_time <= currentTime && remainingTime[i] < minTime) {
                minTime = remainingTime[i];
                shortestProcess = i;
            }
        }
        
        if (shortestProcess == -1) {
            currentTime++;
        } else {
            remainingTime[shortestProcess]--;
            currentTime++;
            
            if (remainingTime[shortestProcess] == 0) {
                processes[shortestProcess].completed = true;
                completed++;
                waitingTime[shortestProcess] = currentTime - processes[shortestProcess].arrival_time - processes[shortestProcess].burst_time;
            }
        }
    }
}

void findTurnaroundTime(struct Process processes[], int n, int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = processes[i].burst_time + waitingTime[i];
    }
}

void findAverageTime(struct Process processes[], int n) {
    int waitingTime[n];
    int turnaroundTime[n];
    
    findWaitingTime(processes, n, waitingTime);
    findTurnaroundTime(processes, n, waitingTime, turnaroundTime);
    
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;
    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, waitingTime[i], turnaroundTime[i]);
    }
    
    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time and burst time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = false;
    }
    
    findAverageTime(processes, n);
    
    return 0;
}
