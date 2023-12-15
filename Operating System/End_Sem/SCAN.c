#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int seek_time = 0, n;
    int req[20];
    int head, maxTrack = 199;

    printf("Enter the number of requests : ");
    scanf("%d", &n);

    printf("Enter the position of the head : ");
    scanf("%d", &head);

    printf("Enter the Number of Tracks : ");
    scanf("%d", &maxTrack);

    printf("Enter elements of the Disk queue:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    // sorting
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (req[i] > req[j])
            {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    printf("Sequence of serviced tracks:\n");
    printf("%d ", head);

    for (int i = 0; i < n; i++)
    {
        if (req[i] > head)
        {
            printf("--> %d ", req[i]);
            seek_time += abs(req[i] - head);
            head = req[i];
        }
    }

    seek_time += abs(maxTrack - head);
    head = maxTrack;
    printf("--> %d ", head);

    for (int i = n - 1; i >= 0; i--)
    {
        if (req[i] < head)
        {
            printf("--> %d ", req[i]);
            seek_time += abs(req[i] - head);
            head = req[i];
        }
    }
    printf("\nTotal seek time: %d\n", seek_time);
    return 0;
}