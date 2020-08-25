#include<stdio.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int n, i, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements containing 0, 1, 2: \n");
    for(i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    int lo = 0, mid = 0, hi = n - 1;
    while(mid <= hi){
        if(a[mid] == 0){
            swap(&a[mid++], &a[lo++]);
        }
        else if(a[mid] == 1){
            ++mid;
        }
        else{
            swap(&a[hi--], &a[mid]);
        }
    }
    printf("The Sorted Array: ");
    for(i = 0; i< n; ++i){
        printf("%d ", a[i]);
    }
}