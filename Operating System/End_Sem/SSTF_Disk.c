#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_REQUESTS 100

void SSTF(int n, int head, int req[])
{
    int visited[MAX_REQUESTS] = {0};
    int seek_time = 0;

    printf("The sequence of movement is: \n");
    printf("%d ", head);

    for (int i = 0; i < n; ++i)
    {
        int min = INT_MAX;
        int index = -1;

        //! finding closet index to the R/W head
        for (int j = 0; j < n; ++j)
        {
            if (visited[j] == 0 && abs(head - req[j]) < min)
            {
                min = abs(head - req[j]);
                index = j;
            }
        }

        visited[index] = 1;
        seek_time += min;
        // printf("-> %d ", req[index]);

        head = req[index];
        printf("-> %d ", req[index]);
    }

    printf("\nTotal seek time: %d\n", seek_time);
}

int main()
{
    int n, head;
    printf("Enter the Numbers of Requests : ");
    scanf("%d", &n);

    if (n > MAX_REQUESTS)
    {
        printf("Error: Number of requests cannot exceed %d\n", MAX_REQUESTS);
        return 0;
    }

    printf("Enter the head position : ");
    scanf("%d", &head);

    int req[MAX_REQUESTS];
    printf("Enter the requests: \n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    SSTF(n, head, req);

    return 0;
}