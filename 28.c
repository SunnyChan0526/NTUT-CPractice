#include <stdio.h>

typedef struct data {
    int no;
    int num[5];
    int score;
    int hits;
    int reach;
}data_t;

void calculate(data_t player[9], int stop){
    int i, j, k;
    int out = 0, isStop = 0, teamScore = 0, item;
    for(i=0; i<9; i++){
        player[i].score = 0;
        player[i].hits = 0;
        player[i].reach = 0;
    }
    for(i=0; i<5; i++){
        for(j=0; j<9; j++){
            if(player[j].num[i] == 0){
                out += 1;
                isStop += 1;
                if(isStop == stop){
                    printf("%d\n", teamScore);
                    for(k=0; k<9; k++){
                        item = k + 1;
                        printf("%d %d %d\n", item, player[k].hits, player[k].reach);
                    }
                    break;
                }
                if(out == 3){
                    out = 0;
                    for(k=0; k<9; k++){
                        player[k].score = 0;
                    }
                }
            }
            else{
                player[j].score += player[j].num[i];
                player[j].hits += 1;
                if(player[j].score > 3){
                    player[j].reach += 1;
                    player[j].score = 0;
                    teamScore += 1;
                }
                for(k=0; k<9; k++){
                    if(k == j){
                        continue;
                    }
                    else{
                        if(player[k].score > 0){
                            player[k].score += player[j].num[i];
                        }
                        if(player[k].score > 3){
                            player[k].reach += 1;
                            player[k].score = 0;
                            teamScore += 1;
                        }
                    }
                }
            }
            // printf("player score hits reach: %d %d %d %d\n", j, player[j].score, player[j].hits, player[j].reach);
        }
    }
}

int main(){
    int stop;
    int i, j;
    char s[10];
    data_t player[9];
    for(i=0; i<9; i++){
        scanf("%d", &player[i].no);
        for(j=0; j<player[i].no; j++){
            scanf("%s", s);
            if(s[0] == 'O'){
                player[i].num[j] = 0;
            }
            else if(s[0] == 'H'){
                player[i].num[j] = 4;
            }
            else{
                player[i].num[j] = s[0] - '0';
            }
        }
    }
    scanf("%d", &stop);
    calculate(player, stop);
    return 0;
}