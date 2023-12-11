#include <stdio.h>
#include <math.h>

double f(double x)
{
    // return (cos(x) - x * exp(x));
    return (x * x * x) - 5 * x + 3;
}

double findX(float x1, float x2)
{
    return (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
}

int main()
{

    int max_iterations = 0, i = 1;
    printf("Enter Number of Iteration : ");
    scanf("%d", &max_iterations);

    float allowed_error = 0.00001;

    float x1, x2, x;

    do
    {
        printf("Enter the value of x1 : ");
        scanf("%f", &x1);
        printf("\n");

        printf("Enter the value of x2 : ");
        scanf("%f", &x2);
        printf("\n");

        if (f(x1) * f(x2) > 0)
        {
            printf("Invalid Roots");
            continue;
        }
        else
        {
            printf("Root lie's between %f and %f", x1, x2);
            printf("\n");
            break;
        }

    } while (1);

    x = findX(x1, x2);

    do
    {
        x1 = x2;
        x2 = x;

        x = findX(x1, x2);
        printf("Iterations=%d  Root=%f\n", i, x);

        if (fabs(x - x2) < allowed_error)
        {

            printf("Final Root=%f  Total Iterations=%d", x, i + 1);
            printf("\n");
            break;
        }

        i++;
    } while (i < max_iterations);

    return 0;
}