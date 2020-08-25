#include <stdio.h>
#include <string.h>
int main()
{
    char arr[100];
    int n,i,flag=0;
    printf(" Enter the string :");
    gets(arr);
    n=strlen(arr);
    for(i=0;i<n;i++){
        if(arr[i]!=arr[n-i-1])
            flag=1;
    }
    if(flag==1) printf("Not a palindrome");
    else printf("Palindrome");
    return 0;
}
