#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head;
    int seek_time = 0;

    printf("Enter the Number of Disk Requests : ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the Disk Requests\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &requests[i]);
    }

    printf("Enter the Initial Position of the DIsk Head : ");
    scanf("%d", &head);

    // calculate Time
    for (int i = 0; i < n; ++i)
    {
        seek_time += abs(requests[i] - head);
        printf("R/W Head Moved from %d to %d\n", head, requests[i]);
        head = requests[i];
    }

    printf("Total seek time: %d\n", seek_time);

    return 0;
}