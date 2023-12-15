#include <stdio.h>
#include <stdlib.h>

int main()
{
    int seek_time = 0, n;
    int req[20];
    int head;
    int maxTrack = 199;

    printf("Enter the number of locations: ");
    scanf("%d", &n);

    printf("Enter the position of the head: ");
    scanf("%d", &head);

    printf("Enter elements of the disk queue:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    req[n] = head;
    n = n + 1;

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

    int dloc = -1;

    for (int i = 0; i < n; i++)
    {
        if (head == req[i])
        {
            dloc = i;
            break;
        }
    }

    printf("Sequence of serviced tracks:\n");
    for (int i = dloc; i < n; i++)
    {
        printf("%d --> ", req[i]);
        seek_time += abs(req[i] - head);
        head = req[i];
    }
    printf("%d --> ", maxTrack);
    seek_time += abs(maxTrack - head);
    head = maxTrack;

    printf("0 --> ");

    seek_time += abs(head - 0);
    head = 0;

    for (int i = 0; i < dloc; i++)
    {
        printf("%d --> ", req[i]);
        seek_time += abs(req[i] - head);
        head = req[i];
    }

    printf("\nTotal seek time: %d\n", seek_time);
    return 0;
}