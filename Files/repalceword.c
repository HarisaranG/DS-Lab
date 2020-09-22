#include<stdio.h>
#include<string.h>

int main() {
    FILE *file, *file1;
    file = fopen("file.txt", "r");
    file1 = fopen("file1.txt", "w");
    char search[100], replace[100];
    printf("Enter a word to be searched: ");
    scanf("%s", search);
    printf("Enter a word to be replaced: ");
    scanf("%s", replace);
    char word[100];
    while(!feof(file)){
        fscanf(file, "%s", word);
        if(!strcmp(search, word)){
            fprintf(file1, "%s ", replace);
        } else {
            fprintf(file1, "%s ", word);
        }
    }
    fclose(file);
    fclose(file1);
    remove("file.txt");
    rename("file1.txt", "file.txt");
}