#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, w, a;
    int i, j;
    int ogDay[20], connect[20][10], record[20], day, current, max, zero=0;
    scanf("%d", &n);
    getchar();
    for(i=0; i<20; i++){
        record[i] = 0;
        ogDay[i] = 0;
        for(j=0; j<10; j++){
            connect[i][j] = 0;
        }
    }
    for(i=0; i<n; i++){
        scanf("%d", &ogDay[i]);
        scanf("%d", &m);
        if(m == 0){
            zero++;
        }
        for(j=0; j<m; j++){
            scanf("%d", &w);
            connect[i][j] = w;
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<10; j++){
            a = connect[i][j];
            if(a == 0){
                break;
            }
            if(record[i] == 0){
                current = ogDay[i];
            }
            else{
                current = record[i];
            }
            // printf("a-1  :%d %d %d\n", a-1, ogDay[a-1], current);
            day = ogDay[a-1] + current;
            if(record[a-1] < day){
                record[a-1] = day;
            }
        }
    }
    if(zero == n){
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                if(ogDay[i] < ogDay[j]){
                    max = ogDay[j];
                    ogDay[j] = ogDay[i];
                    ogDay[i] = max;
                }
            }
            printf("%d", ogDay[0]);
        }
    }
    else{
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                if(record[i] < record[j]){
                    max = record[j];
                    record[j] = record[i];
                    record[i] = max;
                }
            }
        }
        printf("%d", record[0]);
    }
}