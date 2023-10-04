/**
 * Fixed Point Iteration Implementation
 */

#include <stdio.h>
#include <math.h>
float f(float x)
{
    return x * x * x + x * x - 1;
}

float phiOfX(float x)
{
    return 1 / sqrt(1 + x);
}

float differentiation(float x)
{
    return fabs(-0.5 / pow(1 + x, 1.5));
}
int main()
{
    float x, x1, x2, ans = 0.0001;
    int i, iterations;

    printf("Enter the number of iterations : ");
    scanf("%d", &iterations);
    printf("\n");

    do
    {
        printf("Enter the value of x1\n");
        scanf("%f", &x1);
        printf("\n");

        printf("Enter the value of x2\n");
        scanf("%f", &x2);
        printf("\n");

        if (f(x1) * f(x2) > 0)
        {
            printf("Invalid roots\n");
        }
        else
            break;
    } while (1);

    float x0 = (x1 + x2) / 2;

    if (differentiation(x0) >= 1)
    {
        printf("Differentiate form is incorrect\n");
        return 0;
    }

    for (int i = 1; i <= iterations; i++)
    {
        x = phiOfX(x0);
        if (fabs(x - x0) < ans)
        {
            break;
        }
        printf("%d -> %f", i, x);

        x0 = x;
    }
    printf("\n");
    printf("%f", x);
}