/*
 * Simpson's 1/3 Rule
 * Formula is : h/3 *[(y(0) + y(n)) + 4*(y1 + y3 +....) + 2*(y2 + y4 +....)]
 */

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 1.0 / (1 + (x * x));
}

int main()
{
    printf("Hi");
    int n = 0;
    float a = 0, b = 0;
    float sum = 0;
    int position_of_term = 1;

    printf("Enter the value of a : ");
    scanf("%f", &a);

    printf("Enter the value of b : ");
    scanf("%f", &b);

    printf("Enter the value of n (Number of Intervals) : ");
    scanf("%d", &n);

    float h = (b - a) / n;

    for (float i = a + h; i < b; i += h)
    {
        sum += (position_of_term % 2 == 0) ? 2 * f(i) : 4 * f(i);
        position_of_term++;
    }

    sum += f(a) + f(b);
    sum = (h * sum) / 3.0;

    printf("\nValue of the integral = %f\n", sum);

    getchar();
    return 0;
}