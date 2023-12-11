#include <stdio.h>

double f(double x)
{
    return 1.0 / (1 + x * x);
}

int main()
{

    float a, b;
    int n;

    float ans = 0;

    printf("Enter the value of a : ");
    scanf("%f", &a);

    printf("Enter the value of b : ");
    scanf("%f", &b);

    printf("Enter the value of n (Number of Intervals) : ");
    scanf("%d", &n);

    float h = (b - a) / n;

    float x[n + 1];
    float y[n + 1];

    for (int i = 0; i <= n; ++i)
    {
        x[i] = a + (i * h);
    }

    for (int i = 0; i <= n; ++i)
    {
        y[i] = f(x[i]);
    }

    float val1 = h / 2;
    float val2 = y[0] + y[n];

    float sum = 0;

    for (int i = 1; i < n; ++i)
    {
        sum += y[i];
    }

    float val3 = 2 * sum;

    ans = val1 * (val2 + val3);
    printf("The Ans is : %lf", ans);

    return 0;
}