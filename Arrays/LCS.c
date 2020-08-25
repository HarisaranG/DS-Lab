#include<stdio.h>

int main(){
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    // Kadane Algorithm
    int meh = 0, msf = -__INT_MAX__ + 1;
    for(int i = 0; i < n; ++i){
        meh += a[i];
        if(msf < meh){
            msf = meh;
        }
        if(meh < 0)
            meh = 0;
    }
    printf("Largest Sum of Contiguous Subarray: %d", msf);
}