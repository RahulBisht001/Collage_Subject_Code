/*program 2 : Regula falsi method
1> Take two initial values Xo & X1 such that f(Xo)*f(X1) < 0
2> Bisect [Xo, X1] into two halves [Xo,X] & [X,X1] 
                            where X = Xo - (X1 - Xo)/f(X1)-f(Xo) * f(Xo)
3> If f(Xo)*f(X) < 0, set X1 = X, go to step 2
   else f(X)*f(X1) < 0, set Xo = X, go to step 2
4> To stop the proceduce on the basis of iterations or given specified/allowed error f(X) <= allowed error
 f(x) = x^3 - 5*x + 1 = 0
*/

#include <stdio.h>
#include <math.h>
double functionValue(double x){
    return (x - cos(x));
}
int main()
{
    double Xo, X1;
    while(1){
        printf("Enter the value of Xo and X1 : ");
        scanf("%lf %lf",&Xo,&X1);
        if(functionValue(Xo)*functionValue(X1) < 0){
            printf("The root lies between %lf and %lf\n",Xo, X1);
            break;
        }
        else{
            printf("Wrong range enter again\n");
        }
    }
    double allowed_error;
    printf("Enter the allowed error : ");
    scanf("%lf",&allowed_error);
    double x;
    int i = 1;
    while(1){
        x = Xo - ((X1 - Xo)/(functionValue(X1)-functionValue(Xo)))*functionValue(Xo);
        double fx = functionValue(x);
        printf("%d Iteration, value of x is %lf, value of f(x) is %lf\n",i,x,fx);
        ++i;
        if((functionValue(Xo)*fx) < 0) X1 = x;
        else Xo = x;
        if(fabs(fx) <= allowed_error) break;
    }
    printf("The final root is %lf for the equation (x-cos(x))",x);

    return 0;
}