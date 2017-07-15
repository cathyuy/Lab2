#include <stdio.h>
#include "arraysort.h"

void test_createlist() {
    list * theList = createlist(10);
    int i;
    for (i=0; i < 10; i++) 
        printf("%d \n", theList->sortedList[i]);
}

void test_insert() {
    
}


//Comment
int main() {   
    test_createlist();
       
}
