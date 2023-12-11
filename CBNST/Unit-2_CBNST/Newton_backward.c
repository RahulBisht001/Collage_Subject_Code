#include <stdio.h>
#include <math.h>

int main()
{

    int n;
    printf("Enter the Number of Observations : ");
    scanf("%d", &n);

    double observation[n][n + 1];

    printf("Enter the Observations X and Y \n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %lf", &observation[i][0], &observation[i][1]);
    }

    //^ Calculate the Difference Table
    for (int j = 2; j < n + 1; ++j)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            observation[i][j] = observation[i + 1][j - 1] - observation[i][j - 1];
        }
    }

    printf("Newton Backward difference Table\n");

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1 - i; ++j)
        {
            printf("%0.2lf\t", observation[i][j]);
        }
        printf("\n");
    }

    float x;
    printf("Enter the value of X : ");
    scanf("%f", &x);

    double p = (x - observation[n - 1][0]) / (observation[1][0] - observation[0][0]);
    int fac = 1;

    double ans = observation[n - 1][1];

    for (int j = 2; j < n + 1; ++j)
    {
        float temp = p;
        temp *= observation[n - j][j];

        for (int i = 1; i < j - 1; ++i)
        {
            temp *= (p + i);
        }
        temp /= (double)fac;
        ans += temp;

        fac *= j;
    }
    // 0.00 1.00 1.00 - 2.00 12.00 1.00 2.00 - 1.00 10.00 2.00 1.00 9.00 3.00 10.00

    printf("\nThe final solution of x by using newton backward interpolation is %lf", ans);
    return 0;
}