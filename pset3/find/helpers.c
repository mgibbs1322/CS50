/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int first = 0;
    int last = n - 1;
    int middle = (first+last)/2;
    
    while (first <= last){
        if(values[middle] > value){
            last = middle - 1;
        }else if(values[middle]== value){
            printf("found at position %i", middle);
            return true;
        }else{
            first = middle + 1;
        }
        middle = (first+last)/2;
    }
    return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int temp;
    int m = n;
    bool isChange;
    
    for (int i = 0; i < n; i++){
        isChange = false;
        for(int j = 0; j < m - 1; j++ ){
            if (values[j] > values[j+1]){
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
                isChange = true;
            }
        }
        m--;
        if(isChange == false){
            break;
        }
    }
    return;
}
