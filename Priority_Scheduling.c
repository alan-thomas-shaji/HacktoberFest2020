
#include <stdio.h>

void main()
{
   
    int pid[]={1,2,3,4,5,6,7,8,9,10};
    int number,temp;
    int i,j;
    float sum1=0,sum2=0;
    int ch;
    int burst_array[10],wt[10],tat[10],priority[10];
    
    printf("  --------------- Priority Scheduling Algorithm Implementation--------------\n\n");
    printf("  Enter the total number of processes:");
    scanf("%d",&number);
    for (i=0;i<number;i++){
        printf("\n  Enter the priority of process %d:",i+1);
        scanf("%d",&priority[i]);
        printf("  Enter the burst time of process %d:",i+1);
        scanf("%d",&burst_array[i]);
    }
    
    //Sorting the bt based on priority
    for(i=0;i<number-1;i++){
        for(j=i+1;j<number;j++){
            if(priority[j]<priority[i]){
                
                temp=priority[i];
                priority[i]=priority[j];
                priority[j]=temp;
                
                temp=burst_array[i];
                burst_array[i]=burst_array[j];
                burst_array[j]=temp;
                
                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
                
            }
        }
    }
   
    
   
}

