#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>

bool isPrime(int num)
{
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool isPalindrome(int num)
{
    int temp = num;
    int rev = 0;

    while (temp != 0)
    {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return num == rev;
}

int main()
{

    int num;
    printf("Enter the Number :");
    scanf("%d", &num);

    printf("\n");

    int x = fork();

    if (x == 0)
    {
        printf("Child Process is Running\n");
        printf("Child Process id : %d\n", getpid());
        printf("Parent Process id : %d\n", getppid());

        isPrime(num) == true
            ? printf("IT is Prime Number\n")
            : printf("Not a Prime Number\n");
    }
    else
    {
        printf("Parent Process is Running\n");
        printf("Child Process id : %d\n", getpid());
        printf("Parent Process id : %d\n", getppid());

        isPalindrome(num) == true
            ? printf("IT is Palindrome Number\n")
            : printf("Not a Palindrome Number\n");
    }

    return 0;
}