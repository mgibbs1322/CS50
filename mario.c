#include <cs50.h>
#include <stdio.h>

int main(void){
    
    printf("Enter pyramid height as a positive integer no greater than 23: ");
    
    int height = GetInt();
    
    while (height >= 24 || height < 0){
        printf("Enter pyramid height as a positive integer no greater than 23: ");
        height = GetInt();
    }
    
    
    int numHashes = 2;
        
    for(int i = 0; i < height; i++){
        for (int j = 0; j < (height + 1 - numHashes); j++){
            printf(" ");
        }
        for (int k = 0; k < numHashes; k++){
            printf("#");
        }
        printf("\n");
        numHashes++;
    }
}
