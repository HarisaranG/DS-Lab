#include <stdio.h>

int main() {
    int arr[100],i,n,idx,val;
    printf("Enter the no.of elements in array :");
    scanf("%d",&n);
    printf("Enter the elements :");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the index at which the element to be inserted :");
    scanf("%d",&idx);
    printf("Enter the value of the element :");
    scanf("%d",&val);
    for(i=n-1;i>=idx;i--){
        arr[i+1]=arr[i];
    }
    arr[idx]=val;
    printf("The new array after inserting the element is \n");
    for(i=0;i<n+1;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}