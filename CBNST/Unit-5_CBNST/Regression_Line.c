#include <stdio.h>

void linearRegression(int n, double x[], double y[])
{
    double sumX = 0.0, sumY = 0.0, sumX2 = 0.0, sumY2 = 0.0, sumXY = 0.0;

    for (int i = 0; i < n; ++i)
    {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }

    double m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double b = (sumY - m * sumX) / n;

    printf("Regression Line (Y on X): Y = %.4fX + %.4f\n", m, b);

    m = (n * sumXY - sumX * sumY) / (n * sumY2 - sumY * sumY);
    b = (sumX - m * sumY) / n;

    printf("Regression Line (X on Y): X = %.4fY + %.4f\n", m, b);
}

int main()
{
    int n;
    printf("Enter the number of data points \n");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the data points (X Y):\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    linearRegression(n, x, y);
    return 0;
}