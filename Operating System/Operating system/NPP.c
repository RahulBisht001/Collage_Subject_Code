#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
} p;

void sort(p pro[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pro[j].priority > pro[j + 1].priority)
            {
                p temp = pro[j + 1];
                pro[j + 1] = pro[j];
                pro[j] = temp;
            }
        }
    }
}

void PriorityScheduling(p pro[], int n)
{
    int currentTime = 0;
    int totalBurstTime = 0;

    for (int i = 0; i < n; i++)
    {
        if (pro[i].arrivalTime > currentTime)
        {
            currentTime = pro[i].arrivalTime;
        }

        pro[i].waitingTime = currentTime - pro[i].arrivalTime;
        pro[i].turnaroundTime = pro[i].waitingTime + pro[i].burstTime;

        // Update current time
        currentTime += pro[i].burstTime;
        totalBurstTime += pro[i].burstTime;
    }

    double cpuUtilization = (double)totalBurstTime / currentTime;
    double throughput = (double)n / currentTime;

    printf("CPU Utilization: %.4lf\n", cpuUtilization);
    printf("Throughput: %.4lf\n", throughput);
}

void print(p pro[], int n)
{
    printf("PID\tAT\tBT\tPriority\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pro[i].id, pro[i].arrivalTime, pro[i].burstTime,
               pro[i].priority, pro[i].turnaroundTime, pro[i].waitingTime);
    }

    double sumw = 0.0, sumt = 0.0;
    for (int i = 0; i < n; i++)
    {
        sumw += pro[i].waitingTime;
        sumt += pro[i].turnaroundTime;
    }
    printf("Average Waiting Time: %.4lf\n", sumw / (double)n);
    printf("Average Turnaround Time: %.4lf\n", sumt / (double)n);
}

int main()
{
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    p pro[n];

    for (int i = 0; i < n; i++)
    {
        pro[i].id = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &pro[i].arrivalTime);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &pro[i].burstTime);
        printf("Enter priority for Process %d: ", i + 1);
        scanf("%d", &pro[i].priority);
    }

    sort(pro, n); // Sort the processes by priority

    PriorityScheduling(pro, n);
    print(pro, n);

    return 0;
}
