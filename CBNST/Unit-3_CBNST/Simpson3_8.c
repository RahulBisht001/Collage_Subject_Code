/*
 * Simpson's 3/8 Rule
 *
 */

// Write a program in “C” Language to integrate numerically using Simpson’s 3/8 Rule.

#include <stdio.h>

float value(float x)
{
    return 1 / (1 + x * x);
}

int main()
{
    int n, position_of_term = 1;
    float a, b, sum = 0, h;

    printf("Enter the value of a and b : ");
    scanf("%f %f", &a, &b);

    printf("Enter the number of intervals : ");
    scanf("%d", &n);

    h = (b - a) / n;
    sum = value(a) + value(b);

    for (int i = a + h; i < b; i += h)
    {
        sum += (position_of_term % 3 == 0) ? 2 * value(i) : 3 * value(i);
        position_of_term++;
    }

    sum = (h * sum * 3) / 8;

    printf("\nValue of the integral = %f\n", sum);

    return 0;
}

//* *******************************************************************************************

#include <stdio.h>

float f(float x)
{
    return 1.0 / (1 + (x * x));
}

int main()
{
    int n, position_of_term = 1;
    float a, b;
    float sum = 0;

    printf("Enter the value of a: ");
    scanf("%f", &a);

    printf("Enter the value of b: ");
    scanf("%f", &b);

    printf("Enter the value of n (Number of Intervals): ");
    scanf("%d", &n);

    float h = (b - a) / n;

    sum += f(a) + f(b);

    for (int i = a + h; i < b; i += h)
    {
        sum += (position_of_term % 3 == 0) ? 2 * f(i) : 3 * f(i);
        position_of_term++;
    }

    sum = (h * sum * 3) / 8;

    printf("\nValue of the integral = %f\n", sum);

    return 0;
}