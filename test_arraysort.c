#include <stdio.h>
#include "arraysort.h"

int main() {   
    char command = '0';
    int value;
    list * testList = createlist(10);
    while (1) {
        printf("(i)nsert\n(r)emove_val\nget_ma(x)_value\n");
        printf("get_mi(n)_value\n(s)earch\npop_(m)in\n(p)rint\n(e)xit\n");
        printf("Please enter a command: \n");
        scanf("%c", &command);
        printf("\n");
        
        switch (command) {
            case 'i':
                printf("Enter value: ");
                scanf("%d", &value);
                insert(testList, value);
                break;

            case 'r':
                printf("Enter value: ");
                scanf("%d", &value);
                remove_val(testList, value);
                break;

            case 'x':
                printf("Max value: %d/n", get_max_value(testList));
                break;
            
            case 'n':
                printf("Min value: %d/n", get_min_value(testList));
                break;
            
            case 's':
                printf("Search For: ");
                scanf("%d", &value);
                printf("Index of value: %d/n", search(testList, value));
                break;

            case 'm':
                printf("Before pop: ");
                print(testList);
                pop_min(testList);
                printf("After pop: ");
                print(testList);
                break;

            case 'p':
                print(testList);
                break;

            case 'e':
                free(testList->sortedList);
                free(testList);
                return 0;
            
        }
    }
    // Program failure
    return -1;   
}
