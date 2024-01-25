#include <stdio.h>

int main(){
    int num, min = 10000, path;
    int length[10][10];
    int i, j;

    scanf("%d", &num);
    getchar();
    for(i=0; i<num; i++){
        for(j=0; j<num; j++){
            scanf("%d", &length[i][j]);
        }
        getchar();
    }
    

    
    return 0;
}