#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("\t Simpson's 1/3rd Rule \n");
    printf("Enter the number of observations: ");
    scanf("%d", &n);

    double observation[n][2];
    printf("Enter the observations \n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &observation[i][0], &observation[i][1]);
    }

    double h = observation[1][0] - observation[0][0];
    double ans = observation[0][1] + observation[n - 1][1];
    double odd = 0, even = 0;

    // Check condition
    int subintervals = n - 1; // Number of subintervals
    if (subintervals % 2 != 0) {
        printf("Simpson's 1/3rd Rule can't be used here!\n");
        return 0;
    }
 
    for (int i = 1; i < n - 1; i++) {
        if (i % 2 == 0)
            even += observation[i][1];
        else
            odd += observation[i][1];
    }

    ans = ans + 4 * odd + 2 * even;
    ans *= h;
    ans /= 3;

    printf("\nThe solution is %lf\n", ans);
    return 0;
}
