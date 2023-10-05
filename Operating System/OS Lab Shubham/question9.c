#include <stdio.h>
#include <stdbool.h>

struct process
{
    int pid;
    int at;
    int bt;
    int remaining_bt;
    int ct;
    int tat;
    int wt;
};

int findNextProcess(struct process arr[], int n, int curr_time)
{
    int min_time = 1e9;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].at <= curr_time && arr[i].remaining_bt < min_time && arr[i].remaining_bt != 0)
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
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process arr[n];

    int total_tat = 0, total_wt = 0, curr_time = 0;

    for (int i = 0; i < n; i++)
    {
        arr[i].pid = i + 1;
        printf("Enter the arrival time and burst time of %d process: ", arr[i].pid);
        scanf("%d %d", &arr[i].at, &arr[i].bt);
        arr[i].remaining_bt = arr[i].bt;
    }

    int completed = 0, idle_time = 0;

    while (completed != n)
    {
        int idx = findNextProcess(arr, n, curr_time);

        if (idx == -1)
        {
            curr_time++;
            idle_time++;
            continue;
        }

        arr[idx].remaining_bt--;

        if (arr[idx].remaining_bt == 0)
        {
            completed++;

            arr[idx].ct = curr_time + 1;
            arr[idx].tat = arr[idx].ct - arr[idx].at;
            arr[idx].wt = arr[idx].tat - arr[idx].bt;

            total_tat += arr[idx].tat;
            total_wt += arr[idx].wt;
        }
        curr_time++;
    }

    printf("%.2f is the average Turnaround time\n", (float)total_tat / n);
    printf("%.2f is the average Waiting time\n", (float)total_wt / n);
    printf("CPU Utilization = %.2f\n", (float)(curr_time - idle_time) / curr_time);

    printf("----------------------------------------------------------\n");
    printf("| Process | AT  | BT  | CT    | TAT   | WT    |\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("| %d\t | %d\t| %d\t| %d\t| %d\t| %d \t|\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);

    printf("----------------------------------------------------------\n");

    return 0;
}
