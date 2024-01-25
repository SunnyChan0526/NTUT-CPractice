#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodeDay {
    char name[100][3];
    int sum;
} nodeDay_t;

int main(){
    int group, num, nodeNum, node, noneNode[100], noneNodeLen;
    int array[100], x, max, ans[100], final[100];
    int i, j, k, m, p;
    char toStr[2];
    scanf("%d", &group);
    getchar();
    for(i=0; i<group; i++){
        scanf("%d", &num);
        getchar();
        nodeDay_t data[100];
        for(j=0; j<100; j++){
            for(k=0; k<100; k++){
                for(m=0; m<3; m++){
                    data[j].name[k][m] = '\0';
                }
            }
        }
        for(j=0; j<100; j++){
            data[j].sum = 0;
            noneNode[j] = 0;
            ans[j] = 0;
        }
        p = 0;
        for(j=0; j<num; j++){
            scanf("%d %d", &data[j].sum, &nodeNum);
            if(nodeNum == 0){
                noneNode[p] = data[j].sum;
                p++;
            }
            for(k=0; k<nodeNum; k++){
                scanf("%d", &node);
                for(m=0; m<2; m++){
                    toStr[m] = '\0';
                }
                sprintf(toStr, "%d", j);
                m = 0;
                while(1){
                    if(data[node-1].name[m][0] == '\0'){
                        strcpy(data[node-1].name[m], toStr);
                        break;
                    }
                    m++;
                }
            }
            getchar();
        }
        noneNodeLen = p;
        for(j=1; j<num; j++){
            for(k=0; k<100; k++){
                array[k] = 0;
            }
            k = 0;
            while(1){
                if(data[j].name[k][0] == '\0'){
                    break;
                }
                x = atoi(data[j].name[k]);
                array[k] = data[j].sum + data[x].sum;
                k++;
            }
            if(k > 1){
                for(m=0; m<k; m++){
                    max = array[m];
                    for(p=m+1; p<k; p++){
                        if(max < array[p]){
                            max = array[p];
                            array[p] = array[m];
                            array[m] = max;
                        }
                    }
                }
            }
            data[j].sum = array[0];
            ans[j-1] = array[0];
        }
        for(j=0; j<num-1; j++){
            max = ans[j];
            for(k=j+1; k<num-1; k++){
                if(max < ans[k]){
                    max = ans[k];
                    ans[k] = ans[j];
                    ans[j] = max;
                }
            }
        }
        for(j=0; j<noneNodeLen; j++){
            max = noneNode[j];
            for(k=j+1; k<noneNodeLen; k++){
                if(max < noneNode[k]){
                    max = noneNode[k];
                    noneNode[k] = noneNode[j];
                    noneNode[j] = max;
                }
            }
        }
        if(ans[0] > noneNode[0]){
            final[i] = ans[0];
        }
        else{
            final[i] = noneNode[0];
        }
    }
    for(i=0; i<group; i++){
        printf("%d\n", final[i]);
    }
    return 0;
}