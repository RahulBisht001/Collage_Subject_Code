#include <stdio.h>
#include <stdlib.h>
typedef struct process
{
    int id;
    int waitingTime;
    int arrivalTime;
    int burstTime;
    int Tat;

} p;
void sort(p pro[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pro[j].burstTime > pro[j + 1].burstTime)
            {
                p temp = pro[j + 1];
                pro[j + 1] = pro[j];
                pro[j] = temp;
            }
        }
    }
}

void SJF(p pro[], int n)
{
    int currenTime = 0;
    int totalBurstTime = 0;
    for (int i = 0; i < n; i++)
    {
        if (pro[i].arrivalTime > currenTime)
        {
            currenTime = pro[i].arrivalTime;
        }

        pro[i].waitingTime = currenTime - pro[i].arrivalTime;
        pro[i].Tat = pro[i].waitingTime + pro[i].burstTime;

        // update current Timme
        currenTime += pro[i].burstTime;
        totalBurstTime += pro[i].burstTime;
    }
    double cpuUtili = totalBurstTime / currenTime;
    double throughput = (double)n / totalBurstTime;

    printf("CpuUtili=%.4lf\n", cpuUtili);
    printf("Throughput=%.4lf\n", throughput);
}

void print(p pro[], int n)
{

    printf("PID\tAT\tBT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", pro[i].id, pro[i].arrivalTime, pro[i].burstTime, pro[i].Tat, pro[i].waitingTime);
    }
    double sumw = 0.0, sumt = 0.0;
    for (int i = 0; i < n; i++)
    {
        sumw += pro[i].waitingTime;
        sumt += pro[i].Tat;
    }
    printf("Average waiting Time=%.4lf\n", sumw / (double)n);
    printf("Average TAT=%.4lf", sumt / (double)n);
}

void main()
{
    int n;
    printf("enter the number of processes:\n");
    scanf("%d", &n);
    p pro[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of %d processs:", i + 1);
        scanf("%d", &pro[i].arrivalTime);
        printf("Enter the burst time of %d processs:", i + 1);
        scanf("%d", &pro[i].burstTime);

        pro[i].id = i + 1;
    }
    sort(pro, n);
    SJF(pro, n);

    print(pro, n);
}