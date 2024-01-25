#include <stdio.h>
#include <stdlib.h>

void toINT(char s[10], int *up, int *down, int *front){
    char save[10][10];
    int i = 0, j = 0, k = 0;
    for(i=0; i<10; i++) for(j=0; j<10; j++) save[i][j] = '\0';
    i = 0, j = 0;
    //printf("s:%s\n", s);
    while(1){
        //printf("i s[i]:%d %c\n", i, s[i]);
        if(s[i] == '\0') break;
        if(s[i] == '(' || s[i] == ')' || s[i] == '/'){
            j += 1;
            k = 0;
            i += 1;
            continue;
        }
        save[j][k] = s[i];
        k += 1;
        i += 1;
    }
    printf("j:%d\n", j);
    if(j == 1){
        *up = atoi(save[0]);
        *down = atoi(save[1]);
    }
    if(j == 3){
        *front = atoi(save[0]);
        *up = atoi(save[1]);
        *down = atoi(save[2]);
    }
}

int main(){
    char s1[10], s2[10];
    int up1 = 0, down1 = 0, up2 = 0, down2 = 0, front1 = 0, front2 = 0;
    char op[1], yn[1];
    while(1){
        scanf("%s", s1);
        getchar();
        scanf("%s", s2);
        getchar();
        scanf("%c", &op[0]);
        getchar();
        scanf("%c", &yn[0]);
        getchar();
        if(yn[0] == 'n') break;
        printf("s1:%s\n", s1);
        printf("s1:%s\n", s2);
        toINT(s1, &up1, &down1, &front1);
        toINT(s2, &up2, &down2, &front2);
        printf("%d %d %d\n", front1, up1, down1);
        printf("%d %d %d\n", front2, up2, down2);
        if(front1 != 0){
            if(front1>0) up1 = front1*down1 + up1;
            if(front1<0) up1 = front1*down1 - up1;
        }
        if(front2 != 0){
            if(front2>0) up2 = front2*down2 + up2;
            if(front2<0) up2 = front2*down2 - up2;
        }
        printf("%d %d\n", up1, down1);
        printf("%d %d\n", up2, down2);
    }
    

    return 0;
}