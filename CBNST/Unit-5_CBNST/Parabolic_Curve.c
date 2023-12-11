#include <stdio.h>

void parabolicFit(int n, double x[], double y[])
{
    double sumX = 0.0, sumX2 = 0.0, sumX3 = 0.0, sumX4 = 0.0;
    double sumY = 0.0;
    double sumXY = 0.0, sumX2Y = 0.0;

    for (int i = 0; i < n; ++i)
    {
        double x2 = x[i] * x[i];

        sumX += x[i];
        sumY += y[i];
        sumX2 += x2;
        sumX3 += x2 * x[i];
        sumX4 += x2 * x2;
        sumXY += x[i] * y[i];
        sumX2Y += x2 * y[i];
    }

    double a = (sumX2Y * (sumX2 * sumX2 - sumX * sumX3) + sumXY * (sumX * sumX4 - sumX2 * sumX3) - sumY * (sumX * sumX4 - sumX2 * sumX3)) / (sumX2 * (sumX2 * sumX2 - sumX * sumX3) + sumX * (sumX * sumX4 - sumX2 * sumX3) + n * (sumX4 * sumX - sumX2 * sumX2));

    double b = (sumXY - a * sumX2 - sumY) / (sumX);
    double c = (sumY - a * sumX2 - b * sumX) / n;

    printf("Parabolic Equation: y = %.4fx^2 + %.4fx + %.4f\n", a, b, c);
}

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the data points (x y):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    parabolicFit(n, x, y);

    return 0;
}
