#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node_s{
    char data[1];
    struct node_s *next;
    struct node_s *previous;
} node_t;
typedef node_t *nodep_t;

nodep_t create(char data){
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data[0] = data;
    newNode->next = NULL;
    return newNode;
}

int main(){
    char s[100], it[100], swap[1];
    int i, j;
    scanf("%[^\n]", s);
    getchar();
    scanf("%[^\n]", it);
    // printf("%s %s\n", s, it);

    // gets(s);
    // getchar();
    // gets(it);

    nodep_t head = create(s[0]);
    nodep_t newNode;
    nodep_t p = head;
    p->previous = NULL;
    i = 1;
    while(s[i] != '\0'){
        newNode = create(s[i]);
        p->next = newNode;
        newNode->previous = p;
        p = newNode;
        i++;
    }
    newNode = create('\0');
    p->next = newNode;
    newNode->previous = p;  
    nodep_t current = head, temp;

    i = 0;
    while(it[i] != '\0'){
        if(it[i] == '0'){
            while(current->previous != NULL){
                current = current->previous;
            }
            head = current;
        }
        else if(it[i] == '$'){
            while(current->next != NULL){
                current = current->next;
            }
        }
        else if(it[i] == 'x'){
            if(current->data[0] != '\0' && current->previous != NULL){
                current->previous->next = current->next;
                current->next->previous = current->previous;
                temp = current;
                current = current->next;
                free(temp);
            }
            if(current->data[0] != '\0' && current->previous == NULL){
                temp = current;
                current = current->next;
                current->previous = NULL;
                free(temp);
            }
        }
        else if(it[i] == 's'){
            if(current->data[0] != '\0' && current->next->data[0] != '\0'){
                swap[0] = current->data[0];
                current->data[0] = current->next->data[0];
                current->next->data[0] = swap[0];
            }
        }
        else if(it[i] == 'i'){
            newNode = create(it[i+1]);
            if(current->previous != NULL){
                current->previous->next = newNode;
                newNode->next = current;
                newNode->previous = current->previous;
                current->previous = newNode;
            }
            else{
                newNode->next = current;
                current->previous = newNode;
                newNode->previous = NULL;
            }
            i++;
        }
        else if(it[i] == 'u'){
            if(current->data[0] != ' '){
                current->data[0] = toupper(current->data[0]);
            }
            // printf("%c\n", current->data[0]);
            current = current->next;
        }
        else if(it[i] == '+'){
            current = current->next;
            // printf("%c\n", current->data[0]);
        }
        else{
            current = current->previous;
            // printf("%c\n", current->data[0]);
        }
        i++;
        // temp = current;
        // while(temp->previous != NULL){
        //     temp = temp->previous;
        // }
        // while(temp != NULL){
        //     printf("%c", temp->data[0]);
        //     temp = temp->next;
        // }
    }
    temp = current;
    while(temp->previous != NULL){
        temp = temp->previous;
    }
    while(temp->next != NULL){
        printf("%c", temp->data[0]);
        temp = temp->next;
    }
    return 0;
}