#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node_t;
typedef node_t *nodep_t;
nodep_t create(int data){
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main(){
    int n, data, item, x, y;
    int i, j;
    nodep_t head, p, newNode, pop;
    scanf("%d", &n);
    getchar();
    scanf("%d", &data);
    head = create(data);
    p = head;
    for(i=1; i<n; i++){
        scanf("%d", &data);
        newNode = create(data);
        p->next = newNode;
        p = newNode;
    }
    while(1){
        scanf("%d", &item);
        if(item == 1){
            scanf("%d", &x);
            getchar();
            newNode = create(x);
            if(head == NULL){
                head = newNode;
            }
            else{
                p = head;
                while(p->next != NULL){
                    p = p->next;
                }
                p->next = newNode;
            }
        }
        else if(item == 2){
            scanf("%d %d", &x, &y);
            getchar();
            p = head;
            while(p != NULL){
                if(p->data == x){
                    newNode = create(y);
                    newNode->next = p->next;
                    p->next = newNode;
                    break;
                }
                else{
                    p = p->next;
                }
            }
        }
        else if(item == 3){
            scanf("%d", &x);
            getchar();
            if(head->data == x){
                pop = head;
                head = head->next;
                free(pop);
            }
            else{
                p = head;
                while(p->next != NULL){
                    if(p->next->data == x){
                        pop = p->next;
                        p->next = pop->next;
                        free(pop);
                        break;
                    }
                    p = p->next;
                }
            }
        }
        else if(item == 4){
            getchar();
            if(head != NULL){
                pop = head;
                head = head->next;
                free(pop);
            }
        }
        else if(item == 5){
            getchar();
            if(head != NULL){
                if(head->next == NULL){
                    free(head);
                    head = NULL;
                }
                else{
                    p = head;
                    while(p->next != NULL){
                        // printf("p:%d\n", p->data);
                        if(p->next->next == NULL){
                            pop = p->next;
                            p->next = NULL;
                            free(pop);
                            break;
                        }
                        p = p->next;
                    }
                }
            }
        }
        else{
            if(head == NULL){
                printf("None any node");
            }
            else{
                p = head;
                while(p != NULL){
                    printf("%d ", p->data);
                    p = p->next;
                }
            }
            break;
        }
        // if(head == NULL){
        //     printf("None any node");
        // }
        // else{
        //     p = head;
        //     while(p != NULL){
        //         printf("%d ", p->data);
        //         p = p->next;
        //     }
        // }
        // printf("\n");
    }
    return 0;
}