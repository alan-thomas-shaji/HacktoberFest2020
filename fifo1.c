#include<stdio.h>

void main() {
    int i, j, pn, page[50], frame[10], fn, k, avail;
    float pfault = 0, phit = 0, faultratio = 0, hitratio = 0;
    printf("\nFIFO PAGE REPLACEMENT ALGORITHM\n");
    printf("\n Enter the number of pages : ");
    scanf("%d", & pn);
    printf("\n Enter the page number : ");
    for (i = 0; i < pn; i++) {
        scanf("%d", & page[i]);
    }
    printf("\n Enter the number of frames : ");
    scanf("%d", & fn);
    for (i = 0; i < fn; i++) {
        frame[i] = -1;
    }
    j = 0;
    printf("\n\tReference string\t Page Frames\t\tHit or Fault\n");
    for (i = 0; i < pn; i++) {
        printf("\t\t%d\t\t", page[i]);
        avail = 0;

        for (k = 0; k < fn; k++) {
            if (frame[k] == page[i]) {
                phit++;
                avail = 1;
                for (k = 0; k < fn; k++) {
                    printf("%d\t", frame[k]);
                }
                if (avail == 1) {
                    printf(" H");
                }
            }
        }
        if (avail == 0) {
            frame[j] = page[i];
            j = (j + 1) % fn;
            pfault++;
            for (k = 0; k < fn; k++) {
                printf("%d\t", frame[k]);
            }
            if (avail == 0) {
                printf(" F");
            }
        }
        printf("\n");
    }
    hitratio = phit / pn;
    faultratio = pfault / pn;
    printf("Page hit is %f\n", phit);
    printf("Page Fault Is %f\n", pfault);
    printf("Page hit ratio is %f\n ", hitratio);
    printf("Page fault ratio is %f \n", faultratio);
}
