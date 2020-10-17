/* Program to implement Shortest Job First (SJF) scheduling */

#include <stdio.h>

void resulttime(int process[],int n,int process_burst[],int process_arrival[])
{
	int wait[n], tat[n], temp, min, total_burst=0, total_arrival=0;
	float total_wait, total_tat;

	/* Arranging processes on arrival time */

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(process_arrival[i]<process_arrival[j])
			{
				temp = process_arrival[j];
				process_arrival[j] = process_arrival[i];
				process_arrival[i] = temp;

				temp = process[j];
				process[j] = process[i];
				process[i] = temp;
				
				temp = process_burst[j];
				process_burst[j] = process_burst[i];
				process_burst[i] = temp;	
			}
		}
	}

	/* Sorting according to burst time */
	for(int i=0,k=1;i<n;i++,k++)
	{
		total_burst = total_burst + process_burst[i];
		min = process_burst[k];
		for(int j=k;j<n;j++)
		{	
			if(total_burst >= process_arrival[j] && process_burst[j] < min)
			{	
				temp = process_arrival[k];
				process_arrival[k] = process_arrival[j];
				process_arrival[j] = temp;

				temp = process[k];
				process[k] = process[j];
				process[j] = temp;
				
				temp = process_burst[k];
				process_burst[k] = process_burst[j];
				process_burst[j] = temp;
			}
		}
	}

	/* Waiting time for each process */


	wait[0]=0;
	total_burst=0;
	for(int i=1;i<n;i++)
	{
		total_burst = total_burst + process_burst[i-1];
		wait[i] = total_burst - process_arrival[i];
	}

	/* Turn around time for each process */

	for(int i=0;i<n;i++)
	{
		total_arrival = total_arrival + process_burst[i];
		tat[i] = total_arrival - process_arrival[i];
	}

	/* Results */

	printf("\nProcess   \tArrival Time\tBurst Time\tWait Time\tTurn Around Time");

	for(int i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",process[i],process_arrival[i],process_burst[i],wait[i],tat[i]);
		total_wait = total_wait + wait[i];
		total_tat = total_tat + tat[i];
	}
	printf("\n\nAverage Wait Time:%f",total_wait/n);
	printf("\nAverage Turn Around Time:%f",total_tat/n);
}


 /* Driver Code */

void main()
{
	int n;
	printf("\nEnter number of processes:");
	scanf("%d",&n);
	int process[n],process_arrival[n],process_burst[n];

	for(int i=0;i<n;i++)
	{
		process[i]=i+1;
		printf("\nEnter arrival time of process %d:",i+1);
		scanf("%d",&process_arrival[i]);
		printf("\nEnter burst time of process %d:",i+1);
		scanf("%d",&process_burst[i]);
	}

	resulttime(process,n,process_burst,process_arrival);
}
