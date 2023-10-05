#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Parent will get the sum of even and child will get the sum of odd
//parent will give 1 as return value and child will give 0 as return value

int main()
{
    int x = fork();
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array : ");
    for(int i=0;i<n;i++)    scanf("%d", &arr[i]);
    if(!x){
        int evenSum = 0;
        for(int i=0;i<n;i++){
            if(arr[i]%2 == 0)   evenSum += arr[i];
        }
        printf("The sum of even numbers is %d process\n",getpid());
    }
    else{
        int oddSum = 0;
        for(int i=0;i<n;i++){
            if(arr[i]%2 != 0)   oddSum += arr[i];
        }
        printf("The sum of odd numbers is %d process\n",getpid());
    }
    return 0;
}