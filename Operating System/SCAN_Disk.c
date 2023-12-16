#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    int head, maxTrack = 199;
    int seek_time = 0;

    printf("Enter the Number of requests : ");
    scanf("%d", &n);

    int req[n];

    printf("Enter the Initial Position of the R/W Head : ");
    scanf("%d", &head);

    printf("Enter the Request in Disk Queue \n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &req[i]);
    }

    // sorting

    for (int i = 0; i < n; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (req[j] < req[min])
            {
                min = j;
            }
        }

        int temp = req[min];
        req[min] = req[i];
        req[i] = temp;
    }

    printf("The Sequence of Track is \n");
    printf("%d ", head);

    for (int i = 0; i < n; ++i)
    {
        if (req[i] > head)
        {
            printf(" --> %d", req[i]);
            seek_time += abs(req[i] - head);
            head = req[i];
        }
    }

    printf(" --> %d", maxTrack);
    seek_time += abs(maxTrack - head);
    head = maxTrack;

    for (int i = n - 1; i >= 0; --i)
    {
        if (req[i] < head)
        {
            printf("--> %d", req[i]);
            seek_time += abs(req[i] - head);
            head = req[i];
        }
    }

    printf("\nThe Total seek_time is : %d", seek_time);

    return 0;
}