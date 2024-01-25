#include <stdio.h>
int main(){
    int n = 0;
    int nameArray[8], time[8][3], hour[3];
    int i = 0, j = 0, k = 0, l = 0;
    scanf("%d", &n);
    getchar();
    for(i=0; i<n; i++){
        scanf("%d", &nameArray[i]);
        getchar();
        scanf("%d", &hour[i]);
        getchar();
        for(j=0; j<hour[i]; j++){
            scanf("%d", &time[i][j]);
            getchar();
        }
    }
    int x = 0;
    for(i=0; i<n-1; i++){
        for(j=0; j<hour[i]; j++){
            x = i+1;
            for(k=i+1; k<n; k++){
                for(l=0; l<hour[x]; l++){
                    if(time[i][j] == time[k][l]) printf("%d and %d conflict on %d", nameArray[i], nameArray[k], time[i][j]);
                }
                x += 1;
            }
        }
    }
    return 0;
}