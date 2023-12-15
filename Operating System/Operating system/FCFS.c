#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int id;
    int arrivalTime;
    int waitingTime;
    int Tat;
    int burstTime;
} p;

void print(p processes[], int n)
{
    printf("Processid\tArrivalTime\tBurstTime\tWaitingTime\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, processes[i].waitingTime, processes[i].Tat);
    }
    float sumw, sumt;
    for (int i = 0; i < n; i++)
    {
        sumw += processes[i].waitingTime;
        sumt += processes[i].Tat;
    }
    printf("Average TurnaroundTime = %.2lf\n", sumt * 1.0 / n);
    printf("Average waitingTime = %.2lf", sumw * 1.0 / n);

    // float throughput=(float)n/sumt;
    //   printf("\nThroughput=%.2lf process per unit time",throughput);
}

void sort(p processes[], int n)
{//this sort is called bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (processes[i].arrivalTime > processes[j].arrivalTime)
            {
                p temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void fcfs(p processes[], int n)
{
    sort(processes, n);

    int currentTime = 0;
    int totalBurstTime = 0;

    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrivalTime > currentTime)
        {
            currentTime = processes[i].arrivalTime;
        }

        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        processes[i].Tat = processes[i].waitingTime + processes[i].burstTime;

        currentTime += processes[i].burstTime;
        totalBurstTime += processes[i].burstTime;
    }

    float cpuUtilization = (float)totalBurstTime / currentTime;
    printf("CPU Utilization: %.2f\n", cpuUtilization);
    float throughput = (float)n / currentTime;
    printf("Throughput=%.2lf process per unit time\n", throughput);
    // Inside the fcfs function after calculating totalBurstTime
    int totalExecutionTime = totalBurstTime;
    int firstArrivalTime = processes[0].arrivalTime;
    int lastCompletionTime = firstArrivalTime + totalExecutionTime;
    int totalIdleTime = lastCompletionTime - totalExecutionTime;

    printf("Total CPU Execution Time: %d\n", totalExecutionTime);
    printf("Total Idle Time: %d\n", totalIdleTime);
}

int main()
{
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    p processes[n];

    printf("Enter the details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of Process%d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter the burst time of Process%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].id = i + 1;
    }

    fcfs(processes, n);
    print(processes, n);

    return 0;
}
