#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void worse_kind_of_scenario();


int main() {
    int* pointer;
    worse_kind_of_scenario();
    do{
        *(pointer + rand()) = rand();
    }
    while(1);
    return 0;
}

void worse_kind_of_scenario(){
    char char_array[] = "Good bye...";
    int i;
    i = strlen(char_array);
    char_array[i] = '.';
    gets(char_array);
    strcpy(char_array, "Really long string................");
    puts(char_array);
    
}
