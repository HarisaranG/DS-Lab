#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    FILE *file, *file1;
    file = fopen("file.txt", "r");
    file1 = fopen("file1.txt", "w");
    char ch = fgetc(file);
    while(ch != EOF){
        if(islower(ch)){
            ch = toupper(ch);
        } else if(isupper(ch)){
            ch = tolower(ch);
        }
        fputc(ch, file1);
        ch = fgetc(file);
    }
    fclose(file1);
    fclose(file);
    remove("file.txt");
    rename("file1.txt", "file.txt");
}