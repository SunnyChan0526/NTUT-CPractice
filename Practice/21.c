#include <stdio.h>

int isConvert(char ss1[50], char ss2[50], char sp[50][50], int sl){
    char s1[50][50], s2[50][50];
    int i = 0, j = 0, k = 0;
    int s1l = 0, s2l = 0;
    int convert = 0, includes = 0, num = 0;
    int include[sl+1];
    for(i=0; i<=sl; i++) include[i] = 0;
    for(i=0; i<50; i++){
        for(j=0; j<50; j++){
            s1[i][j] = '\0';
            s2[i][j] = '\0';
        }
    }
    i=0, j=0, k=0;
    while(1){
        if(ss1[i] == '\0') break;
        if(ss1[i] == ' '){
            j++;
            i++;
            k = 0;
            continue;
        }
        s1[j][k] = ss1[i];
        k++;
        i++;
    }
    s1l = j;
    //for(i=0; i<=j; i++) printf("%s\n", s1[i]);
    i=0, j=0, k=0;
    while(1){
        if(ss2[i] == '\0') break;
        if(ss2[i] == ' '){
            j++;
            i++;
            k = 0;
            continue;
        }
        s2[j][k] = ss2[i];
        k++;
        i++;
    }
    s2l = j;

    k = 0;
    for(i=0; i<=s1l; i++){
        for(j=0; j<=s2l; j++){
            while(1){
                //printf("%c %c %d\n", s1[i][k], s2[j][k], convert);
                if(s1[i][k] == '\0' &&  s2[j][k] == '\0'){
                    // printf("1\n");
                    convert = 1;
                    break;
                }
                if(s1[i][k] != s2[j][k]){
                    // printf("2\n");
                    break;
                }
                else k++;
            }
            k = 0;
        }
    }

    //include
    k = 0;
    for(i=0; i<=sl; i++){
        for(j=0; j<=s1l; j++){
            while(1){
                if(sp[i][k] == '\0' && s1[i][k] == '\0'){
                    include[i] = 1;
                    break;
                }
                if(sp[i][k] != s1[j][k]) break;
                else k++;
            }
            k = 0;
        }
        //printf("include[i]:%d\n", include[i]);
        k = 0;
        for(j=0; j<=s2l; j++){
            while(1){
                //printf("%c %c\n", sp[i][k], s2[i][k]);
                if(sp[i][k] == '\0' && s2[j][k] == '\0'){
                    include[i] = 1;
                    break;
                }
                if(sp[i][k] != s2[j][k]) break;
                else k++;
            }
            k = 0;
        }
        //printf("include[i]:%d\n", include[i]);
    }
    for(i=0; i<=sl; i++){
        //printf("%d\n", include[i]);
        if(include[i] == 0){
            includes = 1;
            break;
        }
    }
    if(includes == 0 && convert == 0) num = 1;
    else num = 0;
    
    return num;
}

int main(){
    char s[50], sp[50][50], ss[50][50];
    int n = 0;
    int i = 0, j = 0, k = 0;
    int convert = 0, sl = 0, num = 0, ans = 0;

    scanf("%[^\n]", s);
    getchar();
    scanf("%d", &n);
    getchar();
    for(i=0; i<n; i++){
        scanf("%[^\n]", ss[i]);
        getchar();
    }

    for(i=0; i<50; i++){
        for(j=0; j<50; j++) sp[i][j] = '\0';
    }
    i = 0, j = 0;
    while(1){
        if(s[i] == '\0') break;
        if(s[i] == ' '){
            j++;
            i++;
            k = 0;
            continue;
        }
        sp[j][k] = s[i];
        k++;
        i++;
    }
    sl = j;
    //for(i=0; i<=sl; i++) printf("%s\n", sp[i]);

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            convert = 0;
            //printf("%s & %s\n", ss[i], ss[j]);
            num = isConvert(ss[i], ss[j], sp, sl);
            //printf("%d\n", num);
            if(num == 1) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}