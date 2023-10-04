#include <stdio.h>
#include <unistd.h>

int main()
{
    int n;
    printf("Enter total number of elements in the Array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the Array\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int evenCount = 0, oddCount = 0;
    int x = fork();

    printf("\n");

    if (x == 0){
        printf("Child Process is running\n\n");

        printf("Child Process id: %d\n", getpid());
        printf("Parent Process id: %d\n", getppid());

        for (int i = 0; i < n; i++)
            if (arr[i] % 2 == 0)
                evenCount++;
        printf("Even Count : %d \n", evenCount);
        printf("Child Process completed\n\n");
    }
    else{

        printf("Parent Process is Running\n");
        printf("Parent ID: %d \n", getpid());

        for (int i = 0; i < n; i++)
            if (arr[i] % 2 == 1)
                oddCount++;
        printf("Odd Count : %d\n", oddCount);
        printf("Parent Process completed\n\n");
    }
    return 0;
}