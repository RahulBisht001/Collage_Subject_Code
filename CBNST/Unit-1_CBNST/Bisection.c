/**
 * Implement Bisection Method
 */

#include <stdio.h>
#include <math.h>

float f(float x)
{
    // return x * x * x - x - 4;
    return x * x * x - 4 * x - 9; //^ range is 2 and 3
    //* Book : Page Number 68
}

int main()
{
    int num_of_iterations, i = 0;
    float x1, x2, x;
    float allowed_error = 0.00001;

    printf("Enter the Number of Iterations : ");
    scanf("%d", &num_of_iterations);

    do
    {
        printf("Enter the Root 1: ");
        scanf("%f", &x1);
        printf("\n");

        printf("Enter the Root 2: ");
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
            printf("Root lies btw %f and %f", x1, x2);
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
        //* now one of the values from the x1 or x2 is changes
        x = (x1 + x2) / 2;

        if (fabs(x3 - x) < allowed_error)
        {
            break;
        }

    } while (i <= num_of_iterations);

    printf("Root upto given accuracy is %f:", x);
}
