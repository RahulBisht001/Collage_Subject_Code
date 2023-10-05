#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

//Parent will check for palindrome and child will check for prime number
//parent will give 1 as return value and child will give 0 as return value

int reverseNum(int num){
    int temp = num;
    int rev = 0;
    while(temp != 0){
        rev = rev*10 + temp%10;
        temp = temp/10;
    }
    return rev;
}
int main()
{
    int x = fork();
    int num;
    printf("Enter a numbers : ");
    scanf("%d", &num);
    if(x){
        int temp = reverseNum(num);
        if(temp == num) printf("The number is a palindrome %d process\n",getpid());
        else    printf("The number is not a palindrome %d process\n",getpid());
    }
    else{
        int flag=0;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i == 0){
                printf("The number is not a prime number %d process\n",getpid());
                flag++;
            }
        }
        if(!flag)   printf("The number is a prime number %d process\n",getpid());
    }
    return 0;
}