#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int n, quantum_time;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process arr[n];

    int completed = 0, curr_time = 0, total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        arr[i].pid = i + 1;
        printf("Enter the arrival time and burst time of process %d: ", arr[i].pid);
        scanf("%d %d", &arr[i].at, &arr[i].bt);
        arr[i].remaining_bt = arr[i].bt;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum_time);

    while (completed < n)
    {
        for (int i = 0; i < n && completed < n; i++)
        {
            if (arr[i].remaining_bt > 0 && arr[i].at <= curr_time)
            {
                if (arr[i].remaining_bt > quantum_time)
                {
                    curr_time += quantum_time;
                    arr[i].remaining_bt -= quantum_time;
                }
                else
                {
                    curr_time += arr[i].remaining_bt;
                    arr[i].remaining_bt = 0;
                    arr[i].ct = curr_time;
                    arr[i].tat = arr[i].ct - arr[i].at;
                    arr[i].wt = arr[i].tat - arr[i].bt;
                    total_tat += arr[i].tat;
                    total_wt += arr[i].wt;
                    completed++;
                }
            }
        }
    }

    printf("\nAverage waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turn around time = %.2f\n\n", (float)total_tat / n);

    printf("---------------------------------------------------------------------\n");
    printf("| Process | AT  | BT  | CT    | TAT   | WT    |\n");
    printf("---------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("| %d\t  | %d\t| %d\t| %d\t| %d\t| %d \t|\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    printf("---------------------------------------------------------------------\n");

    return 0;
}
