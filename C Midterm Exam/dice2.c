#include <stdio.h>

void roll(int way, int dice[6]){
    char temp[6];
    int i = 0;
    for(i=0; i<6; i++) temp[i] = dice[i];
    if(way==1){
        dice[0] = temp[3];
        dice[1] = temp[0];
        dice[2] = temp[1];
        dice[3] = temp[2];
        dice[4] = temp[4];
        dice[5] = temp[5];
    }
    else{
        dice[0] = temp[0];
        dice[1] = temp[5];
        dice[2] = temp[2];
        dice[3] = temp[4];
        dice[4] = temp[1];
        dice[5] = temp[3];
    }
}

int main(){
    int i = 0, j = 0, k = 0;
    int n = 0;
    int x[100], y[100];
    int diceX[6] = {4, 1, 3, 6, 2, 5}, diceY[6] = {4, 1, 3, 6, 2, 5};
    int temp[6];
    int ansX[2][6], ansY[2][6];
    int an1 = 0, bn1 = 0, an2 = 0, bn2 = 0, aSum = 0, bSum = 0;
    for(i=0; i<6; i++) temp[i] = diceX[i];
    for(i=0; i<2; i++){
        scanf("%d", &n);
        getchar();
        for(j=0; j<n; j++){
            scanf("%d %d", &x[j], &y[j]);
            getchar();
        }
        for(j=0; j<6; j++){
            diceX[j] = temp[j];
            diceY[j] = temp[j];
        }
        for(j=0; j<n; j++){
            roll(x[j], diceX);
            roll(y[j], diceY);
        }
        for(j=0; j<6; j++){
            ansX[i][j] = diceX[j];
            ansY[i][j] = diceY[j];
        }
    }
    for(i=0; i<2; i++){
        for(j=0; j<6; j++){
            printf("%d ", ansX[i][j]);
        }
        printf("\n");
        for(j=0; j<6; j++){
            printf("%d ", ansY[i][j]);
        }
        printf("\n");
    }
    an1 = ansX[0][1];
    an2 = ansY[0][1];
    bn1 = ansX[1][1];
    bn2 = ansY[1][1];
    if(an1 != an2){
        aSum += an1+an2;
    }
    if(bn1 != bn2){
        bSum += bn1+bn2;
    }
    if(aSum>bSum) printf("A win");
    else if(aSum<bSum) printf("B win");
    else printf("Tie");
    return 0;
}