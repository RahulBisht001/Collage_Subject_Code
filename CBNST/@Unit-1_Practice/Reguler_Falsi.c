#include <stdio.h>
#include <math.h>

double f(double x)
{

    // return x * x * x - 2 * x - 5;
    // return (x * x * x * x * x * x) - (x * x * x * x) - (x * x * x) - 1;
    return (x * x * x) - 5 * x + 3;
    //* Book : Page Number 98 ,99, 100
}

double findX(float x1, float x2)
{
    return (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
}

int main()
{

    int max_iterations = 0, i = 1;
    float x1, x2, x;

    printf("Enter the Number of Iterations : ");
    scanf("%d", &max_iterations);
    printf("\n");

    float allowed_error = 0.00001;

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

        if (f(x) * f(x1) < 0)
        {
            x2 = x;
        }
        else if (f(x) * f(x2) < 0)
        {
            x1 = x;
        }

        printf("%d iteration -> %f\n", i, x);

        float x3 = x;
        x = findX(x1, x2);

        if (fabs(x3 - x) < allowed_error)
        {
            break;
        }

        i++;

    } while (i < max_iterations);

    printf("The Root with Given error is %f", x);

    return 0;
}