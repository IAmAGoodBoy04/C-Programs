#include<stdio.h>
typedef struct dates{
    int days,months,years;
}date;
int comparedates(date a,date b){
    if(a.years>b.years){return 1;}
    else if(a.years<b.years){return -1;}
    else if(a.months>b.months){return 1;}
    else if(a.months<b.months){return -1;}
    else if(a.days>b.days){return 1;}
    else if(a.days<b.days){return -1;}
    else{return 0;}
}
int main(){
    date datesarr[10];
    date *a=datesarr;
    int x;
    printf("Enter days months and year respectively in first date:\n");
    scanf("%d %d %d",&a->days,&a->months,&a->years);
    a++;
    printf("Enter days months and year respectively in second date:\n");
    scanf("%d %d %d",&a->days,&a->months,&a->years);
    x=comparedates(datesarr[0],datesarr[1]);
    if(x==0){printf("The dates are equal\n");}
    if(x==1){printf("The date %d/%d/%d is larger\n",datesarr[0].days,datesarr[0].months,datesarr[0].years);}
    if(x==-1){printf("The date %d/%d/%d is larger\n",datesarr[1].days,datesarr[1].months,datesarr[1].years);}
    return 0;
}