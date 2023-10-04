#include <stdio.h>
#include <math.h>
int main()
{
    float Ea, Er, Ep, exact, absolute;
    printf("enter the exact value and approximate value");
    scanf("%f %f", &exact, &absolute);

    Ea = fabs(exact - absolute);
    Er = Ea / exact;
    Ep = Er * 100;

    printf("The absolue error is %f \nrelative error is %f \nand percentage error is %f\n", Ea, Er, Ep);
    return 0;
}