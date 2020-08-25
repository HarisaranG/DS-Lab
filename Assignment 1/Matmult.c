#include <stdio.h>
int main(){
    int r1,r2,c1,c2;
    printf("Enter the no.of rows n columns of first matrix : ");
    scanf("%d %d",&r1,&c1);
    printf("Enter the no.of rows n columns of second matrix : ");
    scanf("%d %d",&r2,&c2);
    int arr1[r1][c1],arr2[r2][c2],arr3[r1][c2],i,j,k;
    if(c1==r2){
    printf("Enter the elements of matrix 1 : ");
    for(i=0;i<r1;i++){
    for(j=0;j<c1;j++){
    scanf("%d",&arr1[i][j]);
    }
    }
    printf("Enter the elements of matrix 2 : ");
    for(i=0;i<r2;i++){
    for(j=0;j<c2;j++){
    scanf("%d",&arr2[i][j]);
    }
    }
    for(i=0;i<r1;i++){
    for(j=0;j<c2;j++){
    arr3[i][j]=0;
    }
    }
    for(i=0;i<r1;i++){
    for(j=0;j<c2;j++){
    for(k=0;k<c1;k++){
    arr3[i][j]+=arr1[i][k]*arr2[k][j];
    }
    }
    }
    printf("The matrix is : ");
    printf("\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            printf("%d ",arr3[i][j]);
        }
        printf("\n");
        }
    }
    else{
        printf("Not possible");
    }
    return 0;
}
