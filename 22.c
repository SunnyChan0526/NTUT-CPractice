#include <stdio.h>
#include <string.h>

int main(){
    char s[50], p[10], q[10];
    char ss[50][50], ans1[50][50], ans2[50][50], ans3[50][50];
    char save[50][50][50], store[50][50];
    char sv[50];
    int i = 0, j = 0, k = 0, m = 0, n = 0, u = 0, t = 0, r = 0;
    int sl = 0, max = 0, min = 0, numSortL = 0, start = 0, over = 0, ret = 0;
    int num[50], numSort[50], len[50][50];
    scanf("%[^\n]", s);
    getchar();
    scanf("%s", p);
    getchar();
    scanf("%s", q);

    for(i=0; i<50; i++){
        for(j=0; j<50; j++){
            ss[i][j] = '\0';
            ans2[i][j] = '\0';
            ans3[i][j] = '\0';
            store[i][j] = '\0';
        }
    }
    i = 0, j = 0;
    while (1){
        if (s[i] == '\0') break;
        if (s[i] == ' '){
            j++;
            i++;
            k = 0;
            continue;
        }
        ss[j][k] = s[i];
        k++;
        i++;
    }
    sl = j;

    for(i=0; i<=sl; i++) strcpy(ans1[i], ss[i]);
    k = 0;
    for(i=0; i<=sl; i++){
        while(1){
            if(ans1[i][k] == '\0' && p[k] == '\0'){
                strcpy(ans1[i], q);
                k = 0;
                break;
            }
            if(ans1[i][k] != p[k]){
                k = 0;
                break;
            }
            else k++;
        }
    }
    for(i=0; i<=sl; i++) printf("%s ", ans1[i]);
    printf("\n");

    j = 0, k = 0;
    for(i=0; i<=sl; i++){
        while(1){
            if(ss[i][j] == '\0' && p[j] == '\0'){
                j = 0;
                strcpy(ans2[k], q);
                strcpy(ans2[k+1], p);
                k += 2;
                break;
            }
            if(ss[i][j] != p[j]){
                j = 0;
                strcpy(ans2[k], ss[i]);
                strcpy(ans3[m], ss[i]);
                k++;
                m++;
                break;
            }
            else j++;
        }
    }

    for(i=0; i<k; i++) printf("%s ", ans2[i]);
    printf("\n");
    for(i=0; i<m; i++) printf("%s ", ans3[i]);
    printf("\n");

    for(i=0; i<=sl; i++) num[i] = 1;
    k = 0;
    for(i=0; i<=sl; i++){
        for(j=i+1; j<=sl; j++){
            while(1){
                if(ss[i][k] == '\0' && ss[j][k] == '\0'){
                    num[i] += 1;
                    k = 0;
                    break;
                }
                if(ss[i][k] != ss[j][k]){
                    k = 0;
                    break;
                }
                else k++;
            }
        }
    }
    k = 0, m = 0;
    for(i=0; i<=sl; i++) numSort[i] = 0;
    for(i=0; i<=sl; i++){
        for(j=0; j<=sl; j++){  
            if(numSort[j] == num[i]) k = 1;
        }
        if(k == 0){
            numSort[m] = num[i];
            m++;
        }
        k = 0;
    }
    numSortL = m;
    for(i=0; i<numSortL; i++){
        max = numSort[i];
        for(j=i+1; j<numSortL; j++){
            if(numSort[j]>max){
                max = numSort[j];
                numSort[j] = numSort[i];
                numSort[i] = max;
            }
        }
    }
    for(i=0; i<5; i++){
        for(j=0; j<50; j++) len[i][j] = '\0';
    }
    k = 0;
    for(i=0; i<numSortL; i++){
        for(j=0; j<=sl; j++){
            if(numSort[i] == num[j]){
                r = 0, u = 0, t = 0;
                while(1){
                    if(u >= n) break;
                    if(store[u][t] == '\0' && ss[j][t] == '\0'){
                        r = 1;
                        break;
                    }
                    if(store[u][t] != ss[j][t]){
                        u++;
                        t = 0;
                        continue;
                    }
                    else t++;
                }
                if(r == 0){
                    strcpy(save[i][k], ss[j]);
                    strcpy(store[n], ss[j]);
                    len[i][k] = strlen(ss[j]);
                    n++;
                    k++;
                }
            }
        }
        k = 0;
    }

    for(i=0; i<numSortL; i++){
        for(j=0; j<1000; j++){
            if(len[i][j] == '\0') break;
            min = len[i][j];
            for(k=j+1; k<1000; k++){
                if(len[i][k] == '\0') break;
                if(min > len[i][k]){
                    min = len[i][k];
                    len[i][k] = len[i][j];
                    len[i][j] = min;

                    for(m=0; m<50; m++) sv[m] = '\0';
                    strcpy(sv, save[i][k]);
                    strcpy(save[i][k], save[i][j]);
                    strcpy(save[i][j], sv);
                }
            }
        }
    }

    for(i=0; i<numSortL; i++){
        start = 0, over = 0, j = 0;
        while(1){
            if(len[i][j] == '\0') break;
            if(len[i][j] == len[i][j+1]){
                over++;
                j++;
            }
            else{
                if(start == over){
                    start++;
                    over++;
                    j++;
                }
                else{
                    for(k=start; k<=over; k++){
                        for(n=0; n<50; n++) sv[n] = '\0';
                        strcpy(sv, save[i][k]);
                        for(m=k+1; m<=over; m++){
                            ret = strcmp(sv, save[i][m]);
                            if(ret > 0){
                                strcpy(sv, save[i][m]);
                                strcpy(save[i][m], save[i][k]);
                                strcpy(save[i][k], sv);
                            }
                        }
                    }
                    start = over+1;
                    over = start;
                    j++;
                }
            }
        }
    }

    for(i=0; i<numSortL; i++){
        for(j=0; j<1000; j++){
            if(len[i][j] == '\0') break;
            printf("%s %d\n", save[i][j], numSort[i]);
        }
    }

    return 0;
}