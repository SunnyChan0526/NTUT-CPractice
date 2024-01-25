#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    struct node *next;
    char name[15];
    int age;
    int birthY, birthM, birthD;
} node_t;
typedef node_t *nodep_t;
nodep_t create(char name[15], int age, int birthY, int birthM, int birthD){
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(node_t));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->birthY = birthY;
    newNode->birthM = birthM;
    newNode->birthD = birthD;
    newNode->next = NULL;
    return newNode;
}

int main(){
    char name[15];
    int select, x, age, birthY, birthM, birthD, n;
    nodep_t top = NULL, p = NULL, pop;
    while(1){
        scanf("%d", &select);
        if(select == 1){
            scanf("%s %d %d %d %d", name, &age, &birthY, &birthM, &birthD);
            getchar();
            p = top;
            top = create(name, age, birthY, birthM, birthD);
            top->next = p;
            p = top;
        }
        else if(select == 2){
            scanf("%d", &x);
            getchar();
            if(top == NULL){
                printf("The Stack is empty\n");
            }
            else{
                if(x == 1){
                        printf("%s\n", top->name);
                }
                else if(x == 2){
                        printf("%d\n", top->age);
                }
                else{
                        printf("%d_%d_%d\n", top->birthY, top->birthM, top->birthD);
                }
                pop = top;
                top = top->next;
                free(pop);
            }
        }
        else if(select == 3){
            getchar();
            if(top == NULL){
                printf("The Stack is empty\n");
            }
            else{
                while(top != NULL){
                    printf("%s %d %d_%d_%d\n", top->name, top->age, top->birthY, top->birthM, top->birthD);
                    pop = top;
                    top = top->next;
                    free(pop);
                }
            }
        }
        else if(select == 4){
            getchar();
            p = top;
            if(p == NULL){
                printf("The Stack is empty\n");
            }
            else{
                while(p != NULL){
                    printf("%s %d %d_%d_%d\n", p->name, p->age, p->birthY, p->birthM, p->birthD);
                    p = p->next;
                }
            }
        }
        else{
            n = 0;
            p = top;
            while(p != NULL){
                n++;
                p = p->next;
            }
            printf("%d", n);
            break;
        }
        // printf("----\n");
        // p = top;
        // if(p == NULL){
        //     printf("The Stack is empty\n");
        // }
        // else{
        //     while(p != NULL){
        //         printf("%s %d %d_%d_%d\n", p->name, p->age, p->birthY, p->birthM, p->birthD);
        //         p = p->next;
        //     }
        // }
        // printf("----\n");
    }
    return 0;
}