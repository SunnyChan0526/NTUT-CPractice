#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s { 
    char c[2];
    struct node_s * right, * left, * next; 
} tree_t;
typedef tree_t * btree;
btree create(char c[2]){
    btree newNode;
    newNode = (btree)malloc(sizeof(tree_t));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->c[0] = c[0];
    return newNode;
}

btree graph(char in1[20], char in2[20], char select1[2], char select2[2], int headC, btree* head){
    char n[2], l1[20], l2[20], r1[20], r2[20];
    int len1, len2, nPoint, l1Len, l2Len, r1Len, r2Len;
    int i, j;
    len1 = strlen(in1);
    len2 = strlen(in2);
    btree newNode;

    if(in1[0] == '\0' && in2[0] == '\0'){
        return NULL;
    }
    else if(in1[0] == '\0'){
        return create(&in2[0]);
    }
    else if (in2[0] == '\0'){
        return create(&in1[0]);
    }
    else{
        for(i=0; i<20; i++){
            in1[i] = '\0';
            in2[i] = '\0';
        }
        if(select1[0] == 'P'){
            n[0] = in1[0];
        }
        else if(select1[0] == 'O'){
            n[0] = in1[len1-1];
        }
        if(select2[0] == 'P'){
            n[0] = in2[0];
        }
        else if(select2[0] == 'O'){
            n[0] = in2[len2-1];
        }

        if(select1[0] == 'I'){
            for(i=0; i<len1; i++){
                if(in1[i] == n[0]){
                    nPoint = i;
                    break;
                }
            }
            for(i=0; i<nPoint; i++){
                l1[i] = in1[i];
            }
            l1[i] = '\0';
            for(i=nPoint+1; i<len1; i++){
                r1[i-nPoint-1] = in1[i];
            }
            r1[i-nPoint-1] = '\0';

            l1Len = strlen(l1);
            if(select2[0] == 'P'){
                for(i=1; i<=l1Len; i++){
                    l2[i-1] = in2[i];
                }
                l2[i-1] = '\0';
                for(i=l1Len+1; i<len2; i++){
                    r2[i-l1Len-1] = in2[i];
                }
                r2[i-l1Len-1] = '\0';
            }
            else if(select2[0] == 'O'){
                for(i=0; i<l1Len; i++){
                    l2[i] = in2[i];
                }
                l2[i] = '\0';
                for(i=l1Len; i<len2-1; i++){
                    r2[i-l1Len] = in2[i];
                }
                r2[i-l1Len] = '\0';
            }
        }
        else if(select2[0] == 'I'){
            for(i=0; i<len2; i++){
                if(in2[i] == n[0]){
                    nPoint = i;
                    break;
                }
            }
            for(i=0; i<nPoint; i++){
                l2[i] = in2[i];
            }
            l2[i] = '\0';
            for(i=nPoint+1; i<len2; i++){
                r2[i-nPoint-1] = in2[i];
            }
            r2[i-nPoint-1] = '\0';

            l2Len = strlen(l2);
            if(select1[0] == 'P'){
                for(i=1; i<=l2Len; i++){
                    l1[i-1] = in1[i];
                }
                l1[i-1] = '\0';
                for(i=l2Len+1; i<len1; i++){
                    r1[i-l2Len-1] = in1[i];
                }
                r1[i-l2Len-1] = '\0';
            }
            else if(select1[0] == 'O'){
                for(i=0; i<l2Len; i++){
                    l1[i] = in1[i];
                }
                l1[i] = '\0';
                for(i=l2Len; i<len1-1; i++){
                    r1[i-l2Len] = in1[i];
                }
                r1[i-l2Len] = '\0';
            }
        }
        newNode = create(n);
        if(headC == 0){
            *head = newNode;
            // printf("head:%d\n", head->c[0]);
            headC++;    
        }
        newNode->left = graph(l1, l2, select1, select2, headC, head);
        newNode->right = graph(r1, r2, select1, select2, headC, head);
        printf("%c %c %c\n", newNode->c[0], newNode->left->c[0], newNode->right->c[0]);
        return newNode;
    }
}

void print(btree head){
    btree front, tail, p, newNode, pop;
    front = create(&head->c[0]);
    p = tail = front;
    while(p != NULL){
        printf("%c", p->c[0]);
        if(p->left != NULL){
            newNode = create(&p->left->c[0]);
            tail->next = newNode;
            tail = tail->next;
        }
        if(p->right != NULL){
            newNode = create(&p->right->c[0]);
            tail->next = newNode;
            tail = tail->next;
        }
        p = p->next;
    }
}

int main(){
    int n, headC = 0;
    char in1[20], in2[20], select1[2], select2[2];
    btree head;
    scanf("%d", &n);
    getchar();
    scanf("%c", &select1[0]);
    getchar();
    scanf("%s", in1);
    getchar();
    scanf("%c", &select2[0]);
    getchar();
    scanf("%s", in2);

    graph(in1, in2, select1, select2, headC, &head);
    printf("head:%d\n", head->c[0]);
    print(head);

    return 0;
}