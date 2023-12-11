#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the Number of Observations : ");
    scanf("%d", &n);

    double observation[n][n + 1];
    printf("Enter the Observations x  and  y\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %lf", &observation[i][0], &observation[i][1]);
    }

    //^______ calculate the values in the table _______

    for (int j = 2; j < n + 1; ++j)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            observation[i][j] = observation[i + 1][j - 1] - observation[i][j - 1];
        }
    }

    printf("Newton Forward Difference Table \n");

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1 - i; ++j)
        {
            printf("%0.2f\t", observation[i][j]);
        }
        printf("\n");
    }

    float x;
    printf("Enter the value of X : ");
    scanf("%f", &x);

    double p = (x - observation[0][0]) / (observation[1][0] - observation[0][0]);

    int fac = 1;
    float ans = observation[0][1];

    for (int j = 2; j < n + 1; ++j)
    {
        float temp = p;
        temp *= observation[0][j];

        for (int i = 1; i < j - 1; ++i)
        {
            temp *= (p - i);
        }

        temp /= (double)fac;
        ans += temp;

        fac *= j;
    }

    printf("The final solution of x is %f", ans);
    return 0;
}