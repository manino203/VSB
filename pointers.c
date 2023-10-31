#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int* a, int* b){
    int pom = *b;
    *b = *a;
    *a = pom;
}

int ptr_main(){
    int x = 10;
    int y = 20;
    swap(&x, &y);

    return 0;
}