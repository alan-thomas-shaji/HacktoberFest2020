
/* Program to implement C-SCAN disk scheduling */

#include <stdio.h>

const int disk_size = 199;					// last cylinder of disk
int head;



	sort(hl,x);
	sort(hr,y);
	printf("\n");

	for(int i=0;i<=y;i++)
	{
		distance = abs(hr[i] - head);
		seek_count += distance;
		head = hr[i];
	}

	seek_count += abs(head - disk_size);
	head = disk_size;
	seek_count += head;
	head = 0;

	for(int i=0;i<=x;i++)
	{
		distance = abs(hl[i] - head);
		seek_count += distance;
		head = hl[i];
	}		
	
	printf("\nTotal seek time:%d",seek_count);
	printf("\nAverage seek time:%f",(float)seek_count/n);

}


void main()
{
	int n;
	
	printf("\nEnter head position:");
	scanf("%d",&head);
	printf("\nEnter number of requests:");
	scanf("%d",&n);
	int request_sequence[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter request %d:",i);
		scanf("%d",&request_sequence[i]);
	}

	resulttime(n,request_sequence);
}
