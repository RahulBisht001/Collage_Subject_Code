#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

bool is_prime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool is_palindrome(int num)
{
    int reversed = 0, original = num;
    while (num > 0)
    {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int id = fork();

    if (id == -1)
    {
        perror("Fork failed");
        return 1;
    }
    else if (id == 0)
    {
        
        if (is_prime(num))
        {
            printf("Child process: %d is a prime number.\n", num);
        }
        else
        {
            printf("Child process: %d is not a prime number.\n", num);
        }
    }
    else
    {
    
        if (is_palindrome(num))
        {
            printf("Parent process: %d is a palindrome number.\n", num);
        }
        else
        {
            printf("Parent process: %d is not a palindrome number.\n", num);
        }

       
    }

    return 0;
}
