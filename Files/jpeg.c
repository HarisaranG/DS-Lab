#include<stdio.h>

int main() {
    char name[30];
    scanf("%s", name);
    FILE* file = fopen(name, "r");
    if(file == NULL){
        printf("File not found");
        return 1;
    }
    unsigned char bytes[3];
    fread(bytes, 3, 1, file);
    if (bytes[0] == 0xff 
        && bytes[1] == 0xd8 
        && bytes[2] == 0xff){
            printf("This Image is in JPEG format!"); 
        }
    else{
        printf("Not in jpeg format");
    }
    return 0;
}