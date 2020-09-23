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
    FILE* file1;
    file1 = fopen("file1.txt", "w");
    fputs(filecontent, file1);
    fclose(file1);
    remove("file.txt");
    rename("file1.txt", "file.txt");
    return 0;
}