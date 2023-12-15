#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int at;
    int bt;
    int remaining_bt;
    int priority;
    int ct;
    int tat;
    int wt;
};

int findNextIndex(struct Process arr[], int n, int cur_time)
{
    int min_priority = 1e9;
    int idx = -1;

    for (int i = 0; i < n; ++i)
    {
        if (arr[i].at <= cur_time && arr[i].remaining_bt > 0)
        {
            if (arr[i].priority < min_priority || (arr[i].priority == min_priority && arr[i].at < arr[idx].at))
            {
                min_priority = arr[i].priority;
                idx = i;
            }
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
        printf("Enter the AT BT and Priority of the process %d :- ", arr[i].pid);
        scanf("%d %d %d", &arr[i].at, &arr[i].bt, &arr[i].priority);

        arr[i].remaining_bt = arr[i].bt;
    }

    int total_tat = 0, total_wt = 0;
    int completed = 0;
    int cur_time = 0, idle_time = 0;

    while (completed != n)
    {
        int idx = findNextIndex(arr, n, cur_time);
        if (idx == -1)
        {
            idle_time++;
            cur_time++;
            continue;
        }

        arr[idx].remaining_bt--;
        if (arr[idx].remaining_bt == 0)
        {
            completed++;

            int ct = cur_time + 1;
            arr[idx].ct = ct;
            arr[idx].tat = arr[idx].ct - arr[idx].at;
            arr[idx].wt = arr[idx].tat - arr[idx].bt;

            total_tat += arr[idx].tat;
            total_wt += arr[idx].wt;
        }
        cur_time++;
    }

    printf("%.2f is the average Turnaround time\n", (float)total_tat / n);
    printf("%.2f is the average Waiting time\n", (float)total_wt / n);
    printf("CPU Utilization = %.2f\n", (float)(cur_time - idle_time) / cur_time);

    printf("-----------------------------------------------------------------\n");
    printf("| Process ID | BT  | Priority | CT    | TAT   | WT    |\n");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("| %d\t  | %d\t| %d\t   | %d\t   | %d\t   | %d\t   |\n", arr[i].pid, arr[i].bt, arr[i].priority, arr[i].ct, arr[i].tat, arr[i].wt);
    printf("-----------------------------------------------------------------\n");

    return 0;
}