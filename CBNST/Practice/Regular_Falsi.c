#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x * x * x) - 5 * x + 3;
}

float findX(float x1, float x2)
{
    return (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
}

int main()
{
    int maxIterations, i = 0;

    printf("Enter Max Iterations: ");
    scanf("%d", &maxIterations);

    float allowed_Error = 0.00001;
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
            printf("Invalid Input");
            printf("\n");
            continue;
        }
        else
        {
            printf("Root lie btw %f and %f", x1, x2);
            printf("\n");
            break;
            ;
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

        printf("%d iteration  and x is : %f\n", i, x);

        float x3 = x;
        x = findX(x1, x2);

        if (fabs(x3 - x) < allowed_Error)
        {
            break;
        }
        i++;
    } while (i < maxIterations);

    printf("Root is %f ", x);
}