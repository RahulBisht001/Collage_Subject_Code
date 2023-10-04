// To find roots, by Secant method

#include <stdio.h>
#include <math.h>
float f(float x)
{
    return (pow(x,3)-5*x+1);
}
int main()
{
    float x1, x2;
    int flag = 0, iterator = 0;
    float allowed_error, x;
    while(1)
    {
        printf("Enter the value of x1 and x2 : ");
        scanf("%f %f", &x1, &x2);
        if (f(x1) * f(x2) < 0)
        {
            printf("The roots lies between %f and %f\n", x1, x2);
            break;
        }
        else
            printf("Wrong intervals, try again....\n");
    } 
    printf("Enter the allowed error : ");
    scanf("%f", &allowed_error);
    while(1)
    {
        iterator++;
        x = x1 - ((x2 - x1) / (f(x2) - f(x1))) * f(x1);
        printf("%d Iteration, value of x is %f, value of (%f) is %f\n", iterator, x, x, f(x));
        if ((fabs(f(x))) <= allowed_error)
        {
            printf("\nThe final root of the equation is %f after %d iteration", x, iterator);
            break;
        }
        else
        {
            x1 = x2;
            x2 = x;
        }
    } 
    return 0;
}