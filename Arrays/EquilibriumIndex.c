#include<stdio.h>

int main(){
    int a[100], n, i = 0, sumall = 0, sumf = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(;i < n; ++i){
        scanf("%d", &a[i]);
        sumall += a[i];
    }
    for(i = 0; i < n; ++i){
        sumf += a[i];
        if(sumf - a[i] == sumall - sumf){
            printf("Equilibrium Index found at: %d \n", i);
        }
    }
    return 0;
}