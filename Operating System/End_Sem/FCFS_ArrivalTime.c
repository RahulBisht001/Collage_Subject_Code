#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int at;
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
    printf("Enter the Number of Process : ");
    scanf("%d", &n);

    struct Process arr[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i].pid = i + 1;
        printf("Enter the AT and BT of the %d Process : ", arr[i].pid);
        scanf("%d %d", &arr[i].at, &arr[i].bt);
    }

    sort(arr, n);
}