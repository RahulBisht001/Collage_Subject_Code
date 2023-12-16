#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int head, maxTrack = 199;
    int req[20];
    int seek_time = 0;

    printf("Enter the Number of requests : ");
    scanf("%d", &n);

    printf("Enter the R/W Head of the Disk : ");
    scanf("%d", &head);

    printf("Enter elements of the disk queue:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    req[n] = head;
    n = n + 1;

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

    int dloc = -1;

    for (int i = 0; i < n; ++i)
    {
        if (req[i] == head)
        {
            dloc = i;
            break;
        }
    }

    printf("Sequence of serviced tracks:\n");
    // printf("%d ", head);

    for (int i = dloc; i < n; ++i)
    {
        printf("%d --> ", req[i]);
        seek_time += abs(req[i] - head);
        head = req[i];
    }

    printf("%d --> ", maxTrack);
    seek_time += abs(maxTrack - head);
    head = maxTrack;

    printf("0 -->");
    seek_time += (head - 0);
    head = 0;

    for (int i = 0; i < dloc; ++i)
    {
        printf("%d -->", req[i]);
        seek_time += abs(req[i] - head);
        head = req[i];
    }
    printf("\nTotal seek time: %d\n", seek_time);
    return 0;
}