#include <stdio.h>
#include <math.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void merge(struct process arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    struct process L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].at <= R[j].at)
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}
void merge_sort(struct process arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    printf("Enter the number of processes : ");
    scanf("%d", &n);

    struct process arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].pid = i + 1;
        printf("Enter the arrival time and burst time of %d process : ", arr[i].pid);
        scanf("%d %d", &arr[i].at, &arr[i].bt);
    }
    merge_sort(arr, 0, n - 1);

    int ttat = 0, twt = 0, ct = arr[0].ct;
    int idle_time = 0;

    for (int i = 0; i < n; i++)
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

    float atat = ttat / (float)n;
    float awt = twt / (float)n;
    float utilization = ((ct - idle_time) / (float)ct) * 100;
    float throughput = n / (float)ct;
    printf("%f is the average Turnaround time\n", atat);
    printf("%f is the average Waiting time\n", awt);
    printf("%f is the CPU utilization percentage \n", utilization);
    printf("%f is the CPU throughput\n", throughput);

    printf("-------------------------------------------------------\n");
    printf("|  Process\t AT\t BT\t CT\t TAT\t WT   \n");
    for (int i = 0; i < n; i++)
        printf("|\t%d\t %d\t %d\t %d\t %d\t %d   \n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    printf("-------------------------------------------------------\n");
    return 0;
}