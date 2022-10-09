#include<stdio.h>
void main()
{
int trackpos[25],n,head,i,j,sum=0,maxrange,diff,temp,a[20],b[20],temp1=0,temp2=0;
float avg;
printf("Enter the maximum range of Disk : ");
scanf("%d",&maxrange);
printf("Enter the number of tracks : ");
scanf("%d",&n);
printf("Enter the initial position of header : ");
scanf("%d",&head);
printf("Enter the position of tracks : ");
for(i=0;i<n;i++)
{
scanf("%d",&temp);

if(temp>head)
{
a[temp1]=temp;
temp1++;
}
else
{
b[temp2]=temp;
temp2++;
}
}
for(i=0;i<temp1-1;i++)
{
for(j=i+1;j<temp1;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
for(i=0;i<temp2-1;i++)
{
for(j=i+1;j<temp2;j++)
{
if(b[i]>b[j])
{
temp=b[i];
b[i]=b[j];
b[j]=temp;
}
}
}
for(i=1,j=0;j<temp1;i++,j++)
{
trackpos[i]=a[j];
}
trackpos[i]=maxrange;
trackpos[i+1]=0;
for(i=temp1+3,j=0;j<temp2;i++,j++)
{
trackpos[i]=b[j];
}

trackpos[0]=head;
printf("\nTrack position\tDifference between tracks");
for(i=0; i<=n+1; i++)
{
if(trackpos[i+1]>trackpos[i])
{
diff=trackpos[i+1]-trackpos[i];
sum=sum+diff;
printf("\n%d\t\t%d",trackpos[i+1],diff);
}
else
{
diff=trackpos[i]-trackpos[i+1];
sum=sum+diff;
printf("\n%d\t\t%d",trackpos[i+1],diff);
}
}
avg=sum/(float)n;
printf("\nTotal movements of header : %d\n", sum);
printf("Average header movements : %f\n", avg);
}
