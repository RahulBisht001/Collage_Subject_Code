// Gauss elimination method

#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter the number of equations: ");
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
            if(i>j)
            {
                double fac=arr[i][j]/arr[j][j]*1.0;
                for(int k=0;k<n+1;k++)
                {
                    arr[i][k]-=arr[j][k]*fac;
                }
            }
        }
    }
    
    printf("\nUpper triangular matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            printf("%.2lf ",arr[i][j]);
        }
        printf("\n");
    }

    double x[n];
    for(int i=n-1;i>=0;i--)
    {
        double ans=arr[i][n];
        for(int j=i+1;j<n;j++)
        {
            ans=ans-(arr[i][j]*x[j]);
        }
        x[i]=ans/arr[i][i];
    }

    printf("Solution of the given set of Equations:\n");
    for(int i=0;i<n;i++){
        printf("x%d=%.2lf\n",i+1,x[i]);
    }
    return 0;
}