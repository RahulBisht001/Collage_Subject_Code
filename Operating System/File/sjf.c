// sjf non preemptive

#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int pid;
    int bt;
    int ct;
    int tat;
    int wt;
} Process;

int compare(const void *a, const void *b)
{
    return (((Process *)a)->bt) - (((Process *)b)->bt);
}

int main()
{
    int n;
    printf("Enter the Total number of Processes:");
    scanf("%d", &n);
    Process arr[n];
    printf("For each Process Enter its Process id and Burst Time(BT) respectively\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].pid);
        scanf("%d", &arr[i].bt);
    }
    qsort(arr, n, sizeof(Process), compare);
    int idle_time = 0;
    int total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            arr[i].ct = arr[i].bt;
        }
        else
        {
            arr[i].ct = arr[i].bt + arr[i - 1].ct;
        }
        arr[i].tat = arr[i].ct;
        total_tat += arr[i].tat;
        arr[i].wt = arr[i].tat - arr[i].bt;
        total_wt += arr[i].wt;
    }
    printf("PID    BT    CT    TAT    WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d     %d     %d     %d     %d\n", arr[i].pid, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    }
    printf("Average tat = %lf\n", total_tat / (double)n);
    printf("Average wt = %lf\n", total_wt / (double)n);
    printf("C.P.U utilization = %lf \n", ((arr[n - 1].ct - idle_time) / (double)arr[n - 1].ct) * 100);
    printf("Throughput = %lf \n", (n / (double)arr[n - 1].ct) * 100);
}