#include<stdio.h>

int main() {
    char x[100];
    int n, k;
    scanf("%s", x);
    scanf("%d", &n);
    scanf("%d", &k);
    int len = 0;
    for(int i = 0; x[i] != '\0'; ++i){
        ++len;
    }
    int j = 1;
    for(int i = 1; i <= n; ++i){
        j *= len;
    }
    for(int i = len; i <= j - len; ++i){
        x[i] = x[i % len];
    }
    printf("%s", x);
    printf("\n");
    printf("%c", x[k - 1]);
    return 0;
}