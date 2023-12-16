#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void SSTF(int n, int head, int requests[])
{
    int visited[n];

    for (int i = 0; i < n; ++i)
    {
        visited[i] = 0;
    }

    int seek_time = 0;
    printf("The sequence of movement is: \n");
    printf("%d ", head);

    for (int i = 0; i < n; ++i)
    {
        int min = INT_MAX;
        int index = -1;

        for (int j = 0; j < n; ++j)
        {
            if (visited[j] == 0 && abs(requests[j] - head) < min)
            {
                min = abs(requests[j] - head);
                index = j;
            }
        }

        seek_time += min;
        visited[index] = 1;

        head = requests[i];
        printf("--> %d ", requests[index]);
    }

    printf("\nTotal Seek Time is : %d", seek_time);
}

int main()
{
    int n, head;
    printf("ENter the Number of Requests : ");
    scanf("%d", &n);

    printf("Enter the initial Position of Disk Head : ");
    scanf("%d", &head);

    int requests[n];
    printf("Enter the Requests\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &requests[i]);
    }
    SSTF(n, head, requests);
    return 0;
}