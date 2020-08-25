#include<stdio.h>

int main(){
    int n, m, i, j, search;
    int a[100][100];
    printf("Enter number of row and coloumns: ");
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter a element to be searched: ");
    scanf("%d", &search);
    i = 0;
    j = n - 1;
    while(i < n && j >= 0){
        if(a[i][j] == search){
            printf("The element is found at the position [%d, %d] \n", i + 1, j + 1);
            return 0;
        }
        else if(search > a[i][j]){
            i += 1;

        }
        else{
            j -= 1;
        }
    }
    printf("Element not Found !");
    return 0;
}