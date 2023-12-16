#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int bt;
    int ct;
    int wt;
    int tat;
    int priority;
};

void sort(struct Process arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j].priority < arr[min].priority)
            {
                min = j;
            }
        }

        struct Process temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{

    int n;
    printf("Enter the Number of Processes : ");
    scanf("%d", &n);

    struct Process arr[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i].pid = i + 1;
        printf("Enter the BT and Priority of the Process %d :- ", arr[i].pid);
        scanf("%d %d", &arr[i].bt, &arr[i].priority);
    }

    sort(arr, n);

    int total_tat = 0, total_wt = 0;
    int ct = 0;

    for (int i = 0; i < n; ++i)
    {
        ct += arr[i].bt;

        arr[i].ct = ct;
        arr[i].tat = arr[i].ct;
        arr[i].wt = arr[i].tat - arr[i].bt;

        total_tat += arr[i].tat;
        total_wt += arr[i].wt;
    }

    float awt = 0.0, atat = 0;

    awt = (total_wt * 1.0) / n;
    atat = (total_tat * 1.0) / n;

    printf("------------------------------\n");
    printf("Average Waiting Time is %f\n", awt);
    printf("Average Turn around Time is %f\n", atat);

    printf("------------------------------\n");
    printf("PID\tPR\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; ++i)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", arr[i].pid, arr[i].priority, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    }

    printf("------------------------------\n");

    return 0;
}