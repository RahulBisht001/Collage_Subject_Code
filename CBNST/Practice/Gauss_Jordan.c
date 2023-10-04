#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the number of rows : ");
    scanf("%d", &n);

    float arr[n][n + 1];
    float values[n];
    float ratio;

    printf("Enter the Arbitrary matrix\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j != i)
            {
                ratio = arr[j][i] / arr[i][i];
                for (int k = 0; k < n + 1; ++k)
                {
                    arr[j][k] -= (ratio * arr[i][k]);
                }
            }
        }
    }

    printf("The Diagonal matrix");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%0.1f\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("The Values are \n");
    for (int i = 0; i < n; ++i)
    {
        printf("value[%d] is = %0.1f \n", i, arr[i][n] / arr[i][i]);
    }

    return 0;
}