// To find roots, by Bisection method
#include <stdio.h>
#include <math.h>
float f(float x)
{
    return (pow(x, 3) - 5 * x + 1);
}
int main()
{
    float x1, x2;
    int flag = 0, iterator = 0;
    float allowed_error, x;
    do
    {
        printf("Enter the value of x1 and x2 : ");
        scanf("%f %f", &x1, &x2);
        if (f(x1) * f(x2) < 0)
        {
            flag = 1;
            printf("\n The roots lies between %f and %f", x1, x2);
        }
        else
            printf("Wrong intervals, try again....\n");
    } while (flag != 1);
    printf("Enter the allowed error : ");
    scanf("%f", &allowed_error);
    do
    {
        iterator++;
        x = (x1 + x2) / 2;
        printf("\n %d Iteration, value of x is %f, value of (%f) is %f", iterator, x, x, f(x));
        if ((fabs(f(x))) <= allowed_error)
        {
            flag = 0;
            printf("\n The root of the equation is %f after %d iteration\n", x, iterator);
        }
        else if (f(x) * f(x1) < 0)
            x2 = x;
        else
            x1 = x;
    } while (flag != 0);
    printf("....................................");
    return 0;
}