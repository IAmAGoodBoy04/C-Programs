#include<stdio.h>
#include<stdlib.h>
#define ll long long

typedef struct index{
    int data;
    int index;
}ind;
int compfunc(const void * a, const void * b){
    ind p=*(const ind*)a;
    ind q=*(const ind*)b;
    if(p.data>q.data){
        return 1;
    }
    if(p.data==q.data){
        return 0;
    }
    else{
        return -1;
    }
}
int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        ind arr[n];
        int lowestnonzero,highestnonzero;
        int idiff,jdiff;
        int ansarr[k];
        int arri[n];
        int arrj[n];
        for(int i=0;i<n;i++){
            arri[i]=arrj[i]=0;
            scanf("%d",&arr[i].data);
            arr[i].index=i;
        }
        for(int i=0;i<k;i++){
            ansarr[i]=0;
        }
        qsort((void *)arr,n,sizeof(ind),compfunc);
        for(int i=0;i<n;i++){
            
            if(i>0 && arr[i].data==arr[i-1].data){
                arri[arr[i].index]=-1;
                arrj[arr[i].index]=-1;
                continue;
            }
            for(int p=0;p<n;p++){
                if(arri[p]==0){
                    lowestnonzero=p;
                    break;
                }
            }
            for(int p=n-1;p>=0;p--){
                if(arri[p]==0){
                    highestnonzero=p;
                    break;
                }
            }
            idiff=highestnonzero-lowestnonzero+1;
            for(int p=0;p<n;p++){
                if(arrj[p]==0){
                    lowestnonzero=p;
                    break;
                }
            }
            for(int p=n-1;p>=0;p--){
                if(arrj[p]==0){
                    highestnonzero=p;
                    break;
                }
            }
            jdiff=highestnonzero-lowestnonzero+1;
            ansarr[arr[i].data-1]=idiff+jdiff;
            arri[arr[i].index]=-1;
            arrj[arr[i].index]=-1;
        }
        for(int i=0;i<k;i++){
            printf("%d ",ansarr[i]);
        }
        printf("\n");
    }
return 0;
}