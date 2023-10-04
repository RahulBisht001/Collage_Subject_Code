#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 3 * x - cos(x) - 1;
}

double fdx(double x)
{
    return 3 + sin(x);
}

int main()
{

    double x0, x1;
    double allowed_error = 0.00001;

    int maxIteration, i = 1;

    do
    {
        printf("Enter the value of x0 :");
        scanf("%lf", &x0);

        if (fdx(x0) != 0)
        {
            printf("This is correct value and we are proceeding");
            break;
        }
        else
        {
            printf("Wrong value");
        }
    } while (1);

    do
    {
        x1 = x0 - (f(x0) / fdx(x0));
        printf("%d iteration and x is %lf\n", i, x1);

        x0 = x1;
        if (fabs(f(x1)) <= allowed_error)
        {
            break;
        }
        i++;
    } while (i < maxIteration);
    printf("the root is : %lf", x1);
}
