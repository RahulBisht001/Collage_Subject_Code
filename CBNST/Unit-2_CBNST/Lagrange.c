#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the Number of Observations : ");
    scanf("%d", &n);

    double observation[n][2];

    printf("Enter the observations \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &observation[i][0], &observation[i][1]);
    }

    int x;
    printf("Enter the value of x : ");
    scanf("%d", &x);

    double ans = 0.0;

    for (int i = 0; i < n; ++i)
    {
        double numerator = 1;
        double denominator = 1;

        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            else
            {
                numerator *= (x - observation[j][0]);
                denominator *= (observation[i][0] - observation[j][0]);
            }
        }
        ans += (numerator / denominator) * observation[i][1];
    }

    printf("\nThe final solution of x by using lagrange interpolating polynomial is %lf", ans);
    return 0;
}