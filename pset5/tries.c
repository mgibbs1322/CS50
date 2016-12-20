#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node{
    bool isWord;
    struct Node * next_char[27];
}node;

node * trieTree = NULL;
unsigned int wordsInDictionary = 0;
unsigned int childNodes = 0;


void insert(node*,char*);
bool searchWord(node*, char*);
bool load(const char*);
bool unload(node*);
int charNumber(char);
bool check(const char*);
unsigned int size(void);
unsigned int nodeCount(void);


int main(){
    
    trieTree = (node*)malloc(sizeof(node));
    if(!load("dictionaries/large")){
        printf("Could not load dictionary..");
        return 1;
    }
    printf("Words: %d\n", size());
    printf("Nodes: %d\n", nodeCount());
    printf("%d\n", unload(trieTree));
    return 0;
}

void insert(node * start, char * word){
    node * traverse = start;
    while(*word!='\0'){
        if(traverse->next_char[*word - 'a']==NULL){
            node * new_node = (node*)malloc(sizeof(node));
            traverse->next_char[*word- 'a'] = new_node;
        }
        traverse = traverse->next_char[*word - 'a'];
        ++word;
    }
    traverse->isWord = true;
}

bool check(char * word){
    node * traverse = trieTree;
    while(*word!='\0'){
        if(traverse->next_char[charNumber(*word)]!=NULL){
            traverse = traverse->next_char[charNumber(*word)];
            ++word;
        }else
            break;
    }
    
    if(*word == '\0' && traverse->isWord == true)
        return true; 
    else
        return false;
}

bool load(const char * dictionary){
    
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
                childNodes++;
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

unsigned int size(void){
    return wordsInDictionary;
}

unsigned int nodeCount(void){
    return childNodes;
}


int charNumber(char c){
    if (c == '\''){
        return 26;
    }else if(c >= 'A' && c <='Z'){
        c+=32;
    }
    int num = c - 'a';
    return num;
}

bool unload(node * p){
    for(int i = 0; i < 27; i++){
        if(p->next_char[i]!=NULL){
            unload(p->next_char[i]);
        }
    }
    free(p);
    return true;
}
