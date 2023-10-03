#include<stdio.h>
#include<stdlib.h>

void main(){
    int req_sq[10],i,j,n,head,seek_count=0,distance,rl[10],rg[10],irl=-1,irg=-1,temp;
    float avg;
    printf("  ------------------------SCAN Disk Scheduling Algorithm-------------------------\n\n");
    printf("  Enter the size of request queue : ");
    scanf("%d",&n);
    printf("  Enter the request sequence :-\n");
    printf("  ");
    for(i=0;i<n;i++){
        scanf("%d",&req_sq[i]);
    }
    printf("  Enter the current head position : ");
    scanf("%d",&head);
    for(i=0;i<n;i++){
        if(req_sq[i]<=head){
            rl[++irl]=req_sq[i];

        }
        else{
                rg[++irg]=req_sq[i];
            }
    }
    for(i=0;i<irl;i++){
        for(j=i+1;j<irl+1;j++){
            if(rl[j]>rl[i]){
                temp=rl[i];
                rl[i]=rl[j];
                rl[j]=temp;
            }

        }
    }
    for(i=0;i<irg;i++){
        for(j=i+1;j<irg+1;j++){
            if(rg[j]<rg[i]){
                temp=rg[i];
                rg[i]=rg[j];
                rg[j]=temp;
            }

        }
    }
    for(i=0;i<=irl;i++){
        distance = abs(head - rl[i]);
        seek_count+=distance;
        head=rl[i];
    }
    seek_count+=rl[irl];
    head=0;
    for(i=0;i<=irg;i++){
        distance=abs(head-rg[i]);
        seek_count+=distance;
        head=rg[i];
    }
    avg = seek_count/n;
    printf("\n\n  ============================================================\n\n");
    printf("  TOTAL SEEK TIME : %d",seek_count);
    printf("\n  AVERAGE SEEK TIME : %for",avg);
    printf("\n\n  ============================================================\n\n"); 
}
