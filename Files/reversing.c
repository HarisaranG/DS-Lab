#include<stdio.h>
#include<string.h>

int main() {
    FILE* file;
    char filecontent[10000];
    int i = 0;
    file = fopen("file.txt", "r");
    char ch = fgetc(file);
    while(!feof(file)){
        filecontent[i] = ch;
        ++i;
        ch = fgetc(file);
    }
    strrev(filecontent);
    printf("%s", filecontent);
    fclose(file);
    return 0;
}