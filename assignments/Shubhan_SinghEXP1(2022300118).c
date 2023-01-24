//operate.c
// #include<stdio.h>
// int main(){
//     int a,b,sum,difference,modulus,product;
//     float division;
//     printf("Enter two numbers\n");
//     scanf("%d %d",&a,&b);
//     sum=a+b;
//     difference=a-b;
//     product=a*b;
//     division=(float)a/b;
//     modulus=a%b;
//     printf("the sum of the two numbers is: %d\n",sum);
//     printf("the difference between the two numbers is: %d\n",difference);
//     printf("the product of the two numbers is: %d\n",product);
//     printf("the division of the two numbers is: %f\n",division);
//     printf("the modulus of the two numbers is: %d\n",modulus);
//     return 0;
// }




//interest.c
// #include<stdio.h>
// #include<math.h>
// int main(){
//     double a=500000, r=0.035, p=10;
//     double cia,cisa,ciq,cim,cid;
//     cia=(a*pow(1+r,1.0*p ))-a;//.0 is for type-casting to double
//     cisa=(a*pow(1+r/2.0 ,2.0*p))-a;
//     ciq=(a*pow(1+r/4.0, 4.0*p))-a;
//     cim=(a*pow(1+r/12.0, 12.0*p))-a;
//     cid=(a*pow(1+r/365.0, 365.0*p))-a;
//     printf("\nSimple interest on Rs.500000 in 10 years is %.2lf\n\n", a*r*p);
//     printf("Interest on Rs.500000 in 10 years compounded annually is %.2lf\n\n", cia);
//     printf("Interest on Rs.500000 in 10 years compounded semi-annually is %.2lf\n\n", cisa);
//     printf("Interest on Rs.500000 in 10 years compounded quarterly is %.2lf\n\n", ciq);
//     printf("Interest on Rs.500000 in 10 years compounded monthly is %.2lf\n\n", cim);
//     printf("Interest on Rs.500000 in 10 years compounded daily is %.2lf\n\n", cid);
//     return 0;
// }




//tempconvert.c
// #include<stdio.h>
// int main()
// {
// float c,f;
// printf("Enter temperature in degrees Fahrenheit:  ");
// scanf("%f",&f);
// c = (f-32)*5/9.0;//.0 for type casting
// printf("\n Temp %.2f in Fahrenheit = %.2f Centigrade\n",f,c); 
// return 0;
// }





//daysconvert.c
// #include<stdio.h>
// int main(){
// int days,months,years,daysfordisplay;
// printf("enter number of days\n");
// scanf("%d",&days);
// daysfordisplay=days;

// if(days<0){
// printf("invalid input");
// return 0;
// }

// years=days/365;
// days=days-(years*365);
// 	if(days>=0 && days<31){months=0;}
// 	else if(days>=31 && days<(31+28)){months=1;days-31;}
// 	else if(days>=(31+28) && days<(31+28+31)){months=2;days=days-31-28;}
// 	else if(days>=(31+28+31) && days<(31+28+31+30)){months=3;days=days-31-28-31;}
// 	else if(days>=(31+28+31+30) && days<(31+28+31+30+31)){months=4;days=days-31-28-31-30;}
// 	else if(days>=(31+28+31+30+31) && days<(31+28+31+30+31+30)){months=5;days=days-31-28-31-30-31;}
// 	else if(days>=(31+28+31+30+31+30) && days<(31+28+31+30+31+30+31)){months=6;days=days-31-28-31-30-31-30;}
// 	else if(days>=(31+28+31+30+31+30+31) && days<(31+28+31+30+31+30+31+31)){months=7;days=days-31-28-31-30-31-30-31;}
// 	else if(days>=(31+28+31+30+31+30+31+31) && days<(31+28+31+30+31+30+31+31+30)){months=8;days=days-31-28-31-30-31-30-31-31;}
// 	else if(days>=(31+28+31+30+31+30+31+31+30) && days<(31+28+31+30+31+30+31+31+30+31)){months=9;days=days-31-28-31-30-31-30-31-31-30;}
// 	else if(days>=(31+28+31+30+31+30+31+31+30+31) && days<(31+28+31+30+31+30+31+31+30+31+30)){months=10;days=days-31-28-31-30-31-30-31-31-30-31;}
// 	else{months=11;days=days-31-28-31-30-31-30-31-31-30-31-30;}

// printf("\n%d days are equal to %d years, %d months and %d days", daysfordisplay,years,months,days);
// return 0;
// }





