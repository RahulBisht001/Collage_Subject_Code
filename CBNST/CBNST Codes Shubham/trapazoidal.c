/*
 * Trapezoidal Method
 */

#include <stdio.h>
#include <math.h>
int main()
{
    printf("\t Trapezoidal Rule \n");
    double ans = 0;

    int n;
    printf("Enter the number of observation : ");
    scanf("%d", &n);

    double observation[n][2];

    printf("Enter the observations \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &observation[i][0], &observation[i][1]);
    }

    double h = observation[1][0] - observation[0][0];

    for (int i = 1; i < n - 1; i++)
        ans += observation[i][1];
    ans *= 2;

    ans += observation[0][1] + observation[n - 1][1];
    ans *= h;
    ans /= 2;

    printf("\nThe solution is %lf", ans);
    return 0;
}