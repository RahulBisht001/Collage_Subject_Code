/*
 * Simpson's 1/3 Rule
 * Formula is :
 */

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 1.0 / (1 + (x * x));
}

int main()
{

    printf("Hi");
    int n, position_of_term = 1;
    float a, b;
    float sum = 0;

    printf("Enter the value of a : ");
    scanf("%f", &a);

    printf("Enter the value of b : ");
    scanf("%f", &b);

    printf("Enter the value of n (Number of Intervals) : ");
    scanf("%d", &n);

    float h = (b - a) / n;

    for (int i = a + h; i < b; i += h)
    {
        sum += (position_of_term % 2 == 0) ? 2 * f(i) : 4 * f(i);
        position_of_term++;
    }

    sum += f(a) + f(b);
    sum = (h * sum) / 3.0;

    printf("\nValue of the integral = %f\n", sum);

    return 0;
}