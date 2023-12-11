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

    int x, x1, x2;
    int max_Iterations = 0, i = 1;

    float allowed_error = 0.00001;

    printf("Enter the number of iterations : ");
    scanf("%d", &max_Iterations);
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
            printf("Invalid Roots");
            continue;
        }
        else
        {
            break;
        }
    } while (1);

    float x0 = (x1 + x2) / 2;
    if (differentiation(x0) >= 1)
    {
        printf("Differentiate form is incorrect\n");
        return 0;
    }

    do
    {
        x = phiOfX(x0);

        if (fabs(x - x0) < allowed_error)
        {
            break;
        }
        printf("%d -> %f", i, x);

        x0 = x;

        i++;
    } while (i < max_Iterations);

    printf("\n");
    printf("%f", x);
}