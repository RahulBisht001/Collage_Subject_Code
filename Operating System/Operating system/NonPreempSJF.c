#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimesSRTF(struct Process processes[], int n)
{
    int currentTime = 0;
    int completed = 0;

    while (completed < n)
    {
        int shortest = -1;
        int shortestTime = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime < shortestTime && processes[i].remainingTime > 0)
            {
                shortest = i;
                shortestTime = processes[i].remainingTime;
            }
        }

        if (shortest == -1)
        {
            currentTime++;
        }
        else
        {
            processes[shortest].remainingTime--;

            if (processes[shortest].remainingTime == 0)
            {
                completed++;
                int finishTime = currentTime + 1;
                processes[shortest].waitingTime = finishTime - processes[shortest].arrivalTime - processes[shortest].burstTime;
                processes[shortest].turnaroundTime = finishTime - processes[shortest].arrivalTime;

                currentTime++;
            }
            else
            {
                currentTime++;
            }
        }
    }
}

void printResults(struct Process processes[], int n)
{
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }
    float sumt = 0, sumw = 0;
    // calculating average waiting time & average turnaround time
    for (int i = 0; i < n; i++)
    {
        sumw += processes[i].waitingTime;
        sumt += processes[i].turnaroundTime;
    }
    printf("\n\n average waiting time = %.2f", sumw * 1.0 / n);
    printf("\n\n average turnaround time = %.2f", sumt * 1.0 / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }

    calculateTimesSRTF(processes, n);

    printResults(processes, n);

    return 0;
}
