#include<stdio.h>
int main() {
    float taxable,tax;
    printf("enter taxable income(in lakhs)\n");
    scanf("%f", &taxable);
    if(taxable>=2.5 && taxable<=5.0){
        tax=0.05*(taxable - 2.5);
        printf("income tax payable is %f lakh\n", tax);
    }
    else if(taxable>=5.0 && taxable<=10.0)
    {   tax=0.2*(taxable - 5);
         printf("income tax payable is %f lakh\n", tax);
        
    }
    else if(taxable>=10.0){
        tax=0.3*(taxable - 10);
         printf("income tax payable is %f lakh\n", tax);
    }
    else{
    printf("You do not fall under any tax slab and are not required to pay any income tax");
    }
    return 0;



}