#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r[100],i,n,TotalHeadMoment=0,initial,count=0;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&r[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    
    while(count!=n)
    {
        int min=1000,d,index;
        for(i=0;i<n;i++)
        {
           d=abs(r[i]-initial);
           if(min>d)
           {
               min=d;
               index=i;
           }
           
        }
        TotalHeadMoment=TotalHeadMoment+min;
        initial=r[index];
        r[index]=1000;
        count++;
    }
    
    printf("Total head movement is %d",TotalHeadMoment);
    return 0;
}
