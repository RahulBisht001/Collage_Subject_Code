/*
Newton forward interpolation formula
1> number of observations.
2> Enter the value of x.
3> Enter the value of fx = y
4> create newton forward difference table
5> print forward difference table
6> apply newton's forward interpolation formula
*/

#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter the number of observation : ");
    scanf("%d",&n);
    double observation[n][n+1];
    printf("Enter the observations \n");
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&observation[i][0],&observation[i][1]);
    }

    for(int j=2;j<n+1;j++){
        for(int i=0;i<=n-2;i++){
            observation[i][j] = observation[i+1][j-1]-observation[i][j-1];
        }
    }

    printf("\t Difference Table\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1-i;j++)  printf("%.2lf ",observation[i][j]);
        printf("\n");
    }
    
    int x;
    printf("Enter the value of x : ");
    scanf("%d",&x);
    double p = (x-observation[0][0])/(observation[1][0]-observation[0][0]);

    int fac = 1;
    double ans = observation[0][1];
    for(int j=2;j<n+1;j++){
        double temp = p;
        temp *= observation[0][j];
        for(int i=1;i<j-1;i++){
            temp*=(p-i);
        }
        temp /= (double)fac;
        ans += temp;
        fac*=j;
    }

    printf("The final solution of x is %lf",ans);
    return 0;
}