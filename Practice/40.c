#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char c[2];   
    struct node *left, *right, *next;
} node_t;
typedef node_t *nodep_t;
nodep_t create(char c[2]){
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->c[0] = c[0];
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->next = NULL;
    return newNode;
}

nodep_t graph(char in1[20], char in2[20], char select1[2], char select2[2], int headInt, nodep_t *headp){
    char n[2], l1[20], l2[20], r1[20], r2[20];
    int lenIn1 = strlen(in1);
    int lenIn2 = strlen(in2);
    int lenR1, lenR2, lenL1, lenL2;
    int nPoint;
    int i, j;
    nodep_t newNode;
    if(in1[0] == '\0' && in2[0] == '\0'){
        return NULL;
    }
    else if(in1[0] == '\0'){
        return create(in2);
    }
    else if(in2[0] == '\0'){
        return create(in1);
    }
    else{
        for(i=0; i<10; i++){
            l1[i] = '\0';
            l2[i] = '\0';
            r1[i] = '\0';
            r2[i] = '\0';
        }
        if(select1[0] == 'P'){
            n[0] = in1[0];
        }
        else if(select1[0] == 'O'){
            n[0] = in1[lenIn1-1];
        }
        if(select2[0] == 'P'){
            n[0] = in2[0];
        }
        else if(select2[0] == 'O'){
            n[0] = in2[lenIn2-1];
        }

        if(select1[0] == 'I'){
            for(i=0; i<lenIn1; i++){ // l1 r1
                if(in1[i] == n[0]){
                    break;
                }
            }
            nPoint = i;
            for(i=0; i<nPoint; i++){
                l1[i] = in1[i];
            }
            l1[i] = '\0';
            for(i=nPoint+1; i<lenIn1; i++){
                r1[i-nPoint-1] = in1[i];
            }
            r1[i] = '\0';

            if(select2[0] == 'P'){ //NLR
                lenL1 = strlen(l1);
                for(i=1; i<=lenL1; i++){
                    l2[i-1] = in2[i];
                }
                l2[i-1] = '\0';
                for(i=lenL1+1; i<lenIn2; i++){
                    r2[i-lenL1-1] = in2[i];
                }
                r2[i-lenL1-1] = '\0';
            }
            else if(select2[0] == 'O'){ //LRN
                lenL1 = strlen(l1);
                for(i=0; i<lenL1; i++){
                    l2[i] = in2[i];
                }
                l2[i] = '\0';
                for(i=lenL1; i<lenIn2-1; i++){
                    r2[i-lenL1] = in2[i];
                }
                r2[i-lenL1] = '\0';
            }
        }
        else if(select2[0] == 'I'){
            for(i=0; i<lenIn2; i++){
                if(in2[i] == n[0]){
                    break;
                }
            }
            nPoint = i;
            for(i=0; i<nPoint; i++){
                l2[i] = in2[i];
            }
            l2[i] = '\0';
            for(i=nPoint+1; i<lenIn2; i++){
                r2[i-nPoint-1] = in2[i];
            }
            r2[i] = '\0';

            if(select1[0] == 'P'){
                lenL2 = strlen(l2);
                for(i=1; i<=lenL2; i++){
                    l1[i-1] = in1[i];
                }
                l1[i-1] = '\0';
                for(i=lenL2+1; i<lenIn1; i++){
                    r1[i-lenL2-1] = in1[i];
                }
                r1[i-lenL2-1] = '\0';
            }
            else if(select1[0] == 'O'){
                lenL2 = strlen(l2);
                for(i=0; i<lenL2; i++){
                    l1[i] = in1[i];
                }
                l1[i] = '\0';
                for(i=lenL2; i<lenIn1-1; i++){
                    r1[i-lenL2] = in1[i];
                }
                r1[i-lenL2] = '\0';
            }
        }
        newNode = create(n);
        if(headInt == 0){
            *headp = newNode;
        }
        headInt++;
        newNode->left = graph(l1, l2, select1, select2, headInt, headp);
        newNode->right = graph(r1, r2, select1, select2, headInt, headp); 
        return newNode;
    }
}
void print(nodep_t head){ //queue, level in order
    nodep_t p, front, tail, pop;
    front = head;
    p = tail = front;
    while(p != NULL){
        if(front->c[0] != '\0'){
            printf("%c", front->c[0]);
        }
        if(p->left != NULL){
            tail->next = p->left;
            tail = tail->next;
        }
        if(p->right != NULL){
            tail->next = p->right;
            tail = tail->next;
        }
        pop = front;
        front = front->next;
        free(pop);
        p = p->next;
    }
}

int main(){
    char select1[2], select2[2], in1[20], in2[20];
    int headInt = 0;
    nodep_t headp = NULL;
    scanf("%s", select1);
    getchar();
    scanf("%s", in1);
    getchar();
    scanf("%s", select2);
    getchar();
    scanf("%s", in2);
    
    graph(in1, in2, select1, select2, headInt, &headp);
    print(headp);
    return 0;
}