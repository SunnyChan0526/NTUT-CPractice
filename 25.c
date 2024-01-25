#include <stdio.h>
#include <string.h>

int main ()
{
    int k = 0;
    char s[100];
    int i = 0, j = 0, m = 0, r = 0;
    int n = 0, next = 0, l = 0, max = 0, save = 0;
    int ans[100];

    scanf("%d", &k);
    getchar();
    scanf("%s", s);

    for(i=0; i<1000; i++){
        if(s[i] == '\0'){
            break;
        }
        if(s[i] < 97){ //ABCD
            n = 0;
        }
        else{ //abcd
            n = 1;
        }
        m = i;
        while(1){
            switch(n){
                case 0: //ABC
                    next = 0;
                    for(j=m; j<m+k; j++){
                        if(s[j] >= 97 || s[j] == '\0'){ //abc
                            next = 1;
                            break;
                        }
                    }
                    break;
                case 1: //abc
                    next = 0;
                    for(j=m; j<m+k; j++){
                        if(s[j] < 97 || s[j] == '\0'){ //ABC
                            next = 1;
                            break;
                        }
                    }
                    break;
            }
            if(next == 0){
                m = j;
                n = (n+1)%2;
                continue;
            }
            else{
                //printf("%d %d\n", i, j-1);
                save = j-i;
                if(save%k != 0){
                    save /= k;
                    save *= k;
                }
                ans[r] = save;
                r++;
                break;
            }
        }
    }
    l = i;
    for(i=0; i<l; i++){
        max = ans[i];
        for(j=i+1; j<l; j++){
            if(ans[j] > max){
                max = ans[j];
                ans[j] = ans[i];
                ans[i] = max; 
            }
        }
    }
    // for(i=0; i<l; i++){
    //     printf("%d ", ans[i]);
    // }
    // printf("\n");
    printf("%d", ans[0]);
    return(0);
}