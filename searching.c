#include<stdio.h>
#include<string.h>

int main() {
    char bookName[20][100] = {
        "Water Wave Mechanics for Engineers and Scientists",
        "Classical and Computational Solid Mechanics",
        "3D Printing and Additive Manufacturing",
        "Introduction to Coastal Engineering and Management",
        "Fundamentals of Solid State Electronics",
        "Chemical Thermodynamics for Metals and Materials",
        "Multiphysics Modeling with Finite Element Methods",
        "Mechanics of Coastal Sediment Transport",
        "Construction Technology for Tall Buildings",
        "Smoothed Particle Hydrodynamics",
    };
    char search [100] = "Chemical Thermodynamics for Metals and Materials";
    // Linear Search
    for(int i = 0; i < 10; ++i){
        if(!strcmp(bookName[i], search)){
            printf("Search Element Found at position %d - Linear Search\n", i + 1);
        }
    }
    // Binary Search
    // Sorting First
    for(int i = 0; i < 10; ++i){
        for(int j = i + 1; j < 10; ++j){
            int minIndex = i;
            if(strcmp(bookName[i], bookName[j]) > 0){
                minIndex = j;
            }
            char temp[100];
            strcpy(temp, bookName[minIndex]);
            strcpy(bookName[minIndex], bookName[i]);
            strcpy(bookName[i], temp);
        }
    }
    int lo = 0, hi = 9;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(strcmp(bookName[mid], search) == 0){
            printf("Search Element Found - Binary Search");
            break;
        } else if(strcmp(bookName[mid], search) < 0){
            hi = mid - 1;
        } else {
            hi = mid + 1;
        }
    }
    return 0;
}