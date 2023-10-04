#include <stdio.h>
#include <math.h>
int main()
{
    float Ea, Er, Ep, exact, absolute, x = 1, y = 1, z = 1, dx, dy, dz, ex = 0.001, ey = 0.001, ez = 0.001;
    float u = (4 * x * x * y * y * y) / (z * z * z * z);
    dx = (8 * x * y * y * y) / (z * z * z * z);
    dy = (12 * x * x * y * y) / (z * z * z * z);
    dz = (-16 * x * x * y * y * y) / (z * z * z * z * z);
    Ea = fabs(dx * ex) + fabs(dy * ey) + fabs(dz * ez);
    Er = Ea / u;
    Ep = Er * 100;

    printf("The absolute error is %f \nrelative error is %f \nand percentage error is %f %%\n", Ea, Er, Ep);
    return 0;
}