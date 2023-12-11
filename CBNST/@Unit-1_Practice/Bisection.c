#include <stdio.h>
#include <math.h>

double f(double x)
{
    // return x * x * x - x - 4;
    return x * x * x - 4 * x - 9; //^ range is 2 and 3
    //* Book : Page Number 68
}

int main()
{

    float x1 = 0, x2 = 0, x = 0;
    int num_of_iterations = 0;
    float allowed_error = 0.00001;

    printf("Enter Number of Iterations : ");
    scanf("%d", &num_of_iterations);

    do
    {
        printf("Enter the value of x1 : ");
        scanf("%f", &x1);

        printf("Enter the value of x2 : ");
        scanf("%f", &x2);

        if (f(x1) * f(x2) > 0)
        {
            printf("Invalid Roots");
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
    int i = 0;

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

        if (fabs(x3 - x) < allowed_error)
        {
            break;
        }
        i++;
    } while (i <= num_of_iterations);

    printf("Root upto given accuracy is %f:", x);

    return 0;
}