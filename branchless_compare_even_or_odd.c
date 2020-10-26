#include <stdio.h>
int main()
{
    int i;
    for(i = 0; i<10000; i++)
        /* print even or odd with branchless comparison */
        (i%2==0)?printf("%d is %s\n",i,"Even"):printf("%d is %s\n",i,"Odd");
}
