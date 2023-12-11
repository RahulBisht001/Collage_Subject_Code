
#include <stdio.h>

double fx(double x, double y)
{

    return (x - y) / (x + y);
}

double rungeKutta(double x, double y, double h)
{

    double k1, k2, k3, k4;

    k1 = h * fx(x, y);
    k2 = h * fx(x + h / 2.0, y + k1 / 2.0);
    k3 = h * fx(x + h / 2.0, y + k2 / 2.0);
    k4 = h * fx(x + h, y + k3);

    double ans = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;

    return ans;
}

int main()
{

    double x, y, h, target;
    printf("Enter the value of x & y respectively \n");
    scanf("%lf%lf", &x, &y);

    printf("Enter the value of x where we have to calculate y\n");
    scanf("%lf", &target);

    printf("Enter the step size: ");
    scanf("%lf", &h);

    int steps = (target - x) / h;

    for (int i = 0; i < steps; ++i)
    {
        printf("x = %f  y = %f", x, y);
        y = rungeKutta(x, y, h);
        x += h;
    }

    printf("-------------------");
    printf("y(%lf) = %lf\n", target, y);

    return 0;
}