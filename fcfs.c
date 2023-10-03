#include <stdio.h>

void main() {
    int i, j, n, head;
    float avg, sum;
    sum = 0;
    int trackpos[20], stime[20];

    printf("Enter number of tracks : ");
    scanf("%d", &n);
    printf("Enter position of header : ");
    scanf("%d", &head);
    printf("Enter position of tracks : ");

    for(i=0; i<n; i++) {
        scanf("%d", &trackpos[i]);
        stime[i] = head - trackpos[i];

        if(stime[i] < 0) {
            stime[i] = trackpos[i]-head;
        }
        head = trackpos[i];
        sum = sum + stime[i];
    }

    avg = sum/n;
    printf("\nTrack position\tDifference between tracks");

    for (i=0; i<n; i++) {
        printf("\n%d\t\t%d", trackpos[i], stime[i]);
    }

    printf("\n\nTotal movements of header : %f ", sum);
    printf("\nAverage of header movements : %f ", avg);
    printf("\n");
}
