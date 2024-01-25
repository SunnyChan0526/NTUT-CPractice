#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    struct node *next;
    char name[20];
    int age, birthY, birthM, birthD;
} node_t;
typedef node_t *node_p;
node_p create(char name[20], int age, int birthY, int birthM, int birthD){
    node_p newNode;
    newNode = (node_p)malloc(sizeof(node_t));
    newNode->next = NULL;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->birthY = birthY;
    newNode->birthM = birthM;
    newNode->birthD = birthD;
    return newNode;
}

int main(){
    int select, x, age, birthY, birthM, birthD, n;
    char name[20];
    node_p tail, head = NULL, p, pop;
    while(1){
        scanf("%d", &select);
        if(select == 1){
            scanf("%s %d %d %d %d", name, &age, &birthY, &birthM, &birthD);
            getchar();
            if(head == NULL){
                tail = create(name, age, birthY, birthM, birthD);
                p = tail;
                head = tail;
            }
            else{
                p = tail;
                tail = create(name, age, birthY, birthM, birthD);
                p->next = tail;
                p = tail;
            }
        }
        else if(select == 2){
            scanf("%d", &x);
            getchar();
            if(head == NULL){
                printf("The Queue is empty\n");
            }
            else{
                if(x == 1){
                    printf("%s\n", head->name);
                }
                else if(x == 2){
                    printf("%d\n", head->age);
                }
                else{
                    printf("%d_%d_%d\n", head->birthY, head->birthM, head->birthD);
                }
                pop = head;
                head = head->next;
                free(pop);
            }
        }
        else if(select == 3){
            getchar();
            if(head == NULL){
                printf("The Queue is empty\n");
            }
            else{
                while(head != NULL){
                    printf("%s %d %d_%d_%d\n", head->name, head->age, head->birthY, head->birthM, head->birthD);
                    pop = head;
                    head = head->next;
                    free(pop);
                }
            }
        }
        else if(select == 4){
            getchar();
            if(head == NULL){
                printf("The Queue is empty\n");
            }
            else{
                p = head;
                while(p != NULL){
                    printf("%s %d %d_%d_%d\n", p->name, p->age, p->birthY, p->birthM, p->birthD);
                    p = p->next;
                }
            }
        }
        else{
            n = 0;
            p = head;
            while(p != NULL){
                n++;
                p = p->next;
            }
            printf("%d", n);
            break;
        }
        // printf("---\n");
        // if(head == NULL){
        //     printf("The Queue is empty\n");
        // }
        // else{
        //     p = head;
        //     while(p != NULL){
        //         printf("%s %d %d_%d_%d\n", p->name, p->age, p->birthY, p->birthM, p->birthD);
        //         p = p->next;
        //     }
        // }
        // printf("---\n");
    }

    return 0;
}