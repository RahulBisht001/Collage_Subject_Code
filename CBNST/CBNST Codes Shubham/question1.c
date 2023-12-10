#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Write a program in C language to deduce error (absolute error, relative error, percentage error) involved in polynomial equation
int main()
{
    int x, y, z;
    double dx, dy, dz;
    printf("Enter the value of x, y and z respectively : ");
    scanf("%d %d %d",&x,&y,&z);

    printf("Enter the value of errors x, y and z respectively : ");
    scanf("%lf %lf %lf",&dx,&dy,&dz);

    double true_value = 4*pow(x,2)*pow(y,3)/pow(z,4);
    double error_value = fabs((8*x*pow(y,3)/pow(z,4))*dx + (12*pow(x,2)*pow(y,2)/pow(z,4))*dy + (-16*pow(x,2)*pow(y,3)/pow(z,5))*dz);

    printf("%lf\n",error_value);

    double absolute_error, relative_error, percentage_error;
    absolute_error = error_value;
    relative_error = absolute_error/true_value;
    percentage_error = relative_error*100;

    printf("Absolute error : %lf\n", absolute_error);
    printf("Relative error: %lf\n", relative_error);
    printf("Percentage error: %lf\n", percentage_error);

    return 0;
}