#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int bt;
    int ct;
    int tat;
    int wt;
};

int compare_burst(const void *a, const void *b)
{
    struct process *p1 = (struct process *)a;
    struct process *p2 = (struct process *)b;

    return p1->bt - p2->bt;
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].pid = i + 1;
        printf("Enter the burst time of %d process: ", arr[i].pid);
        scanf("%d", &arr[i].bt);
    }

    // Sorting based on burst time
    qsort(arr, n, sizeof(struct process), compare_burst);

    int ct = 0, ttat = 0, twt = 0;

    for (int i = 0; i < n; i++)
    {
        ct += arr[i].bt;

        arr[i].ct = ct;
        arr[i].tat = arr[i].ct; // Since AT is ignored and assumed as 0
        arr[i].wt = arr[i].tat - arr[i].bt;

        ttat += arr[i].tat;
        twt += arr[i].wt;
    }

    float atat = (float)ttat / n;
    float awt = (float)twt / n;

    printf("This is SJF (Shortest Job First) without considering Arrival Time\n");
    printf("%f is the average Turnaround time\n", atat);
    printf("%f is the average Waiting time\n", awt);

    printf("----------------------------------------------\n");
    printf(" Process\tBT\tCT\tTAT\tWT \n");
    for (int i = 0; i < n; i++)
        printf("\t%d\t %d\t %d\t %d\t %d\n", arr[i].pid, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    printf("----------------------------------------------\n");

    return 0;
}
