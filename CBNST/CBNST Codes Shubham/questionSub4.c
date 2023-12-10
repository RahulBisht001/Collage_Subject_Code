/*
Program - Newton Rapsion Method

Xn+1 = Xn - f(X)/f'(Xn)
X1 = Xo - f(X1)/f'(X1)

for condition f'(x) != 0
if this is zero this method will not proceed
*/

#include <stdio.h>
#include <math.h>
double fx(double x){
    return (x-cos(x));
}

double fdx(double x){
    return (1+sin(x));
}
int main()
{
    double Xo,X1,allowed_error;
    while(1){
        printf("Enter the value of Xo : ");
        scanf("%lf",&Xo);
        if(fdx(Xo) != 0){
            printf("The input value is correct\n");
            break;
        }
        else{
            printf("Wrong value enter again\n");
        }
    }
    printf("Enter the allowed error : ");
    scanf("%lf",&allowed_error);
    int i = 1;
    while(1){
        X1 = Xo - (fx(Xo)/fdx(Xo));
        printf("%d Iteration, value of x is %lf\n",i,X1);
        ++i;
        Xo = X1;
        if(fabs(fx(X1)) <= allowed_error) break;
    }
    printf("The final root is %lf for the equation (x - cos(x))",X1);

    return 0;
}