#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
//Create two child and parent process and use sleep function.
/* if the child process is terminated first and parent is still existing with the help of sleep function then there still exist a instance
of it but the process is terminated so that child process is called as zombie process.*/

int main(){
    int x = fork();
    if(x){
    	printf("Parent process is started\n");
    	sleep(2);
    	printf("Parent process is terminated\n");
    }
    else{
    	printf("Child process is started\n");
    	printf("Zombie process\n");
    	printf("Child process is terminated\n");
	getchar();
    }
    
    return 0;
}
