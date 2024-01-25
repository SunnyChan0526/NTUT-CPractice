#include <stdio.h>

typedef struct data {
    int d[50];
} data_t;

int main(){
    int n, m, in, min[50], max, rcL;
    int i, j, k, l, p;
    int record[50][50];
    for(i=0; i<50; i++){
        for(j=0; j<50; j++){
            record[i][j] = 0;
        }
    }
    scanf("%d %d", &n, &m);
    data_t s[n+1];
    getchar();
    for(i=0; i<n+1; i++){
        for(j=0; j<m; j++){
            s[i].d[j] = 0;
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &in);
            s[i+1].d[j] = in;
        }
        getchar();
    }
    max = s[1].d[0];
    for(j=2; j<=n; j++){   
        if(max < s[j].d[0]){
            max = s[j].d[0];
        }
    }
    i = 0, k = 0, l = 0;
    while(1){
        for(j=1; j<=n; j++){  
            if(s[j].d[0] == i){
                record[k][l] = j;
                l++;
            }
        }
        i++;
        l = 0;
        if(i > max){
            break;
        }
        if(record[k][0] != 0){
            k++;
        }
    }
    rcL = k+1;
    // for(i=0; i<=k; i++){
    //     for(j=0; j<50; j++){
    //         if(record[i][j] == 0){
    //             break;
    //         }
    //         printf("%d ", record[i][j]);
    //     }
    //     printf("\n");
    // }
    for(i=0; i<rcL; i++){
        for(j=0; j<n; j++){
            if(record[i][j] == 0){
                break;
            }
            for(k=j+1; k<n; k++){
                if(record[i][k] == 0){
                    break;
                }
                for(l=0; l<m; l++){
                    if(s[record[i][j]].d[l] > s[record[i][k]].d[l]){
                        for(p=0; p<m; p++){
                            min[p] = s[record[i][k]].d[p];
                        }
                        for(p=0; p<m; p++){
                            s[record[i][k]].d[p] = s[record[i][j]].d[p];
                        }
                        for(p=0; p<m; p++){
                            s[record[i][j]].d[p] = min[p];
                        }
                    }
                    if(s[record[i][j]].d[l] < s[record[i][k]].d[l]){
                        break;
                    }
                }
                // printf("record:%d %d\n", record[i][j], record[i][k]);
                // printf("a b l:%d %d %d\n", s[record[i][j]].d[l], s[record[i][k]].d[l], l);
            }
        }
    }
    // printf("----\n");
    for(i=0; i<rcL; i++){
        for(j=0; j<n; j++){
            if(record[i][j] == 0){
                break;
            }
            for(k=0; k<m; k++){
                printf("%d ", s[record[i][j]].d[k]);
            }
            printf("\n");
        }
    }
    return 0;
}