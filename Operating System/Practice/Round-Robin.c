#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct process
{
    int pid, at, bt, ct, tat, wt, remTime, rt, qint;
} process;

void getInput(process p[], int n, int *tq)
{
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d", &p[i].at);
        p[i].qint = p[i].at;
        scanf("%d", &p[i].bt);
        p[i].remTime = p[i].bt;
        p[i].rt = -1;
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", tq);
}

void printChart(process p[], int n)
{
    printf("\n");

    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }
}

void getNextProcess(process p[], int n, int curTime, int *npidx)
{
    int minAt = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (p[i].qint <= curTime && p[i].remTime > 0 && p[i].qint <= minAt)
        {
            if (p[i].qint == minAt && p[i].at <= p[*npidx].at)
            {
                continue;
            }
            minAt = p[i].qint;
            *npidx = i;
        }
    }
}

void roundRobin(process p[], int n, int tq)
{
    int curTime = 0, idelTime = 0, done = 0;

    while (done < n)
    {
        int npidx = -1;

        getNextProcess(p, n, curTime, &npidx);

        if (npidx == -1)
        {
            curTime++;
            idelTime++;
        }
        else
        {
            if (p[npidx].remTime == p[npidx].bt && p[npidx].rt == -1)
                p[npidx].rt = curTime - p[npidx].at;

            if (p[npidx].remTime > tq)
            {
                curTime += tq;
                p[npidx].remTime -= tq;
                p[npidx].qint = curTime;
            }
            else
            {
                curTime += p[npidx].remTime;
                p[npidx].remTime = 0;
                p[npidx].ct = curTime;
                p[npidx].tat = p[npidx].ct - p[npidx].at;
                p[npidx].wt = p[npidx].tat - p[npidx].bt;
                done++;
            }
        }
    }
    int totalTAT = 0, totalWT = 0;

    for (int i = 0; i < n; i++)
    {
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }
    printChart(p, n);

    printf("\n\nAverage TAT: %f\n", (float)totalTAT / n);
    printf("Average WT: %f\n", (float)totalWT / n);
    printf("Total idel time: %d\n", idelTime);
    printf("Utilization: %f\n", (float)(curTime - idelTime) / curTime);
    printf("Throughput: %f\n\n", (float)n / curTime);
}

int main()
{
    int n;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    process *p = (process *)malloc(n * sizeof(process));
    int tq = 0;
    getInput(p, n, &tq);

    roundRobin(p, n, tq);
    return 0;
}