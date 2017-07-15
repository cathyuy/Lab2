#include <stdio.h>
#include "arraysort.h"

void test_createlist() {
    list * theList = createlist(10);
    int i;
    for (i=0; i < 10; i++) 
        printf("%d \n", theList->sortedList[i]);
    
    printf("%d", theList->maxSize);
}

void test_insert() {
    
}


int main() {   
    test_createlist();
       
}
