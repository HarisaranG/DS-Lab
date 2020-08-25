#include <stdio.h>
int main(){
    int arr[10], i, j, k, Size;
    printf("Enter Number of elements in an array : ");
    scanf("%d", &Size);
    printf("Enter the elements : ");
    for (i = 0; i < Size; i++){
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < Size; i++){
        for(j = i + 1; j < Size; j++){
            if(arr[i] == arr[j]){
                for(k = j; k < Size; k++){
                    arr[k] = arr[k + 1];
                }
                Size--;
                j--;
            }
        }
    }
    printf("The new array is :");
    for (i = 0; i < Size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}