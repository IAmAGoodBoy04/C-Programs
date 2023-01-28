#include<stdio.h>

int main()

{

    int n;
    scanf("%d",&n);
    int a[n],b[n],i,c=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    int min=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<min)
        min=a[i];
    }
    i=0;
    c=0;
      while(i<n)
    {
        //c=0;
        while(a[i]>min)
        {
            a[i]=a[i]-b[i];
            c++;
        }
        if(a[i]<min)

        {
            min=a[i];
            i=0;
        }
        else
        if(a[i]<0)
        {
            c=-1;
            break;
        }
        else
        i++;
    }
    printf("%d",c);
    return 0;

}