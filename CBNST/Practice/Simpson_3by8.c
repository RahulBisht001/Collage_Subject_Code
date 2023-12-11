#include <stdio.h>

double f(double x)
{

    return 1.0 / (1 + x * x);
}

int main()
{

    float a = 0, b = 0;
    int n = 0, position_of_term = 1;
    float sum = 0;

    printf("Enter the value of a and b : ");
    scanf("%f %f", &a, &b);

    printf("Enter the number of intervals : ");
    scanf("%d", &n);

    float h = (b - a) / n;

    for (float i = a + h; i < b; i += h)
    {
        sum += (position_of_term % 3 == 0) ? 2 * f(i) : 3 * f(i);
        position_of_term++;
    }

    sum += f(a) + f(b);

    sum = (h * sum * 3) / 8.0;

    printf("The ans is : %lf", sum);

    return 0;
}