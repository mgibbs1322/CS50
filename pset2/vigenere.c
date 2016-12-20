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
        return 1;
    }else{
        string k = argv[1];
        int kArr[strlen(k)];
        int kCipher;
        for(int x = 0, p = strlen(k); x < p; x++){
            kCipher = (int)k[x];
            if((kCipher > 64) && (kCipher < 91)){
                kArr[x] = kCipher - 65;
            }else if((kCipher > 96) && (kCipher < 123)){
                kArr[x] = kCipher - 97;
            }else{
                printf("Illegal keyword character entered!\n");
                return 1;
            }
        }
        //printf("Enter the message to be encrypted: ");
        string message = GetString();

        int kIterator = 0;
        int cipheredChar;
        
        for(int i = 0, n = strlen(message); i < n; i++){
            int ascii = (int)message[i];
            int kPos = kIterator % strlen(k);
            if((ascii > 64) && (ascii < 91)){
                if (ascii + kArr[kPos] > 90){
                    cipheredChar = (ascii + kArr[kPos]) - 26;
                    kIterator++;
                }else{
                    cipheredChar = ascii + kArr[kPos];
                    kIterator++;
                }
            }else if((ascii > 96) && (ascii < 123)){
                if(ascii + kArr[kPos] > 122){
                    cipheredChar = (ascii + kArr[kPos]) - 26;
                    kIterator++;
                }else{
                    cipheredChar = ascii + kArr[kPos];
                    kIterator++;
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
