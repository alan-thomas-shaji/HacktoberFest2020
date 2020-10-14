
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
    wt[0]=0;
    for(i=1;i<number;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i]+=burst_array[j];
        }
        sum1+=wt[i];
    }
    
    for(i=0;i<number;i++){
        tat[i]=0;
        for(j=0;j<=i;j++){
            tat[i]+=burst_array[j];
        }
        sum2+=tat[i];
    
    }
    printf("\n\n ----------------------------------------------------------------------------------------------------------\n");
    printf("\n  Process\t Priority\t Burst Time\t Waiting Time\t Turn-around Time" );
    for(i=0;i<number;i++)
    {
    printf("\n   P%d\t\t   %d\t\t  %d\t\t\t  %d\t\t\t%d",pid[i],priority[i],burst_array[i],wt[i],tat[i]);
    }
 
    printf("\n\n  AVERAGE WAITING TIME : %f",sum1/number);
    printf("\n  AVERAGE TURN AROUND TIME : %f",sum2/number);
    printf("\n\n ----------------------------------------------------------------------------------------------------------\n");
        
    
    
   
}

