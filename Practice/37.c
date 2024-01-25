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

int add(nodep_t head1, nodep_t head2, int n1, int n2, int ans[20]){
    nodep_t p1, p2;
    int times = 0, i, max;
    p1 = head1;
    p2 = head2;
    if(n1 > n2){
        times = n1 - n2;
        for(i=0; i<times; i++){
            ans[n1-i] = p1->data;
            p1 = p1->next;
        }
        for(i=0; i<=n2; i++){
            ans[n2-i] = p1->data + p2->data;
            p1 = p1->next;
            p2 = p2->next;
        }
        max = n1;
    }
    else if(n1 < n2){
        times = n2 - n1;
        for(i=0; i<times; i++){
            ans[n2-i] = p2->data;
            p2 = p2->next;
        }
        for(i=0; i<=n1; i++){
            // printf("p1 p2:%d %d\n", p1->data, p2->data);
            ans[n1-i] = p1->data + p2->data;
            p1 = p1->next;
            p2 = p2->next;
        }
        max = n2;
    }
    else{
        for(i=0; i<=n1; i++){
            ans[n1-i] = p1->data + p2->data;
            p1 = p1->next;
            p2 = p2->next;
        }
        max = n1;
    }
    return max;
}
int sub(nodep_t head1, nodep_t head2, int n1, int n2, int ans[20]){
    nodep_t p1, p2;
    int times = 0, i, max;
    p1 = head1;
    p2 = head2;
    if(n1 > n2){
        times = n1 - n2;
        for(i=0; i<times; i++){
            ans[n1-i] = p1->data;
            p1 = p1->next;
        }
        for(i=0; i<=n2; i++){
            ans[n2-i] = p1->data - p2->data;
            p1 = p1->next;
            p2 = p2->next;
        }
        max = n1;
    }
    else if(n1 < n2){
        times = n2 - n1;
        for(i=0; i<times; i++){
            ans[n2-i] = -(p2->data);
            p2 = p2->next;
        }
        for(i=0; i<=n1; i++){
            // printf("p1 p2:%d %d\n", p1->data, p2->data);
            ans[n1-i] = p1->data - p2->data;
            p1 = p1->next;
            p2 = p2->next;
        }
        max = n2;
    }
    else{
        for(i=0; i<=n1; i++){
            ans[n1-i] = p1->data - p2->data;
            p1 = p1->next;
            p2 = p2->next;
        }
        max = n1;
    }
    return max;
}
int mul(nodep_t head1, nodep_t head2, int n1, int n2, int ans[20]){
    int i, j;
    nodep_t p1, p2;
    p1 = head1;
    p2 = head2;
    for(i = n1; i>=0; i--){
        for(j = n2; j>=0; j--){
            ans[i+j] += p1->data * p2->data;
            p2 = p2->next;
        }
        p1 = p1->next;
        p2 = head2;
    }
    return n1+n2;
}
void print(int ans[20], int max){
    int i, zeroCount = 0;
    for(i=max; i>=0; i--){
        if(i == max || (i == max-1 && ans[max] == 0)){
            if(ans[i] == 0){
                zeroCount++;
                continue;
            }
            else if(ans[i] == 1 || ans[i] == -1){
                if(i == 1){
                    if(ans[i] > 0){
                        printf("x");
                    }
                    else{
                        printf("-x");
                    }
                }
                else if(i == 0){
                    if(ans[i] > 0){
                        printf("%d", ans[i]);
                    }
                    else{
                        printf("%d", ans[i]);
                    }
                }
                else{
                    if(ans[i] > 0){
                        printf("x^%d", i);
                    }
                    else{
                        printf("-x^%d", i);
                    }
                }
            }
            else{
                if(i == 1){
                    printf("%dx", ans[i]);
                }
                else if(i == 0){
                    printf("%d", ans[i]);
                }
                else{
                    printf("%dx^%d", ans[i], i);
                }
            } 
        }
        else{
            if(ans[i] == 0){
                zeroCount++;
                continue;
            }
            else if(ans[i] == 1 || ans[i] == -1){
                if(i == 1){
                    if(ans[i] > 0){
                        printf("+x");
                    }
                    else{
                        printf("-x");
                    }
                }
                else if(i == 0){
                    if(ans[i] > 0){
                        printf("+%d", ans[i]);
                    }
                    else{
                        printf("%d", ans[i]);
                    }
                }
                else{
                    if(ans[i] > 0){
                        printf("+x^%d", i);
                    }
                    else{
                        printf("-x^%d", i);
                    }
                }
            }
            else{
                if(i == 1){
                    if(ans[i] > 0){
                        printf("+%dx", ans[i]);
                    }
                    else{
                        printf("%dx", ans[i]);
                    }
                }
                else if(i == 0){
                    if(ans[i] > 0){
                        printf("+%d", ans[i]);
                    }
                    else{
                        printf("%d", ans[i]);
                    }
                }
                else{
                    if(ans[i] > 0){
                        printf("+%dx^%d", ans[i], i);
                    }
                    else{
                        printf("%dx^%d", ans[i], i);
                    }
                }
            } 
        }  
    }
    // printf("zc:%d\n", zeroCount);
    if(zeroCount == max+1){
        printf("0");
    }
}

int main(){
    int data, n1, n2, ans[20], max, i;
    nodep_t newNode, p, head1, head2;
    n1 = 0;
    scanf("%d", &data);
    head1 = create(data);
    p = head1;
    if(getchar() == '\n'){
        n2 = 0;
        scanf("%d", &data);
        head2 = create(data);
        p = head2;
        if(getchar() != '\n'){
            while(1){
                scanf("%d", &data);
                n2++;
                newNode = create(data);
                p->next = newNode;
                p = newNode;
                if(getchar() == '\n'){
                    break;
                }
            }
        }
    }
    else{
        while(1){
            scanf("%d", &data);
            n1++;
            newNode = create(data);
            p->next = newNode;
            p = newNode;
            if(getchar() == '\n'){
                break;
            }
        }
        n2 = 0;
        scanf("%d", &data);
        head2 = create(data);
        p = head2;
        if(getchar() != '\n'){
            while(1){
                scanf("%d", &data);
                n2++;
                newNode = create(data);
                p->next = newNode;
                p = newNode;
                if(getchar() == '\n'){
                    break;
                }
            }
        }
    }
    max = add(head1, head2, n1, n2, ans);
    print(ans, max);
    printf("\n");
    max = sub(head1, head2, n1, n2, ans);
    print(ans, max);
    printf("\n");
    for(i=0; i<20; i++){
        ans[i] = 0;
    }
    max = mul(head1, head2, n1, n2, ans);
    print(ans, max);
    return 0;
}