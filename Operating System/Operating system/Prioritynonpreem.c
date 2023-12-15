#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;             // Process ID
    int burstTime;      // Burst time of the process
    int priority;       // Priority of the process (lower value indicates higher priority)
    int waitingTime;    // Waiting time for the process
    int turnaroundTime; // Turnaround time for the process
} Process;

void priorityScheduling(Process processes[], int n)
{
    int currentTime = 0;

    // Sort processes by priority (higher priority first)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].priority > processes[j + 1].priority)
            {
                // Swap processes[j] and processes[j+1]
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        // Calculate waiting time for each process
        processes[i].waitingTime = currentTime;
        currentTime += processes[i].burstTime;

        // Calculate turnaround time for each process
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

int main()
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter priority for Process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    // Perform Priority Scheduling
    priorityScheduling(processes, n);

    // Calculate and print average waiting time and average turnaround time
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    printf("\nProcess ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].priority,
               processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    double averageWaitingTime = totalWaitingTime / n;
    double averageTurnaroundTime = totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2lf\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", averageTurnaroundTime);

    return 0;
}
