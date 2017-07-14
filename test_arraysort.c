#include <stdio.h>
#include "arraysort.h"

void test_createlist() {
    list * theList = createlist(10);
    int i;
    for (i=0; i < 10; i++) 
        printf("%d", theList->sortedList[i]);
}

void test_insert() {
    
}

int main() {   
    test_createlist();
       
}
