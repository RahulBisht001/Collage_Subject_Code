#include <stdio.h>

#define MAX_PROCESS 10
#define MAX_RESOURCE 10

int main()
{
    int processes, resources;

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    int available[MAX_RESOURCE];
    int max[MAX_PROCESS][MAX_RESOURCE];
    int allocation[MAX_PROCESS][MAX_RESOURCE];
    int need[MAX_PROCESS][MAX_RESOURCE];

    printf("\nEnter the available resources:\n");
    for (int i = 0; i < resources; ++i)
    {
        printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }

    printf("\nEnter the maximum resources required by each process:\n");
    for (int i = 0; i < processes; ++i)
    {
        printf("For Process %d:\n", i + 1);
        for (int j = 0; j < resources; ++j)
        {
            printf("Resource %d: ", j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter the resources currently allocated to each process:\n");
    for (int i = 0; i < processes; ++i)
    {
        printf("For Process %d:\n", i + 1);
        for (int j = 0; j < resources; ++j)
        {
            printf("Resource %d: ", j + 1);
            scanf("%d", &allocation[i][j]);

            // Calculate the need matrix
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Banker's Algorithm
    int work[MAX_RESOURCE];
    int finish[MAX_PROCESS] = {0};
    int safeSequence[MAX_PROCESS];
    int count = 0;

    for (int i = 0; i < resources; ++i)
    {
        work[i] = available[i];
    }

    // Find a safe sequence
    while (count < processes)
    {
        int found = 0;

        for (int i = 0; i < processes; ++i)
        {
            if (finish[i] == 0)
            {
                int j;
                for (j = 0; j < resources; ++j)
                {
                    if (need[i][j] > work[j])
                    {
                        break;
                    }
                }

                if (j == resources)
                {
                    // Process i can finish
                    for (int k = 0; k < resources; ++k)
                    {
                        work[k] += allocation[i][k];
                    }

                    safeSequence[count++] = i + 1;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
        {
            printf("\nUnsafe State! System is in deadlock.\n");
            return 0;
        }
    }

    // Print the safe sequence
    printf("\nSafe Sequence: ");
    for (int i = 0; i < processes; ++i)
    {
        printf("P%d", safeSequence[i]);
        if (i < processes - 1)
        {
            printf(" -> ");
        }
    }

    printf("\n");

    return 0;
}
