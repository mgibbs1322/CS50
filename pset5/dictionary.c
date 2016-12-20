/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

node * trieTree;
int wordsInDictionary = 0;

int charNumber(char c){
    if (c == '\''){
        return 26;
    }else if(c >= 'A' && c <='Z'){
        c+=32;
    }
    int num = c - 'a';
    return num;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    trieTree = (node*)malloc(sizeof(node));
    FILE * infile = fopen(dictionary, "r");
    if(infile==NULL){
        fclose(infile);
        return false;
    }
    
    char* word = malloc(sizeof(char)*45);
    char * place = word;
    while(fscanf(infile, "%s\n", word)!=EOF){
        node * traverse = trieTree;
        while(*word!='\0'){
            if(traverse->next_char[charNumber(*word)]==NULL){
                node * new_node = (node*)malloc(sizeof(node));
                traverse->next_char[charNumber(*word)] = new_node;
            }
            traverse = traverse->next_char[charNumber(*word)];
            ++word;
        }
        traverse->isWord = true;
        wordsInDictionary++;
        word = place;
    }
    fclose(infile);
    free(word);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordsInDictionary;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
