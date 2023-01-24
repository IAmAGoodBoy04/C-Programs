//Write a C program to convert days into year, month and days.  366 days   365 1 month = 30days 
#include<stdio.h>

int main(){
	int days,years,daysfordisplay;
	
	int i = 0;
	
	int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	printf("Enter number of days\n");
	scanf("%d",&days);
	daysfordisplay = days;
	
	if(days<0){
		printf("invalid input");
		return 0;
	}
	
	years = days / 365;
	
	days -= (years*365);
	
	while (days > months[i] ) {

		days -= months[i];
		i++;
	}
	
	printf("\n%d days are equal to %d years, %d months and %d days\n", daysfordisplay, years, i, days);

	return 0;
}


