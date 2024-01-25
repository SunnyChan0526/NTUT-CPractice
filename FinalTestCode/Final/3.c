#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int data;
    struct node_s *next, *pv; 
} node_t;
typedef node_t* nodep_t;
nodep_t create(int data){
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->next = NULL;
    newNode->pv = NULL;
    newNode->data = data;
    return newNode;
}

int main(){
    int n, m, add, select, x, y, xYes, yYes;
    nodep_t head = NULL, tail = NULL, p, newNode, pop, xp, yp, typ;
    scanf("%d", &n);
    getchar();
    scanf("%d", &add);
    head = create(add);
    p = head;
    for(int i=1; i<n; i++){
        scanf("%d", &add);
        newNode = create(add);
        p->next = newNode;
        newNode->pv = p;
        p = p->next;
    }
    tail = p;
    scanf("%d", &m);
    getchar();
    for(int i=0; i<m; i++){
        scanf("%d", &select);
        if(select == 1){
            // if(tail == NULL){
            //     printf("YES!\n");
            // }
            // else{
            //     printf("tail:%d\n", tail->data);
            // }
            scanf("%d", &x);
            newNode = create(x);
            if(tail != NULL){
                tail->next = newNode;
                newNode->pv = tail;
                tail = newNode;
            }
            else{
                head = tail = newNode;
            }
        }
        else if(select == 2){
            if(head != NULL){
                pop = head;
                head = head->next;
                if(head != NULL){
                    head->pv = NULL;
                }
                if(tail->pv == NULL){
                    tail = NULL;
                }
                free(pop);
            }
        }
        else if(select == 3){
            // printf("tail head :%d %d\n", tail->data, head->data);
            p = head;
            // if(p == NULL){
            //     // printf("None");
            // }
            // else{
            //     while(p != NULL){
            //         printf("%d ", p->data);
            //         p = p->next;
            //     }
            // }
            if(tail != NULL){
                pop = tail;
                tail = tail->pv;
                // printf("tail:%d\n", tail->data);
                if(tail != NULL){
                    tail->pv = NULL;
                }
                free(pop);
                tail->next = NULL;
            }
        }
        else if(select == 4){
            scanf("%d", &x);
            p = head;
            while(p != NULL){
                if(p->data == x){
                    pop = p;
                    p->pv->next = p->next;
                    p->next->pv = p->pv;
                    free(pop);
                }
                p = p->next;
            }
        }
        else if(select == 5){
            scanf("%d %d", &x, &y);
            p = head;
            while(p != NULL){
                if(p->data == x){
                    newNode = create(y);
                    p->next = newNode;
                    newNode->pv = p;
                    newNode->next = p->next->next;
                    p->next->next->pv = newNode;
                }
                p = p->next;
            }
        }
        else if(select == 6){

        }
        else{
            scanf("%d %d", &x, &y);
            p = head;
            xYes = yYes = 0;
            while(p != NULL){
                if(p->data == x){
                    xp = p;
                    xYes = 1;
                }
                if(p->data == y){
                    yp = p;
                    yYes = 1;
                }
                p = p->next;
            }
            if(xYes == 1 && yYes == 1){
                // txp = xp;
                typ = yp;
                xp->pv->next = yp;
                yp->pv = xp->pv;
                yp->next = xp->next;
                yp->next->pv = yp;


                typ->pv->next = xp;
                xp->pv = typ->pv;
                xp->next = typ->next;
                typ->next->pv = xp;
            }
            // p = tail;
            // if(p == NULL){
            //     printf("None");
            // }
            // else{
            //     while(p != NULL){
            //         printf("%d ", p->data);
            //         p = p->pv;
            //     }
            // }
        }
        getchar();
        // p = head;
        // if(p == NULL){
        //     printf("None");
        // }
        // else{
        //     while(p != NULL){
        //         printf("%d ", p->data);
        //         p = p->next;
        //     }
        // }
    }
    p = head;
    if(p == NULL){
        printf("None");
    }
    else{
        while(p != NULL){
            printf("%d ", p->data);
            p = p->next;
        }
    }
    return 0;
}