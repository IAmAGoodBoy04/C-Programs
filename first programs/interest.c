#include<stdio.h>
#include<math.h>
int main(){
    double a=500000, r=0.035, p=10;
    double cia,cisa,ciq,cim,cid;
    cia=(a*pow(1+r,1.0*p ))-a;//.0 is for type-casting to double
    cisa=(a*pow(1+r/2.0 ,2.0*p))-a;
    ciq=(a*pow(1+r/4.0, 4.0*p))-a;
    cim=(a*pow(1+r/12.0, 12.0*p))-a;
    cid=(a*pow(1+r/365.0, 365.0*p))-a;
    printf("\nSimple interest on Rs.500000 in 10 years is %.2lf\n\n", a*r*p);
    printf("Interest on Rs.500000 in 10 years compounded annually is %.2lf\n\n", cia);
    printf("Interest on Rs.500000 in 10 years compounded semi-annually is %.2lf\n\n", cisa);
    printf("Interest on Rs.500000 in 10 years compounded quarterly is %.2lf\n\n", ciq);
    printf("Interest on Rs.500000 in 10 years compounded monthly is %.2lf\n\n", cim);
    printf("Interest on Rs.500000 in 10 years compounded daily is %.2lf\n\n", cid);

    return 0;
}