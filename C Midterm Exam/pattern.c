#include <stdio.h>

void f111(int *i, int *n){
    int j = 0;
    for(j=1; j<=*i; j++) printf("%d", j);
}
void f112(int *i, int *n){
    int j = 0;
    for(j=*i; j>=1; j--) printf("%d", j);
}
void f12(int *i, int *n){
    int j = 0;
    for(j=1; j<=*i; j++) printf("%d", *i);
}
void f21(int i, int n){
    int j = 0;
    for(j=1; j<=i; j++) printf("%d", j);
    for(j=i-1; j>=1; j--) printf("%d", j);
}
void f221(int i, int n){
    int j = 0;
    for(j=1; j<n-i; j++) printf("_");
    for(j=i; j>1; j--) printf("%d", j);
    for(j=1; j<=i; j++) printf("%d", j);
    for(j=1; j<n-i; j++) printf("_");
}
void f222(int i, int n){
    int j = 0;
    for(j=1; j<5-i; j++) printf("_");
    for(j=i; j>1; j--) printf("%d", j);
    for(j=1; j<=i; j++) printf("%d", j);
    for(j=1; j<5-i; j++) printf("_");
}

int main(){
    int select = 0, n = 0;
    int i = 0;
    scanf("%d", &select);
    getchar();
    scanf("%d", &n);

    if(select==1){
        for(i=1; i<=n; i++){
            f111(&i, &n);
            printf("\n");
        }
        for(i=n; i>=1; i--){
            f112(&i, &n);
            printf("\n");
        }
        for(i=1; i<=n; i++){
            f12(&i, &n);
            printf("\n");
        }
    }

    if(select==2){
        for(i=1; i<=n; i++){
            f21(i, n);
            printf("\n");
        }
        for(i=1; i<n; i++){
            f221(i, n);
            printf("\n");
        }
        for(i=n-1; i>=1; i--){
            f222(i, n);
            printf("\n");
        }
    }
    return 0;
}