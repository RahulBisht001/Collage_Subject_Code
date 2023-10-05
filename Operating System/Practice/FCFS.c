#include <stdio.h>
#define max 30

int main()
{
    int n;
    int bt[max], wt[max], tat[max];
    float awt, atat; //* Average Waiting Time and Average Turn Around Time

    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    printf("Enter the Burst time of Each Process: \n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &bt[i]);
    }

    printf("Process\t\tBurst Time\tWaiting Time\tTurnAround Time \n");
    for (int i = 0; i < n; ++i)
    {
        wt[i] = 0;
        tat[i] = 0;

        for (int j = 0; j < i; ++j)
        {
            wt[i] += bt[j];
        }
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];

        printf("%d\t\t %d\t\t%d\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time is : %f\n", awt / n);
    printf("Average Turn Around Time is : %f\n", atat / n);
}