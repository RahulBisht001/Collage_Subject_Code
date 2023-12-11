#include <stdio.h>

double fx(double x, double y)
{
    return (x - y) / (x + y);
}

int main()
{

    double x, y, target, h;

    printf("Enter the initial values of x and y\n");
    scanf("%lf%lf", &x, &y);

    printf("Enter the values of x where we have to calculate y\n");
    scanf("%lf", &target);

    printf("Enter the step size\n");
    scanf("%lf", &h);

    int steps = (target - x) / h;
    for (int i = 0; i < steps; ++i)
    {
        printf("x = %lf  y = %lf\n", x, y);
        y = y + h * fx(x, y);
        x += h;
    }

    printf("Ans is %lf", y);

    return 0;
}