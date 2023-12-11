/*
 * Trapezoidal Method
 * The Formula is
 * ans = h/2 * [(y0 + yn) + 2 * (y(1)....y(n-1))]
 */

/*
^ If we are given with the function only
^ we have to calculate the values of y = f(x)
^ manually.
*/

#include <stdio.h>
#include <math.h>

float f(float x)
{
    //^ This is the Given function
    return 1.0 / (1 + (x * x));
}

int main()
{
    float a, b;
    int n;
    float ans;

    printf("Enter the value of a : ");
    scanf("%f", &a);

    printf("Enter the value of b : ");
    scanf("%f", &b);

    printf("Enter the value of n (Number of Intervals) : ");
    scanf("%d", &n);

    //^ Calculate the value of h
    float h = (b - a) / n;

    float x[n + 1];
    float y[n + 1];

    for (int i = 0; i <= n; ++i)
    {
        x[i] = a + i * h;
    }

    for (int i = 0; i <= n; ++i)
    {
        y[i] = f(x[i]);
    }

    // formula is h/2 * [(y0 + yn) + 2 * (y1....yn)]

    float val1 = h / 2;
    float val2 = y[0] + y[n];

    float sum = 0;
    for (int i = 1; i < n; ++i)
    {
        sum += y[i];
    }

    float val3 = sum * 2;

    ans = val1 * (val2 + val3);

    printf("The Ans is : %lf", ans);
}

// ! _______________________________________________________________________________________________
// ! -----------------------------------------------------------------------------------------------

/*
 * This is the Second case where the Observations are given
 * you just need to use them and put the values in the
 * formula  h/2 * [(y0 + yn) + 2 * (y1....yn)]
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