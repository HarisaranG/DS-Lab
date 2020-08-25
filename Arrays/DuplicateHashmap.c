#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, a[100], i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements in the range of [0, %d]: ", n - 1);
    for(i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; ++i){
        a[a[i] % n] = a[a[i] % n] + n;
    }
    printf("The repeating elements are: ");
    for(i = 0; i < n; ++i){
        if(a[i] >= 2 * n){
            printf("%d ", i);
        }
    }
}