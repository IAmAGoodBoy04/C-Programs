//Write a C program to convert days into year, month and days.  366 days   365 1 month = 30days 
#include<stdio.h>
int main(){
int days,months,years,daysfordisplay;
printf("enter number of days\n");
scanf("%d",&days);
daysfordisplay=days;

if(days<0){
printf("invalid input");
return 0;
}

years=days/365;
days=days-(years*365);
	if(days>=0 && days<31){months=0;}
	else if(days>=31 && days<(31+28)){months=1;days-31;}
	else if(days>=(31+28) && days<(31+28+31)){months=2;days=days-31-28;}
	else if(days>=(31+28+31) && days<(31+28+31+30)){months=3;days=days-31-28-31;}
	else if(days>=(31+28+31+30) && days<(31+28+31+30+31)){months=4;days=days-31-28-31-30;}
	else if(days>=(31+28+31+30+31) && days<(31+28+31+30+31+30)){months=5;days=days-31-28-31-30-31;}
	else if(days>=(31+28+31+30+31+30) && days<(31+28+31+30+31+30+31)){months=6;days=days-31-28-31-30-31-30;}
	else if(days>=(31+28+31+30+31+30+31) && days<(31+28+31+30+31+30+31+31)){months=7;days=days-31-28-31-30-31-30-31;}
	else if(days>=(31+28+31+30+31+30+31+31) && days<(31+28+31+30+31+30+31+31+30)){months=8;days=days-31-28-31-30-31-30-31-31;}
	else if(days>=(31+28+31+30+31+30+31+31+30) && days<(31+28+31+30+31+30+31+31+30+31)){months=9;days=days-31-28-31-30-31-30-31-31-30;}
	else if(days>=(31+28+31+30+31+30+31+31+30+31) && days<(31+28+31+30+31+30+31+31+30+31+30)){months=10;days=days-31-28-31-30-31-30-31-31-30-31;}
	else{months=11;days=days-31-28-31-30-31-30-31-31-30-31-30;}

printf("\n%d days are equal to %d years, %d months and %d days", daysfordisplay,years,months,days);
return 0;
}


