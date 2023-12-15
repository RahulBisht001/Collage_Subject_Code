#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct process
{
    int id;
    int at;
    int bt;
    int tat;
    int p;
    int rt;
    int wt;
} p;

void sortp(p pro[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pro[j].p > pro[j + 1].p)
            {
                p temp = pro[j + 1];
                pro[j + 1] = pro[j];
                pro[j] = temp;
            }
        }
    }
}

void ppt(p pro[], int n)
{
    int currentTime = 0;
    int completed = 0;
    int tburstTime = 0;          // Initialize total burst time
    int totalWaitingTime = 0;    // Variable to store the total waiting time
    int totalTurnaroundTime = 0; // Variable to store the total turnaround time

    while (completed < n)
    {
        int highestPriority = INT_MAX;
        int currentProcess = -1;

        for (int i = 0; i < n; i++)
        {
            if (pro[i].at <= currentTime && pro[i].bt > 0 && pro[i].p < highestPriority)
            {
                highestPriority = pro[i].p;
                currentProcess = i;
            }
        }

        if (currentProcess == -1)
        {
            currentTime++;
        }
        else
        {
            pro[currentProcess].bt--;
            currentTime++;

            if (pro[currentProcess].bt == 0)
            {
                int completionTime = currentTime;
                pro[currentProcess].tat = completionTime - pro[currentProcess].at;
                pro[currentProcess].wt = pro[currentProcess].tat - pro[currentProcess].bt - pro[currentProcess].at;

                // Update total waiting time and total turnaround time
                totalWaitingTime += pro[currentProcess].wt;
                totalTurnaroundTime += pro[currentProcess].tat;
                tburstTime += pro[currentProcess].bt; // Update total burst time
                completed++;
            }
        }
    }

    double cpuUtili = (double)tburstTime / currentTime;
    double throughput = (double)n / currentTime;

    printf("CPU Utilization: %.4lf\n", cpuUtili);
    printf("Throughput: %.4lf\n", throughput);

    // Calculate and print average waiting time and average turnaround time
    double averageWaitingTime = (double)totalWaitingTime / n;
    double averageTurnaroundTime = (double)totalTurnaroundTime / n;
    printf("Average Waiting Time: %.4lf\n", averageWaitingTime);
    printf("Average Turnaround Time: %.4lf\n", averageTurnaroundTime);
}

void print(p pro[], int n)
{
    printf("PID\tAT\tBT\tTAT\tPriority\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n", pro[i].id, pro[i].at, pro[i].bt, pro[i].tat, pro[i].p, pro[i].wt);
    }
}
void main()
{
    int n;
    printf("Enter the number of process:\n");
    scanf("%d", &n);
    p pro[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time for %d process:", i + 1);
        scanf("%d", &pro[i].at);
        printf("Enter the burst time for %d process:", i + 1);
        scanf("%d", &pro[i].bt);
        printf("Enter the priority for %d process:", i + 1);
        scanf("%d", &pro[i].p);

        pro[i].rt = pro[i].bt;
        pro[i].id = i + 1;
    }

    sortp(pro, n);
    ppt(pro, n);
    print(pro, n);
    return;
}