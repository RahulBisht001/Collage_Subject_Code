#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int ct;
    int at;
    int bt;
    int wt;
    int tat;
    int remaining_bt;
};

int findNextProcess(struct Process arr[], int n, int cur_time)
{
    int min_time = 1e9;
    int idx = -1;

    for (int i = 0; i < n; ++i)
    {
        if (arr[i].at <= cur_time && arr[i].remaining_bt < min_time && arr[i].remaining_bt != 0)
        {
            min_time = arr[i].remaining_bt;
            idx = i;
        }
    }

    return idx;
}

int main()
{
    int n;
    printf("Enter the Number of Process : ");
    scanf("%d", &n);

    struct Process arr[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i].pid = i + 1;
        printf("Enter the AT and BT of the Process %d :- ", arr[i].pid);
        scanf("%d %d", &arr[i].at, &arr[i].bt);

        arr[i].remaining_bt = arr[i].bt;
    }
    printf("\n");

    int total_tat = 0, total_wt = 0;
    int cur_time = 0, idle_time = 0, completed = 0;

    while (completed != n)
    {
        int idx = findNextProcess(arr, n, cur_time);

        if (idx == -1)
        {
            cur_time++;
            idle_time++;
            continue;
        }
        arr[idx].remaining_bt--;

        if (arr[idx].remaining_bt == 0)
        {
            completed++;

            arr[idx].ct = cur_time + 1;
            arr[idx].tat = arr[idx].ct - arr[idx].at;
            arr[idx].wt = arr[idx].tat - arr[idx].bt;

            total_tat += arr[idx].tat;
            total_wt += arr[idx].wt;
        }
        cur_time++;
    }

    printf("------------------------------------\n");
    printf("Average Turnaround time is : %0.2f\n", (1.0 * total_tat) / n);
    printf("Average waiting time is : %0.2f\n", (1.0 * total_wt) / n);
    printf("CPU Utilization is : %0.2f\n", ((cur_time - idle_time) / cur_time) * 100);
    printf("------------------------------------\n");

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; ++i)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    }
    printf("------------------------------------\n");

    return 0;
}