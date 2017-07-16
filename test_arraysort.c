#include <stdio.h>
#include "arraysort.h"

void test_createlist(list * lp) {
    lp = createlist(10);
    int i;
    for (i=0; i < 10; i++) 
        printf("%d \n", theList->sortedList[i]);
    
    printf("%d", theList->maxSize);
}

void test_insert() {
    
}


int main() {   
    char command = '0';
    list * theList;
    while (command != 'e') {
        printf("(c)reate list\n(i)nsert\n(r)emove_val\nget_ma(x)_value\n");
        printf("get_mi(n)_value\n(s)earch\npop_(m)in\n(p)rint\n(e)xit\n");
        printf("Please enter a command: ");
        scanf("%c", &command);
        
        switch (command) {
            case 'c':
                test_createlist(theList);
                break;
            
            case 'i':
                break;

            case 'r':
                break;

            case 'x':
                break;
            
            case 'n':
                break;
        
            case 'm':
                break;

            case 'p':
                break;

            case 'e':
                return 0;
            
            default:
                printf("Invalid command, exiting...");
                return -1;
        }
    }
        
}
