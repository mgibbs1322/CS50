#include <stdio.h>
#include <cs50.h>

int main(void){
    int minutes;
    int bottles = 0;
    
    printf("Please enter the length of the shower in minutes: ");
    minutes = GetInt();
    
    bottles = minutes * 12;
    
    printf("Water usage of a %d minute shower is equivalent to %d water bottles!\n", minutes, bottles);
}
