#include<stdio.h>
#include<math.h>
int n;

double f(double a[],double arr[n][n+1],int i)
{
    double ans=0;
    for(int j=0;j<n;j++)
    {
        if(i==j)
            continue;
        ans=ans+arr[i][j]*a[j];
    }
    return (arr[i][n]-ans)/arr[i][i];
}

int main()
{
    printf("Enter the number of equations:\n");
    scanf("%d",&n);
    printf("\n\nEnter the augmented matrix row wise:\n");
    double arr[n][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            scanf("%lf",&arr[i][j]);
        }
    }

    double err;
    printf("\nEnter the allowed error:");
    scanf("%lf",&err);

    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            sum+=fabs(arr[i][j]);
        }
        if(fabs(arr[i][i]) <= sum)
        {
            printf("Gauss Seidel cannot be used here");
            return 0;
        }
    }

    printf("\nEnter the initial values:");
    double a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
    }
    printf("\n");

    int k=0;
    char c='x';
    for(int j=0;j<n;j++)
    {
        printf("%c%d = %lf ",c+j,k,a[j]);
    }
    k++;
    printf("\n");

    for(int i=0;i<n;i++)
    {
        double b=a[i];
        a[i]=f(a,arr,i);

        if(fabs(a[i]-b)<=err)
        {
            break;
        }

        if(i==n-1)
        {
            for(int j=0;j<n;j++)
                printf("%c%d = %lf ",(c+j),k,a[j]);
            k++;
            printf("\n");
            i=-1;
        }
    }
    
    for(int j=0;j<n;j++)
    {
        printf("%c%d = %lf ",(c+j),k,a[j]);
    }

    printf("\n");
    printf("\nSolution of the System of Equations:\n");
    for(int i=0;i<n;i++)
    {
        printf("%c =%lf\n",c+i,a[i]);
    }
}