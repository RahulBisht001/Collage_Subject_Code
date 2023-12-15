#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct process
{
    int id;
    int waitingTime;
    int arrivalTime;
    int burstTime;
    int remainingBurstTime; // Add remaining burst time
    int Tat;

} p;

int findShortestRemainingProcess(p pro[], int n, int currentTime)
{
    int shortestProcess = -1;
    int shortestTime = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (pro[i].arrivalTime <= currentTime && pro[i].remainingBurstTime > 0)
        {
            if (pro[i].remainingBurstTime < shortestTime)
            {
                shortestProcess = i;
                shortestTime = pro[i].remainingBurstTime;
            }
        }
    }

    return shortestProcess;
}

void SRTF(p pro[], int n)
{
    int currentTime = 0;
    int totalBurstTime = 0;

    while (true)
    {
        int shortestProcess = findShortestRemainingProcess(pro, n, currentTime);

        if (shortestProcess == -1)
            break;

        pro[shortestProcess].remainingBurstTime--;

        if (pro[shortestProcess].remainingBurstTime == 0)
        {
            // Process has completed
            int completionTime = currentTime + 1;
            pro[shortestProcess].Tat = completionTime - pro[shortestProcess].arrivalTime;
            pro[shortestProcess].waitingTime = pro[shortestProcess].Tat - pro[shortestProcess].burstTime;

            // Update current time and total burst time
            currentTime = completionTime;
            totalBurstTime += pro[shortestProcess].burstTime;
        }
        else
        {
            // Process is still running
            currentTime++;
        }
    }

    double cpuUtili = totalBurstTime / (double)currentTime;
    double throughput = (double)n / currentTime;

    printf("CpuUtili=%.4lf\n", cpuUtili);
    printf("Throughput=%.4lf\n", throughput);
}

int main()
{
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    p pro[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of Process %d: ", i + 1);
        scanf("%d", &pro[i].arrivalTime);
        printf("Enter the burst time of Process %d: ", i + 1);
        scanf("%d", &pro[i].burstTime);

        pro[i].id = i + 1;
        pro[i].remainingBurstTime = pro[i].burstTime; // Initialize remaining burst time
    }

    SRTF(pro, n);

    printf("PID\tAT\tBT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", pro[i].id, pro[i].arrivalTime, pro[i].burstTime, pro[i].Tat, pro[i].waitingTime);
    }

    return 0;
}