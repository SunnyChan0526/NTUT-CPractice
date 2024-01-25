#include <stdio.h>

int main()
{
    int class[3], hour = 0, time[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
    for(int i=0; i<3; i++){
        scanf("%d", &class[i]);
        scanf("%d", &hour);
        for (int j=0; j<hour; j++){
            scanf("%d", &time[i][j]);
        }
    }
    int name1, name2, ans;
    for(int i=0; i<3; i++){
        for (int j=i+1; j<3; j++){
            for (int k=0; k<3; k++){
                for (int l=0; l<3; l++){
                    if ((time[i][k] == time[j][l]) && time[i][k]!=0){
                        name1 = class[i];
                        name2 = class[j];
                        ans = time[i][k];
                    }
                }
            }
        }
    }
    printf("%d and %d conflict on %d", name1, name2, ans);
    return 0;
}