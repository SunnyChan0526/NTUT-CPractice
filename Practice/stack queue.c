#include <stdio.h>
#include <stdlib.h>

// typedef struct node_s {
//     int data;
//     struct node_s * next;
// } node_t;
// typedef node_t * nodep_t;

// nodep_t create(int data){
//     nodep_t newNode;
//     newNode = (nodep_t)malloc(sizeof(node_t));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// void push(nodep_t * p_top, int x) {
//     nodep_t head, newNode;
//     newNode = create(x);
//     newNode->next = *p_top;
//     *p_top = newNode;
// }
// int pop(nodep_t *p_top){
//     int data = (*p_top)->data;
//     nodep_t current = (*p_top);
//     (*p_top) = (*p_top)->next;
//     free(current);
//     return data;
// }
// void printStack(nodep_t top) {
//     nodep_t current = top;
//     while(current != NULL){
//         printf("%d ", current->data);
//         current = current->next;
//     }
// }
// int main() {
//     nodep_t top = NULL;
//     push(&top, 5);
//     push(&top, 8);
//     printStack(top); // 8 5
//     return 0;
// }

typedef struct node_s {
    int data;
    struct node_s * next;
} node_t;
typedef node_t * nodep_t;

nodep_t create(int data){
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(nodep_t *head, nodep_t *tail, int x) {
    nodep_t newNode;
    newNode = create(x);
    newNode->next = *tail;
    if(*head == NULL){
        *head = newNode;
    }
}

int dequeue(nodep_t *head) {
    if(*head != NULL){
        int data = (*head)->data;
        nodep_t current = (*head);
        (*head) = (*head)->next;
        free(current);
        return data;
    }
}
int main() {
    int x;
    nodep_t tail = NULL, head = NULL;
    enqueue(&head, &tail, 5);
    enqueue(&head, &tail, 8);
    x = dequeue(&head);
    printf("%d\n", x);
    return 0;
}