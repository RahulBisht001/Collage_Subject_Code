/*
simpson's 3/8th code
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("\t Simpson's 3/8th Rule \n");
    printf("Enter the number of observation : ");
    scanf("%d",&n);
    double observation[n][2];
    printf("Enter the observations \n");
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&observation[i][0],&observation[i][1]);
    }
    
    double h = observation[1][0] - observation[0][0], ans = observation[0][1] + observation[n-1][1], mulThree = 0,other = 0;

    //check condition
    int subintervals = (observation[n-1][0] - observation[0][0])/h;
    if(subintervals%3 != 0){
        printf("Simpson's 3/8th can't be used here!");
        return 0;
    }

    for(int i=1;i<n-1;i++){
        if(i%3 == 0)    mulThree += observation[i][1];
        else    other += observation[i][1];
    }
    ans = ans + 3*other + 2*mulThree;

    ans = ans*3*h;
    ans /= 8;

    printf("\nThe solution is %lf",ans);
    return 0;
}