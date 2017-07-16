#include <stdio.h>
#include <stdlib.h>

#include "arraysort.h"
/**
 * This function creates an empty list, with space allocated for an array of
 * maxElements ints (pointed to by int *sortedList) and returns a pointer to the
 * list.
 */
list* createlist(int maxElements)
{
    list * theList = malloc(sizeof(list));
    theList->sortedList = malloc(sizeof(int)*maxElements);
    theList->maxSize = maxElements;
    theList->size = 0;
    return theList;
}

/**
 * This function takes a pointer to the list and an integer value as input. It
 * should insert the value 'val' into sortedList, update the number of elements
 * in the list and return the index where the element was inserted. If the list
 * is full before inserting the element, it should increase the size of the list
 * to double its previous size and then insert the element. If the result of the
 * insert was not successful it should return -1. Note that the resulting list
 * should be sorted and there should be no information loss. The function should
 * return -1 if no valid list was passed to it..
 */
int insert(list *ls, int val)
{
    int i, j;
    int size = ls->size;
 
    if (!ls) {       // Null pointer check & debug message
        printf("ERROR: List pointer is null!!\n");
        return -1;
    }
        
    if (size == ls->maxSize) {      // list is full
        int ** oldListptr = &(ls->sortedList);
        int * newList = malloc(sizeof(int)*(size*2));
        for (i = 0; i < size; i++) {
            newList[i] = ls->sortedList[i];
        } 
        ls->sortedList = newList;
        free(*oldListptr);    
    }    
    
    if (size == 0) {     //first item insertion
        ls->sortedList[0] = val;   
        (ls->size)++;
        printf("First insert successful!\n");
        print(ls);
        return 0;
    }
    

    
    for (i = 0; i < size; i++) {      // iterate through the list
        if (val <= ls->sortedList[i]) {    // stop at successor
            for (j = size-1; j >= i; j--)    // shift right
                ls->sortedList[j+1] = ls->sortedList[j];  
            ls->sortedList[i] = val;       // insert val
            (ls->size)++;
            printf("Insertion Successful: ");
            print(ls);
            return i;
        }
        
        if (i == size-1) {    // stop if empty space is found      
            ls->sortedList[i+1] = val;
            (ls->size)++;
            printf("Insertion Successful: ");
            print(ls);
            return i;
        }
    }
    
    printf("Oops, something went wrong with the insertion\n");
    return -1;   
}

/**
 * This function takes a pointer to the list and an integer value as input. It
 * should delete all instances of elements in the sortedList with value 'val',
 * update the number of elements remaining in the list and return the number of
 * elements that were deleted. Once again the resulting list should be sorted.
 */
int remove_val(list *ls, int val)
{
    int i;
    int size = ls->size;
    int items = 0;
   
    if (!ls) {       // Null pointer check & debug message                      
        printf("ERROR: List pointer is null!!\n");                              
        return -1;                                                              
    }       

    if(size == 0) {
        printf("NO ELEMENTS TO DELETE \n");
        return -1;
    }
    
    for(i = 0; i < size; i++) {
        if(ls->sortedList[i] == val) {
            int j;
            for(j = i; j < size; j++) {
                ls->sortedList[j] = ls->sortedList[j+1];
            }
            (ls->size)--;
            size = ls->size;
            items++;
            i--;
        }
    }
    print(ls);
    return items;


}

/**
 * This function takes a pointer to the the list as input and returns the
 * maximum value in the list OR -1 if the list is empty.
 */
int get_max_value(list *ls)
{
    
    if(ls->size == 0) {
        return -1;
    } 
    else { 
        int size = ls->size;
        return ls->sortedList[size-1];
    }
}

/**
 * This function takes a pointer to the list and returns the minimum value in
 * the list OR -1 if the list is empty.
 */
int get_min_value(list *ls){
    if(ls->size == 0){
        return -1;
    }
    else{
        return ls->sortedList[0];
    }
}

/**
 * This function returns the index of the first occurrence of 'val' in the
 * list. It returns -1 if the value 'val' is not present in the list.
 */
int search(list *ls, int val){
}

/**
 * This function returns the minimum value from the list and removes it from the
 * list. It returns -1 if the list is empty.
 */
int pop_min(list *ls){
}

/**
 * This function print the contents of the sorted list on a single line as follows:
 * 1 4 6 7 8
 */
void print(list *ls){
    int i;
    
    if (!ls) {
        printf("ERROR: List pointer is null!!\n");
        return;
    }
    
    for (i = 0; i < ls->size; i++) 
        printf("%d ", ls->sortedList[i]);
    printf("\n");
}

/**
 * Identical to get_min_value(), but implemented in ARM assembly
 * (use given file get_min_ARM.s)
 */
int get_min_ARM(list *ls);

/**
 * Identical to get_max_value(), but implemented in ARM assembly
 * (use given file get_max_ARM.s)
 */
int get_max_ARM(list *ls);
