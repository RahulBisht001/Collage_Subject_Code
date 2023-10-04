#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x * x * x) - (5 * x) + 3;
}

float findX(float x1, float x2)
{
    return (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
}

int main()
{
    int maxIterations, i = 1;
    float x1, x2, x;

    float allowed_error = 0.00001;

    printf("Enter max Iterations :");
    scanf("%d", &maxIterations);

    do
    {
        printf("Enter x1 : ");
        scanf("%f", &x1);
        printf("\n");

        printf("Enter x2 : ");
        scanf("%f", &x2);
        printf("\n");

        if (f(x1) * f(x2) > 0)
        {
            printf("Invalid Roots");
            printf("\n");
            continue;
        }
        else
        {
            printf("Root lie btw %f and %f", x1, x2);
            printf("\n");
            break;
        }
    } while (1);

    x = findX(x1, x2);

    do
    {

        x1 = x2;
        x2 = x;

        printf("%d Iteration and x is : %f", i, x);
        x = findX(x1, x2);

        if (fabs(x2 - x) < allowed_error)
        {
            break;
        }
        i++;
    } while (i < maxIterations);

    printf("x is  :%f", x);
}