
#include <stdio.h>
#include <math.h>
double f(double x)
{
    return 3 * x - cos(x) - 1;
    // return (pow(x, 3) - 5 * x + 1);
}
double fdx(double x)
{
    return 3 + sin(x);
}

int main()
{

    float allowed_error = 0.00001;
    int max_Iteration = 0, i = 1;

    float X0, X1;

    do
    {
        printf("Enter the value of X0 : ");
        scanf("%f", &X0);

        if (fdx(X0) != 0)
        {
            printf("The input value is correct\n");
            break;
        }
        else
        {
            printf("Wrong value enter again\n");
        }
    } while (1);

    do
    {
        X1 = X0 - (f(X0) / fdx(X0));
        printf("%d Iteration, value of x is %lf\n", i, X1);

        X0 = X1;

        if (fabs(f(X1)) <= allowed_error)
        {
            break;
        }
        printf("The final root is %lf for the equation (x^3 - 5*x + 1)", X1);
        i++;
    } while (i < max_Iteration);
}