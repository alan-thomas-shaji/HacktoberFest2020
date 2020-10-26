#include<stdio.h>

void main(){
    int i, n, burstTime[10], waitingTime[10], turnaroundTime[10];
    printf("Enter the process details for FCFS Scheduling");

    printf("\nEnter the number of processes:\t");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("\nEnter the Burst Time for process %d\t", i+1);
        scanf("%d", &burstTime[i]);
    }

    waitingTime[0] = 0;

    for (i=1; i<n ; ++i)
    {
        waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
    }

    printf("\n\nThe waiting times of each processes are:");

    for( i=0; i<n; ++i)
    {
        printf("\nProcess %d : %d", i+1, waitingTime[i]);
    }

    turnaroundTime[0] = burstTime[0];

    for (i=1; i<n; ++i)
    {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
    }

    printf("\n\nThe turnaround times of each processes are:");

    for( i=0; i<n; ++i)
    {
        printf("\nProcess %d : %d", i+1,turnaroundTime[i]);
    }

    float avgWaitTime = 0, avgTurnaroundTime = 0;

    for(i=0; i<n; ++i)
    {
        avgTurnaroundTime = avgTurnaroundTime + turnaroundTime[i];
        avgWaitTime = avgTurnaroundTime + waitingTime[i];
    }

    avgTurnaroundTime = avgTurnaroundTime/4;
    avgWaitTime = avgTurnaroundTime/4;

    printf("\n\nThe average Waiting Time is : %f", avgWaitTime);
    printf("\n\nThe average Turn around Time is : %f", avgTurnaroundTime);

}
