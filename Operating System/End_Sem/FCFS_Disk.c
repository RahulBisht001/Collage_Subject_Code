#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, head, seek_time = 0;

    printf("Enter the Number of Disk Requests\n");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the Requests \n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &requests[i]);
    }

    printf("Enter the Initial Position of Disk Head : ");
    scanf("%d", &head);

    printf("\n");

    //* Calculate Total Seek Time

    for (int i = 0; i < n; ++i)
    {
        seek_time += abs(head - requests[i]);
        printf("R/W Head Moved from %d to %d\n", head, requests[i]);
        head = requests[i];
    }

    printf("Total seek time: %d\n", seek_time);
    return 0;
}

/**
#include <stdio.h>
#include <stdlib.h>

int calcHeadTime(int arr[], int head, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(head - arr[i]);
        head = arr[i];
    }
    return ans;
}
void printQueue(int arr[], int head, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The total head time is %d", calcHeadTime(arr, head, n));
}
int main()
{
    int n, head;
    printf("Enter the number of requests below\n");
    scanf("%d", &n);

    printf("Enter the curr head position below\n");
    scanf("%d", &head);

    int queue[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    printQueue(queue, head, n);
}
*/