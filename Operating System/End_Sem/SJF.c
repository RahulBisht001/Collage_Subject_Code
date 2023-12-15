#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int bt;
    int ct;
    int tat;
    int wt;
};

void sort(struct Process arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j].bt <= arr[min].bt)
            {
                min = j;
            }
        }

        struct Process temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
        printf("The Burst Time of Process %d : ", arr[i].pid);
        scanf("%d", &arr[i].bt);
    }

    printf("\n");
    sort(arr, n);

    int ttat = 0, twt = 0, ct = 0;

    for (int i = 0; i < n; ++i)
    {
        ct += arr[i].bt;

        arr[i].ct = ct;
        arr[i].tat = ct;
        arr[i].wt = arr[i].tat - arr[i].bt;

        ttat += arr[i].tat;
        twt += arr[i].wt;
    }

    float awt = 0.0, atat = 0.0;
    float CPU_utilization = 0, throughput = 0.0;

    awt = (1.0 * twt) / n;
    atat = (1.0 * ttat) / n;
    throughput = (1.0 * n) / ct;

    printf("------------------------------------\n");
    printf("This is SJF scheduling Algo\n");
    printf("Average waiting time is : %f\n", awt);
    printf("Average turnaround time is : %f\n", atat);
    printf("Throughput is : %f\n", throughput);

    printf("------------------------------------\n");
    printf("Pid\tBT\tCT\tTAT\tWT\n\n");

    for (int i = 0; i < n; ++i)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", arr[i].pid, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    }
    printf("------------------------------------\n");

    return 0;
}