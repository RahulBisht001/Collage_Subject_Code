#include <stdio.h>
#include <math.h>
double fx(double x,double y){
    return (y-x)/(y+x);
}
int main()
{
    double x, y, target, h;
    printf("Enter the intial values of x and y respectively : ");
    scanf("%lf %lf",&x,&y);
    printf("Enter the value of x where we have to calculate y : ");
    scanf("%lf",&target);
    printf("Enter the step size : ");
    scanf("%lf",&h);
    int steps = (target-x)/h;

    for(int i=0;i<steps;i++){
        y = y + h*fx(x,y);
        x += h;
    }
    printf("%lf",y);
    return 0;
}