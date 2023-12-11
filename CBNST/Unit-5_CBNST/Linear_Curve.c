/*
 * Linear Curve Fitting
 * Formula is :
 */

#include <stdio.h>
#include <math.h>

void linearFit(int n, double x[], double y[])
{
    double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;

    for (int i = 0; i < n; ++i)
    {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double b = (sumY - m * sumX) / n;

    printf("Linear Fit curve y = %0.4f * x + %0.4f", m, b);
}

int main()
{
    int n = 0;
    printf("Enter the number of data points : ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the data points (x y):\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    linearFit(n, x, y);

    return 0;
}