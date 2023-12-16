#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
};

//* Sorting Algorithm

void sort(struct Process arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int min = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j].at <= arr[min].at)
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
    printf("Enter The Number of Processes: ");
    scanf("%d", &n);

    struct Process arr[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i].pid = i + 1;
        printf("Enter the AT and BT of the %d Process : ", arr[i].pid);
        scanf("%d %d", &arr[i].at, &arr[i].bt);
    }

    sort(arr, n);

    int ttat = 0, twt = 0, ct = arr[0].ct;
    int idle_time = 0;

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            ct = arr[i].bt;
        }
        else if (ct < arr[i].at)
        {
            idle_time += arr[i].at - ct;
            ct = arr[i].at + arr[i].bt;
        }
        else
        {
            ct = ct + arr[i].bt;
        }

        arr[i].ct = ct;
        arr[i].tat = arr[i].ct - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
        ttat += arr[i].tat;
        twt += arr[i].wt;
    }

    float atat = (ttat * 1.0) / n;
    float awt = (twt * 1.0) / n;

    float utilization = (((ct - idle_time) * 1.0) / ct) * 100;
    float throughput = n * 1.0 / ct;

    printf("-----------------------------------------\n\n");

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; ++i)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    }

    printf("-----------------------------------------\n");
    printf("Average Turn Around Time : %f \n", atat);
    printf("Average Waiting Time : %f \n", awt);
    printf("Throughput: %f \n", throughput);
    printf("CPU Utilization percentage is : %f\n", utilization);
    printf("-----------------------------------------");

    return 0;
}