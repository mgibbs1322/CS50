#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



typedef struct Node{
    int data;
    struct Node * next;
} node;

void insert_end(node*, int);
void print_list(node*);
void insert_beg(node**,int);
void free_mem(node*);

int main(){
    
    node * start = (node*)malloc(sizeof(node));
    
    if(start==NULL)
        return 1;
    start->data = 5;
    
    insert_end(start, 20);
    insert_end(start, 30);
    insert_beg(&start, 2);
    insert_beg(&start, 1);
    insert_end(start, 100);

    print_list(start);
    free_mem(start);
    
    return 0;
}


void insert_end(node * start, int val){
    node * current = start;
    while(current->next!=NULL){
        current = current->next;
    }
    
    current->next = (node*)malloc(sizeof(node));
    current->next->data = val;
    current->next->next = NULL;
}

void print_list(node * start){
    node * current = start;
    
    while(current!=NULL){
        printf("%i\n", current->data);
        current = current->next;
    }
}

void insert_beg(node ** start, int val){
    node * new_start = (node*)malloc(sizeof(node));
    
    new_start->data = val;
    new_start->next = *start;
    *start = new_start;
}

void free_mem(node * start){
    node * curr;
    while((curr = start)!=NULL){
        start = start->next;
        free(curr);
    }
}
