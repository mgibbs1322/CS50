#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[]){
    
    if (argc < 2){
        printf("\nNo arguments entered!\n");
        return 1;
    }else if(argc > 2){
        printf("\nToo many arguments entered!\n");
    }else{
        int k = atoi(argv[1]) % 26;
        printf("Enter the message to be encrypted: ");
        string message = GetString();
        
        int cipheredChar;
        
        for(int i = 0, n = strlen(message); i < n; i++){
            int ascii = (int)message[i];
            if((ascii > 64) && (ascii < 91)){
                if (ascii + k > 90){
                    cipheredChar = (ascii + k) - 26;
                }else{
                    cipheredChar = ascii + k;
                }
            }else if((ascii > 96) && (ascii < 123)){
                if(ascii + k > 122){
                    cipheredChar = (ascii + k) - 26;
                }else{
                    cipheredChar = ascii + k;
                }
            }else{
                cipheredChar = ascii;
            }
            printf("%c", (char)cipheredChar);
        }
        printf("\n");
        return 0;
    }
}
