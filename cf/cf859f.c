#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bounces;
int simulate(int x, int y, int xi, int yi, int xf, int yf, int dir){
    int yes=0;
    int xcoord=xi;
    int ycoord=yi;
    int breakall=1;
    while(breakall){
        while(dir==1){
            if(xcoord!=1 && ycoord!=y){
            xcoord--;
            ycoord++;
            }
            if(xcoord==xf && ycoord==yf){
                yes=1;
                breakall=0;
                break;
            }
            if(xcoord==1 && ycoord==y){
                if(bounces>0){
                breakall=0;
                break;
                }
                else{
                    dir=3;
                    bounces++;
                    break;
                }
            }
            if(xcoord==1){
                dir=2;
                bounces++;
                break;
            }
            if(ycoord==y){
                dir=4;
                bounces++;
                break;
            }
        }
        while(dir==2){
            if(xcoord!=x && ycoord!=y){
            xcoord++;
            ycoord++;}
            if(xcoord==xf && ycoord==yf){
                yes=1;
                breakall=0;
                break;
            }
            if(xcoord==x && ycoord==y){
                if(bounces>0){
                breakall=0;
                break;
                }
                else{
                    dir=4;
                    bounces++;
                    break;
                }
            }
            if(xcoord==x){
                dir=1;
                bounces++;
                break;
            }
            if(ycoord==y){
                dir=3;
                bounces++;
                break;
            }
        }
        while(dir==3){
            if(xcoord!=x && ycoord!=1){
            xcoord++;
            ycoord--;}
            if(xcoord==xf && ycoord==yf){
                yes=1;
                breakall=0;
                break;
            }
            if(xcoord==x && ycoord==1){
                if(bounces>0){
                breakall=0;
                break;
                }
                else{
                    dir=1;
                    bounces++;
                    break;
                }
            }
            if(xcoord==x){
                dir=4;
                bounces++;
                break;
            }
            if(ycoord==1){
                dir=2;
                bounces++;
                break;
            }
        }
        while(dir==4){
            if(xcoord!=1 && ycoord!=1){
            xcoord--;
            ycoord--;}
            if(xcoord==xf && ycoord==yf){
                yes=1;
                breakall=0;
                break;
            }
            if(xcoord==1 && ycoord==1){
                if(bounces>0){
                breakall=0;
                break;
                }
                else{
                    dir=2;
                    bounces++;
                    break;
                }
            }
            if(xcoord==1){
                dir=3;
                bounces++;
                break;
            }
            if(ycoord==1){
                dir=1;
                bounces++;
                break;
            }
        }

    }
    return yes;
}
int main(){
    int t,x,y,xi,yi,xf,yf,dir,yes;
    char str[3];
    scanf("%d",&t);
    while(t--){
        bounces=0;
        scanf("%d %d %d %d %d %d %[^\n]%*c",&x,&y,&xi,&yi,&xf,&yf,str);
        if(strcmp(str,"UR")==0){dir=1;}
        else if(strcmp(str,"DR")==0){dir=2;}
        else if(strcmp(str,"DL")==0){dir=3;}
        else if(strcmp(str,"UL")==0){dir=4;}
        yes=simulate(x,y,xi,yi,xf,yf,dir);
        if(yes==1){
            printf("%d\n",bounces);
        }
        else{
            printf("-1\n");
        }
    }

return 0;
}