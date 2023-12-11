#include <stdio.h>

double f(double x)
{
    return 1.0 / (1 + x * x);
}

int main()
{
    float a, b;
    int n;
    int position_of_term = 1;
    float sum = 0;

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

    printf("The Ans is : %lf", sum);

    return 0;
}