/* Iteration method */
#include <stdio.h>
#include <math.h>
double px(double x)
{
    return (cos(x) + 1) * (1 / 3.0);
}
double fx(double x)
{
    return (cos(x) - 3 * x + 1);
}
double pdx(double x)
{
    return -(sin(x) / 3);
}
int main()
{
    double Xo, X1, allowed_error;

    printf("Enter the value of Xo : ");
    scanf("%lf", &Xo);
    if (fabs(pdx(Xo)) >= 1)
    {
        printf("Wrong function change the function and run the code again\n");
        return 0;
    }
    else
    {
        printf("The input value is correct\n");
    }

    printf("Enter the allowed error : ");
    scanf("%lf", &allowed_error);
    int i = 1;
    while (1)
    {
        X1 = px(Xo);
        printf("%d Iteration, value of x is %lf\n", i, X1);
        ++i;
        if (fabs(fx(X1)) <= allowed_error)
            break;
        Xo = X1;
    }
    printf("The final root is %lf for the equation (cos(x) - 3*x + 1)", X1);

    return 0;
}