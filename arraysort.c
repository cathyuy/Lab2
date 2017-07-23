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
    //allocate memory for list struct
    list * theList = malloc(sizeof(list));
   
     //allocate memory for array storing elements
    theList->sortedList = malloc(sizeof(int)*maxElements);
    
    //initialize list fields
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
 
    //ls null ptr check
    if (!ls) {   
        return -1;
    }
    
    //list is full   
    if (size == ls->maxSize) {
        //allocate memory for larger array
        int ** oldListptr = &(ls->sortedList);
        int * newList = malloc(sizeof(int)*(size*2));
        //copy contents of smaller old list to bigger list
        for (i = 0; i < size; i++) {
            newList[i] = ls->sortedList[i];
        } 
        //delete smaller old list
        free(*oldListptr); 
        *oldListptr = NULL;
        ls->sortedList = newList;
    }    
    
    //if first item insertion
    if (size == 0) {     
        ls->sortedList[0] = val;   
        (ls->size)++;
        return 0;
    }
    
    //find insertion location
    for (i = 0; i < size; i++) {  
        //inserting in middle
        if (val <= ls->sortedList[i]) {   
            //shift right
            for (j = size-1; j >= i; j--) 
                ls->sortedList[j+1] = ls->sortedList[j];  
            //insert item & update list size
            ls->sortedList[i] = val;      
            (ls->size)++;
            return i;
        }
        //item is new max element
        if (i == size-1) {         
            ls->sortedList[i+1] = val;
            (ls->size)++;
            return i;
        }
    }
   
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
   
    //ls null ptr check
    if (!ls) {                           
        return -1;                                                              
    }       
   
    //list is empty, remove failed
    if(size == 0) {     
        return -1;
    }
   
    //find item to remove
    for(i = 0; i < size; i++) {     
        //item found
        if(ls->sortedList[i] == val) {
            int j;
            //shift list when item is found
            for(j = i; j < size; j++) {
                ls->sortedList[j] = ls->sortedList[j+1];
            }
            //update list size & num items removed
            (ls->size)--;
            size = ls->size;
            items++;
            i--;
        }
    }
    return items;


}

/**
 * This function takes a pointer to the the list as input and returns the
 * maximum value in the list OR -1 if the list is empty.
 */
int get_max_value(list *ls)
{
    //list is empty   
    if(ls->size == 0) {
        return -1;
    } 
    //return last element
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
    //list is empty
    if(ls->size == 0){
        return -1;
    }
    //return first element
    else{
        return ls->sortedList[0];
    }
}

/**
 * This function returns the index of the first occurrence of 'val' in the
 * list. It returns -1 if the value 'val' is not present in the list.
 */
int search(list *ls, int val){
    int i;
    //ls null ptr check
    if (!ls) {  
        return -1;
    }
    
    //check each index if it contains the key   
    for (i = 0; i < ls->size; i++) {
        if (ls->sortedList[i] == val)
            return i;
    }
    return -1;     
}

/**
 * This function returns the minimum value from the list and removes it from the
 * list. It returns -1 if the list is empty.
 */
int pop_min(list *ls){
    int i;
    int size = ls->size;
    //ls null ptr check
    if(!ls) {
        return -1;                                                              
    }          
    //list is empty, pop failed   
    if(size == 0){
        return -1;
    }
    //save min value & shift items left
    else {
        int min = ls->sortedList[0];
        for(i = 0; i < size-1; i++){
            ls->sortedList[i] = ls->sortedList[i+1];
        }    
        (ls->size)--;
        return min;
    }   
}

/**
 * This function print the contents of the sorted list on a single line as follows:
 * 1 4 6 7 8
 */
void print(list *ls){
    int i;
    
    //ls null ptr check
    if (!ls) {
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
