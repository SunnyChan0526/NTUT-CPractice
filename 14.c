#include <stdio.h>

int main()
{
    char ans[4], in[6][4];
    int i=0, j=0, k=0, a=0, b=0;
    for(i=0; i<4; i++) scanf("%c", &ans[i]);
    getchar();
    i=0;
    while(1){
        for(j=0; j<4; j++) scanf("%c", &in[i][j]);
        getchar();
        a=0, b=0;
        for(j=0; j<4; j++){
            if(in[i][j]==ans[j]) a += 1;
            else{
                for(k=0; k<4; k++){
                    if(in[i][j]==ans[k]) b += 1;
                }
            }
        }
        if(a==4){
            printf("win");
            break;
        }
        else printf("%dA%dB\n", a, b);
        if(i==5) break;
        i+=1;
    }
    return 0;
}