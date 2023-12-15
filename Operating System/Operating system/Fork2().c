#include <stdio.h>
#include <unistd.h>
void main()
{
   int n;
   printf("Enter the number of elements in the array:-");
   scanf("%d", &n);
   int a[n];
   printf("Enter the elements of the array:-");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &a[i]);
   }
   int count = 0;
   int count1 = 0;
   int id = fork();
   if (id == 0)
   {
      for (int i = 0; i < n; i++)
      {
         if (a[i] % 2 == 0)
         {
            count++;
         }
      }
   }
   else
   {
      for (int i = 0; i < n; i++)
      {
         if (a[i] % 2 != 0)
         {
            count1++;
         }
      }
   }

   if (id == 0)
   {
      printf("This is the child process\n");
      printf("child process id is %d\n", getpid());
      printf("parent process id is %d\n", getppid());

      printf("The number of even numbers in the array is %d\n", count);
      printf("Child process is terminated\n  ");
   }
   else
   {
      printf("This is the parent process\n");
      printf("parent process id is %d\n", getpid());
      printf("child process id is %d\n", id);
      printf("The number of odd numbers in the array is %d\n", count1);
      printf("Parent process is terminated\n");
   }
}