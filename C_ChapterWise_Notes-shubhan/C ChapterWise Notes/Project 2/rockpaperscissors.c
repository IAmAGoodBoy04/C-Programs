#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int plr=0,comp=0;
void randomgen(char *c){
    int m,rem=0;
    srand(time(0));
    m=rand();
    while(rem==0){
        rem=m%10;
        if(rem==0){m=m/10;}
    }
    if(rem<0){rem=rem*(-1);}
    if(rem<4){
        *c='r';
    }
    else if((rem>=4) && (rem>7)){
        *c='p';
    }
    else{
        *c='s';
    }
}
void printres(char p,char c){
    if(p=='r' && c=='s'){
        printf("You win!\n");
        plr++;
    }
    else if(c=='r' && p=='s'){
        printf("you lose\n");
        comp++;
    }
    else if(p=='s' && c=='p'){
        printf("You win!\n");
        plr++;
    }
    else if(c=='s' && p=='p'){
        printf("you lose\n");
        comp++;
    }
    else if(p=='p' && c=='r'){
        printf("You win!\n");
        plr++;
    }
    else if(c=='p' && p=='r'){
        printf("you lose\n");
        comp++;
    }
    else{printf("draw\n");}
    
}
int main(){
    int n;
    char p,c;
    printf("Note: Enter r for rock, p for paper, s for scissors\n");
    printf("Enter number of rounds: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("choose rock,paper or scissors: ");
        while ((getchar()) != '\n');
        p=getchar();
        randomgen(&c);
        printf("computer chose %c\n",c);
        printres(p,c);
    }
    printf("\n\nFinal result is:\nplayer:%d\tcomputer:%d\n",plr,comp);
    if(plr==comp){printf("draw :(\n");}
    else if(plr>comp){printf("You won!!!");}
    else{printf("t(-_-t)");}
    return 0;
}