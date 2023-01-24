 /* Write a C program temp.c that accepts a temperature in Fahrenheit and  prints the corresponding temperature in Celsius.

Test data and expected output:

Enter temp in Farenheit:  98.4

Temp 98.40 in Farenheit = 36.89 Centigrade */

#include<stdio.h>
int main()
{
float c,f;
printf("Enter temperature in degrees Fahrenheit:  ");
scanf("%f",&f);
c = (f-32)*5/9.0;//.0 for type casting
printf("\n Temp %.2f in Fahrenheit = %.2f Centigrade\n",f,c); 
return 0;
}
