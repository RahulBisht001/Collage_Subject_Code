#include <stdio.h>
#include <unistd.h>

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int id = fork();

    if (id == -1)
    {
        perror("Fork failed");
        return 1;
    }
    else if (id == 0)
    {
        // Child process
        int evenCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                evenCount++;
            }
        }
        printf("Child process: Number of even elements in the array is %d\n", evenCount);
    }
    else
    {
        // Parent process
        int oddCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 != 0)
            {
                oddCount++;
            }
        }
        printf("Parent process: Number of odd elements in the array is %d\n", oddCount);
    }

    return 0;
}
