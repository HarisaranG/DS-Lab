#include<stdio.h>

int main() {
    char x[] = "file.txt";
    FILE* file = fopen(x, "a+"); 
    if (file == NULL) { 
        printf("Unable to open/detect file"); 
        return 1; 
    } 
    fprintf(file, "\n"); 
    fseek(file, 0, 0); 
    int ch = 0; 
    char buffer[100]; 
    while (fgets(buffer, sizeof(buffer), file)) { 
        if (!(ch % 2)) { 
            printf("%s", buffer); 
        } 
        ch++; 
    } 
    ch = 1; 
    fseek(file, 0, 0);
    while (fgets(buffer, sizeof(buffer), file)) { 
        if (!(ch % 2)) { 
            printf("%s", buffer); 
        } 
        ch++; 
    }
    fclose(file); 
    return 0;
}