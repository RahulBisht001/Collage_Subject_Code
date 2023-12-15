#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void customSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void customSCAN(int requestSequence[], int initialHead, char moveDirection[], int totalTracks, int requestCount)
{
    int totalSeekTime = 0;
    int *leftRequests = (int *)malloc(totalTracks * sizeof(int));
    int *rightRequests = (int *)malloc(totalTracks * sizeof(int));
    int *seekSequence = (int *)malloc(totalTracks * 2 * sizeof(int));
    int sequenceIndex = 0;
    int leftCount = 0, rightCount = 0;

    if (strcmp(moveDirection, "left") == 0)
    {
        leftRequests[0] = 0;
        leftCount++;
    }
    else if (strcmp(moveDirection, "right") == 0)
    {
        rightRequests[0] = totalTracks - 1;
        rightCount++;
    }

    for (int i = 0; i < requestCount; i++)
    {
        if (requestSequence[i] < initialHead)
            leftRequests[leftCount++] = requestSequence[i];
        else if (requestSequence[i] > initialHead)
            rightRequests[rightCount++] = requestSequence[i];
    }

    customSort(leftRequests, leftCount);
    customSort(rightRequests, rightCount);

    int runs = 2;
    while (runs--)
    {
        if (strcmp(moveDirection, "left") == 0)
        {
            for (int i = leftCount - 1; i >= 0; i--)
            {
                totalSeekTime += abs(initialHead - leftRequests[i]);
                initialHead = leftRequests[i];
                seekSequence[sequenceIndex++] = initialHead;
            }
            strcpy(moveDirection, "right");
        }
        else if (strcmp(moveDirection, "right") == 0)
        {
            for (int i = 0; i < rightCount; i++)
            {
                totalSeekTime += abs(initialHead - rightRequests[i]);
                initialHead = rightRequests[i];
                seekSequence[sequenceIndex++] = initialHead;
            }
            strcpy(moveDirection, "left");
        }
    }

    printf("\nTotal seek time: %d\n", totalSeekTime);
    printf("The sequence of movement is: \n");
    for (int i = 0; i < sequenceIndex; i++)
        printf("%d ", seekSequence[i]);
    printf("\n");

    free(leftRequests);
    free(rightRequests);
    free(seekSequence);
}

int main()
{
    printf("\n\n");
    int totalRequests, initialHead, totalTracks;
    printf("Enter total number of tracks: ");
    scanf("%d", &totalTracks);
    printf("Enter the number of requests: ");
    scanf("%d", &totalRequests);
    printf("Enter the initial head position: ");
    scanf("%d", &initialHead);
    int requests[totalRequests];
    printf("Enter the requests: \n");
    for (int i = 0; i < totalRequests; i++)
        scanf("%d", &requests[i]);
    char moveDirection[10];
    printf("Enter the direction: ");
    scanf("%s", moveDirection);
    customSCAN(requests, initialHead, moveDirection, totalTracks, totalRequests);
    printf("\n\n");
    return 0;
}