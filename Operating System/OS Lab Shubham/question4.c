#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
//Create two child and parent process and use sleep function.
/* if the parent process is terminated first and child is still existing with the help of sleep function then that child process is called 'orphan process' cause it will have no parent.*/

int main(){
    int x = fork();
    if(x){
    	printf("Parent process is started\n");
    	printf("Parent process is terminated\n");
    }
    else{
    	printf("Child process is started\n");
    	sleep(2);
    	printf("Orphan process\n");
    	printf("Child process is terminated\n");
	getchar();
    }
    
    return 0;
}
