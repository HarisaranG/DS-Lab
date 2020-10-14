#include<stdio.h>

int moves = 0;
void binarySearch(int arr[], int l, int r){
    if(l == r){
        int temp;
        printf("%d", arr[l]);
        scanf("%d", &temp);
        ++moves;
        if(temp == 2){
            printf("%d\n%d", moves, l);
        } else {
            printf("%d\n-1", moves);
        }

    }
    while(l <= r){
        
    }
}

int main(){
    
}