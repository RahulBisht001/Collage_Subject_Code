
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * x * x - 4 * x - 9;
}

int main()
{

    int numberOfIterations, i = 0;

    printf("Enter Number of Iterations");
    scanf("%d", &numberOfIterations);

    float allowed_Error = 0.00001;

    float x1, x2, x;

    do
    {
        printf("Enter the value of x1");
        scanf("%f", &x1);
        printf("\n");

        printf("Enter the value of x2");
        scanf("%f", &x2);
        printf("\n");

        if (f(x1) * f(x2) > 0)
        {
            printf("Invalid Range");
            printf("\n");
            continue;
        }
        else
        {
            printf("Range is %f and %f", x1, x2);
            printf("\n");
            break;
        }

    } while (1);

    x = (x1 + x2) / 2;

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

        float x3 = x;
        x = (x1 + x2) / 2;

        if (fabs(x3 - x) < allowed_Error)
        {
            break;
        }

        i++;
    } while (i < numberOfIterations);

    printf("%f", x);
}