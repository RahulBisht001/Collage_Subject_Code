#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int bt;
    int ct;
    int pr;
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
            if (arr[j].pr < arr[min].pr)
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
    printf("Enter the Number of Process : ");
    scanf("%d", &n);

    struct Process arr[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i].pid = i + 1;
        printf("Enter the BT and Priority of the %d Process : ", arr[i].pid);
        scanf("%d %d", &arr[i].bt, &arr[i].pr);
    }

    sort(arr, n);

    int ct = 0, ttat = 0, twt = 0;

    for (int i = 0; i < n; ++i)
    {
        ct += arr[i].bt;

        arr[i].ct = ct;
        arr[i].tat = arr[i].ct;
        arr[i].wt = arr[i].tat - arr[i].bt;

        ttat += arr[i].tat;
        twt += arr[i].wt;
    }

    float awt = 0, atat = 0;
    awt = (1.0 * twt) / n;
    atat = (1.0 * ttat) / n;

    printf("------------------------------\n");
    printf("Average Waiting Time is %f\n", awt);
    printf("Average Turn around Time is %f\n", atat);

    printf("------------------------------\n");
    printf("PID\tPR\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; ++i)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", arr[i].pid, arr[i].pr, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    }
    printf("------------------------------\n");

    return 0;
}