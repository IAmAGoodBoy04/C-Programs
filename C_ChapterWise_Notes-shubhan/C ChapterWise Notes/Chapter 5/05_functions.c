#include<stdio.h>
void goodmorning();
void goodafternoon();
void goodnight();
int main(){
    goodmorning();
    goodafternoon();
    goodnight();
    return 0;
}
void goodmorning(){
    printf("\ngood morning!\n");
}
void goodafternoon(){
    printf("\ngood afternoon!\n");
}
void goodnight(){
    printf("\ngood night!\n");
}