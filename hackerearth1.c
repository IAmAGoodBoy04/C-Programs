#include <stdio.h>
void minmax(int *min, int *max, int *maxindex, int n,int arr1[n])
{   
    *max=0;
    *maxindex=0;
    *min=0;
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] > (*max))
        {
            *max = arr1[i];
            *maxindex = i;
        }
    } 
    *min = *max;    
    for(int i=0;i<n;i++){
        if (arr1[i] < (*min))
        {
            *min = arr1[i];
        }
    }
}
int main()
{
    int n, max = 0, min=0, maxindex=0, steps = 0, count = 0,invalid=0;
    int *pmax = &max;
    int *pmin = &min;
    int *pmaxindex = &maxindex;
    scanf("%d", &n);
    int arr1[n];
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }
    minmax(pmin, pmax, pmaxindex, n, arr1);
    while (1)
    {
        count=0;
        while (arr1[maxindex] > min)
        {
            arr1[maxindex] = arr1[maxindex] - arr2[maxindex];
            steps++;
        }
        minmax(pmin, pmax, pmaxindex, n,arr1);
        if(min<0){invalid=1;break;}
        for (int i = 0; i < n; i++)
        {
            if (arr1[i] == min)
            {
                count++;
            }
        }
        if (count == n)
        {
            break;
        }
        
    }
    if(invalid==0){
    printf("%d\n", steps);}
    else{printf("-1\n");}
    return 0;
}