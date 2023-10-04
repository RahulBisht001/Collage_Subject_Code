#include <stdio.h>
#include <stdlib.h>

typedef struct Process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} Process;

void getInput(Process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].pid = i + 1;
    }
}

void sortProcesses(Process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void calculateOtherTime(Process p[], int n, int *idelTime, int *totalTime)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            p[i].ct = p[i].at + p[i].bt;
        else
        {
            if (p[i - 1].ct > p[i].at)
            {
                p[i].ct = p[i - 1].ct + p[i].bt;
            }
            else if (p[i - 1].ct < p[i].at)
            {
                (*idelTime) += p[i].at - p[i - 1].ct;
                p[i].ct = p[i].at + p[i].bt;
            }
            else
            {
                p[i].ct = p[i].at + p[i].bt;
            }
        }
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        if (i == n - 1)
        {
            (*totalTime) = p[i].ct;
        }
    }
}

void calculate(Process p[], int n, int totalTime, int idelTime, double *utilization, double *throughput, double *awt)
{
    (*utilization) = ((double)(totalTime - idelTime)) / (double)totalTime;
    (*throughput) = (double)n / (double)totalTime;

    int sumWait = 0;
    for (int i = 0; i < n; i++)
    {
        sumWait += p[i].wt;
    }

    (*awt) = sumWait / n;
}

void printProcesses(Process p[], int n, int totalTime, int idelTime, double utilization, double throuhput, double awt)
{
    printf("/n\t\tDemonstration of FCFS scheduling algorithm.\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Total time: %d\n", totalTime);
    printf("Idel time: %d\n", idelTime);
    printf("Utilization: %lf\n", utilization);
    printf("Throughput: %lf\n", throuhput);
    printf("Average waiting time: %lf\n", awt);
}

int main()
{

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process *p = (Process *)malloc(n * sizeof(Process));
    if (p == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    getInput(p, n);
    sortProcesses(p, n);

    int idelTime = 0;
    int totalTime = 0;
    double utilization = 0, throughput = 0, awt = 0;

    calculateOtherTime(p, n, &idelTime, &totalTime);
    calculate(p, n, totalTime, idelTime, &utilization, &throughput, &awt);
    printProcesses(p, n, totalTime, idelTime, utilization, throughput, awt);
    free(p);
    return 0;
}
