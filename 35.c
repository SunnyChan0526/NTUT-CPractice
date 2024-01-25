#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    char point[2];
    struct node *next, *pv, *below;
} node_t;
typedef node_t *node_p;

node_p create(int data){
    node_p newNode;
    newNode = (node_p)malloc(sizeof(node_t));
    newNode->next = NULL;
    newNode->pv = NULL;
    newNode->below = NULL;
    newNode->data = data;
    return newNode;
}

void mul(char s1t[200], char s2t[200], int ts){
    node_p head, primeHead, newNode, p, h1 = NULL, x, y, px, ansHead, ansTail;
    int len1, len2, mul, s, c, cc, ans, lenAns, dot, final;
    int i, j, k, h;
    int fn[200], fnt[200];
    len1 = strlen(s1t);
    len2 = strlen(s2t);
    // printf("len:%d %d\n", len1, len2);
    cc = 0; 
    for(i=len2-1; i>=0; i--){
        h = 0;
        if(i != len2-1){
            h1 = h1->next;
        }
        for(j=len1-1; j>=0; j--){
            mul = (s2t[i]-48) * (s1t[j]-48);
            // printf("st:%c %c\n", s1t[j], s2t[i]);
            // printf("mul:%d\n", mul);
            if(mul<10){
                s = mul;
                c = 0;
            }
            else{
                s = mul%10;
                c = mul/10;
            }

            if(h == 0){
                newNode = create(s+cc);
                head = newNode;
                p = newNode;
                head->below = NULL;
                if(h == 0 && i == len2-1 && j == len1-1){
                    primeHead = newNode;
                }
                else{
                    h1->below = head;
                    h1 = h1->next;
                }
            }
            else{
                newNode = create(s+cc);
                p->next = newNode;
                p = newNode;
                if(h1 != NULL){
                    h1->below = newNode;
                    h1 = h1->next;
                }
            }
            cc = c;
            h++;
        }
        h1 = head;
        if(cc != 0){
            newNode = create(cc);
            p->next = newNode;
        }
    }
    if(cc != 0){
        newNode = create(cc);
        p->next = newNode;
    }

    ansHead = create(primeHead->data);
    p = ansHead;
    x = primeHead->next;
    c = 0;
    while(1){
        ans = 0;
        if(x == NULL){
            if(px->below == NULL){
                break;
            }
            x = px->below->next; 
        }
        y = x;
        while(y != NULL){
            // printf("%d ", y->data);
            ans += y->data;
            y = y->below;
        }
        ans += c;
        if(ans<10){
            s = ans;
            c = 0;
        }
        else{
            s = ans%10;
            c = ans/10;
        }
        newNode = create(s);
        p->next = newNode;
        newNode->pv = p;
        p = newNode;
        // printf("\n");
        px = x;
        x = x->next;
    }
    p = ansHead;
    lenAns = 0;
    while(p->next != NULL){
        p = p->next;
        lenAns++;
    }
    dot = lenAns+1 - ts;
    ansTail = p;
    p = ansTail;
    // printf("dot len ts:%d %d %d\n", dot, lenAns, ts);
    for(i=0; i<=dot; i++){
        p = p->pv;
    }
    i = dot+1;
    final = 0;
    while(p != NULL){
        if(p->data != 0){
            final = i;
        }
        i++;
        p = p->pv;
    }

    p = ansTail;
    i = 0;
    // printf("fn:%d\n", final);
    while(p != NULL){
        printf("%d", p->data);
        p = p->pv;
        i++;
        if(i == final+1){
            break;
        }
        if(i == dot){
            if(final == 0){
                break;
            }
            else{
                printf(".");
            }
        }
    }
}

int main(){
    char s1[200], s2[200], s1t[200], s2t[200];
    int s1dot = 0, s2dot = 0, len1, len2, ts = 0;
    int i = 0, j = 0; 
    scanf("%s\n%s", s1, s2);
    len1 = strlen(s1);
    len2 = strlen(s2); 
    for(i=0; i<200; i++){
        if(s1[i] == '-'){
            continue;
        }
        if(s1[i] == '.'){
            s1dot = i;
            continue;
        }
        else{
            s1t[j] = s1[i];
            j++;
        }
    }
    j = 0;
    for(i=0; i<200; i++){
        if(s2[i] == '-'){
            continue;
        }
        if(s2[i] == '.'){
            s2dot = i;
            continue;
        }
        else{
            s2t[j] = s2[i];
            j++;
        }
    }
    if(s1dot != 0){
        s1dot = len1-s1dot-1;
    }
    if(s2dot != 0){
        s2dot = len2-s2dot-1;
    }
    ts = s1dot + s2dot;
    printf("dot1 dot2 ts:%d %d %d\n", s1dot, s2dot, ts);
    // printf("%d\n", ts);
    mul(s1t, s2t, ts);
    return 0;
}