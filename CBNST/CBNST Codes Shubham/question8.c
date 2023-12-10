//Gauss jordan method
/*

*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter the number of equations:\n");
    scanf("%d",&n);
    printf("Enter the augmented matrix row-wise:\n");
    double arr[n][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            scanf("%lf",&arr[i][j]);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                double fac=arr[j][i]/arr[i][i];
                for(int k=0;k<n+1;k++)  arr[j][k]-=arr[i][k]*fac;
            }
        }
    }

    printf("\nDiagonal triangular matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++) 
        {
            printf("%.2lf ",arr[i][j]);
        }
        printf("\n");
    }

    double x[n];
    printf("Solution of the given system of Equations:\n");
    for(int i=0;i<n;i++){
        x[i]=arr[i][n]/arr[i][i];
        printf("x%d=%.2lf\n",i+1,x[i]);
    }
    
    return 0;
}