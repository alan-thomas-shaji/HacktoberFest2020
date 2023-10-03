#include <stdio.h> 

int binarySearch(int ar[], int l, int r, int x) { 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (ar[mid] == x) 
            return mid;
        if (ar[mid] > x) 
            return binarySearch(ar, l, mid - 1, x);
        return binarySearch(ar, mid + 1, r, x); 
    }
    return -1; 
} 
  
int main(void) { 
    int ar[] = { 2, 3, 4, 10, 40 }; 
    int n = sizeof(ar) / sizeof(ar[0]); 
    int x = 10; 
    int result = binarySearch(ar, 0, n - 1, x); 
    (result == -1) ? printf("Element is not present in array!!!") 
                   : printf("Element is present at position %d", 
                            result); 
    return 0; 
} 
