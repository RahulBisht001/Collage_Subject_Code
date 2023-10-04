/**
 * Implement Secant Method
 */

#include <stdio.h>
#include <math.h>

float f(float x)
{
    // return x * x * x - 5 * x + 1;
    return (cos(x) - x * exp(x));
}

float findX(float x1, float x2)
{
    return (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
}

int main()
{
    int max_iterations, i = 1;
    float x1, x2, x;

    float allowed_error = 0.00001;

    printf("Enter the Number of Iterations : ");
    scanf("%d", &max_iterations);
    printf("\n");

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
            printf("Invalid Interval");
            printf("\n");
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
        printf("Iterations=%d  Root=%f\n", i, x);

        x = findX(x1, x2);
        if (fabs(x - x2) < allowed_error)
        {
            printf("Final Root=%f  Total Iterations=%d", x, i + 1);
            printf("\n");
            break;
        }
        i++;
    } while (i <= max_iterations);

    printf("%f", x);
}

/**
#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001 // to find answers till 4 correct decimal places

float f(float x)
{
    return x * x * x - 5 * x + 1;
    // return cos(x)+2*sin(x)+x*x; transcendental Equation
}

float findX(float x1, float x2)
{
    return (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
}
int main()
{
    int max_iterations, i = 1;
    float x1, x2, x;

    printf("Enter the Number of Iterations : ");
    scanf("%d", &max_iterations);
    printf("\n");

    printf("Enter the value of x1 : ");
    scanf("%f", &x1);
    printf("\n");

    printf("Enter the value of x2 : ");
    scanf("%f", &x2);
    printf("\n");

    x = findX(x1, x2);
    do
    {
        x1 = x2;
        x2 = x;
        printf("Iterations=%d  Root=%f\n", i, x);

        x = findX(x1, x2);

        if (fabs(x - x2) < EPSILON)
        {
            printf("Final Root=%f  Total Iterations=%d", x, i + 1);
            return 0;
        }
        i++;
    } while (i <= max_iterations);

    printf("Final Root=%f", x);

    return 0;
}
*/