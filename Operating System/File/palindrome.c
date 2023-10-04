#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int val)
{
    for (int i = 2; i*i <= val; i++)
        if (val % i == 0)
            return false;
    return true;
}

bool isPalindrome(int val)
{
    int sum = 0;
    int temp = val;
    while (val > 0)
    {
        int rem = val % 10;
        sum = sum * 10 + rem;
        val /= 10;
    }
    if (sum == temp)
        return true;
    return false;
}
int main()
{
    int n;
    printf("Enter A Number: ");
    scanf("%d", &n);
    printf("\n\n");

    int x = fork();
    if (x == 0)
    {
        printf("Child Process is running\n");
        printf("Child Process id: %d\n", getpid());
        printf("Parent Process id: %d\n", getppid());

        if (isPrime(n))
            printf("%d is prime\n", n);
        printf("Child Process completed\n\n");
    }
    else
    {
        printf("Parent Process is Running\n");
        printf("Parent id: %d \n", getpid());
        if (isPalindrome(n))
            printf("%d is Palindrome\n", n);
        printf("Parent Process completed\n\n");
    }
    return 0;
}
