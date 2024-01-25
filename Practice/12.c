#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1[100], b1[100], a2[100], b2[100];
    char ope[100], stop[100], ans[100][100];
    int i=0, j=0, k=0, up=0, down=0, base=0, m=0, front=0, b=0, n=0, p=0, l=0, q=0;
    while(1){
        scanf("%d/%d", &a1[i], &a2[i]) + getchar();
        scanf("%d/%d", &b1[i], &b2[i]) + getchar();
        scanf("%c", &ope[i]) + getchar();
        scanf("%c", &stop[i]) + getchar();
        if(stop[i]==110) break;
        else i++;
    }
    for(j=0; j<=i; j++){
        up=0, down=0, m=0, front=0;
        if(a2[j]==0 || b2[j]==0){
            ans[j][0] = 69;
            ans[j][1] = 82;
            ans[j][2] = 82;
            ans[j][3] = 79;
            ans[j][4] = 82;
            printf("%s\n", ans[j]);
        }
        else{
            if(ope[j]==43){ //+
                if(a2[j] == b2[j]){
                    up = a1[j] + b1[j];
                    down = a2[j];
                }
                else{
                    k = a2[j];
                    a1[j] *= b2[j];
                    a2[j] *= b2[j];
                    b1[j] *= k;
                    b2[j] *= k;
                    up = a1[j] + b1[j];
                    down = a2[j];
                }
            }
            if(ope[j]==45){ //-
                if(a2[j] == b2[j]){
                    up = a1[j] - b1[j];
                    down = a2[j];
                }
                else{
                    k = a2[j];
                    a1[j] *= b2[j];
                    a2[j] *= b2[j];
                    b1[j] *= k;
                    b2[j] *= k;
                    up = a1[j] - b1[j];
                    down = a2[j];
                }
            }
            if(ope[j]==42){ //*
                up = a1[j] * b1[j];
                down = a2[j] * b2[j];
            }
            if(ope[j]==47){ ///
                up = a1[j] * b2[j];
                down = a2[j] * b1[j];
            }
            
            if(up==0){
                ans[j][0] = 0;
                printf("%d\n", ans[j][0]);
                continue;
            }
            if(abs(up)>abs(down)) base = abs(up);
            else base = abs(down);
            //printf("up, down base:%d %d %d\n", up, down, base);
            for(int l=base; l>1; l--){
                //printf("l:%d\n", l);
                if((up%l == 0) && (down%l == 0)){
                    m = l;
                    break;
                }
            }
            if(m!=0){
                up /= m;
                down /= m;
            }
            if(abs(up)>abs(down)){
                front = up/down;
                if(up<0 && down<0){
                    up = abs(up);
                    down = abs(down);
                }
                if(down<0 && up>0){
                    up = -up;
                    down = abs(down);
                }
                up = abs(up) - abs(front) * down;
                //printf("%d %d %d\n", front, up, down);
                b = abs(front);
                n=0;
                while(1){
                    b /= 10;
                    n += 1;
                    if(b == 0) break;
                }
                //printf("n:%d\n", n);
                if(front<0) ans[j][0] = 45;
                if(n==1){
                    if(front>0) ans[j][0] = front + 48;
                    else{
                        ans[j][1] = abs(front) + 48;
                        n += 1;
                    }
                }
                else{
                    if(front<0){
                        n+=1;
                        for(p=0; p<n-1; p++){
                            ans[j][n-1-p] = abs(front)%10 + 48;
                            front/=10;
                        }
                    }
                    else{
                        for(p=0; p<n; p++){
                            ans[j][n-1-p] = front%10 + 48;
                            front/=10;
                        }
                    }
                }
                if(up == 0){
                    printf("%s\n", ans[j]);
                    continue;
                }
                ans[j][n] = 40;
            
                b = up;
                l = 0;
                while(1){
                    b /= 10;
                    l += 1;
                    if(b == 0) break;
                }
                if(l==1){
                    ans[j][n+1] = up + 48;
                }
                else{
                    for(p=0; p<l; p++){
                        ans[j][n+l-p] = up%10 + 48;
                        up/=10;
                    }
                }
                //printf("n+l+1:%d\n", n+l+1);
                ans[j][n+l+1] = 47;
                
                q=0;
                b = down;
                while(1){
                    b /= 10;
                    q += 1;
                    if(b == 0) break;
                }
                //printf("q:%d\n", q);
                if(q==1){
                    ans[j][n+l+2] = down + 48;
                }
                else{
                    for(p=0; p<q; p++){
                        ans[j][n+l+q+1-p] = down%10 + 48;
                        down/=10;
                    }
                }
                ans[j][n+l+q+2] = 41;
            }
            else{
                if(up/down==1){
                    printf("%d\n", 1);
                    continue;
                }
                if(up/down==-1){
                    printf("%d\n", -1);
                    continue;
                }
                if(up<0 && down<0){
                    up = abs(up);
                    down = abs(down);
                }
                if(up<0 || down<0){
                    ans[j][0] = 45;
                }
                if(down<0){
                    up = -up;
                    down = abs(down);
                }
                b = abs(up);
                l = 0;
                while(1){
                    b /= 10;
                    l += 1;
                    if(b == 0) break;
                }
                if(l==1){
                    if(up>0) ans[j][0] = abs(up) + 48;
                    else {
                        ans[j][1] = abs(up) + 48;
                        l+=1;
                    }
                }
                else{
                    if(up<0){
                        l+=1;
                        for(p=0; p<l-1; p++){
                            ans[j][l-1-p] = abs(up)%10 + 48;
                            up/=10;
                        }
                    }
                    else{
                        for(p=0; p<l; p++){
                            ans[j][l-1-p] = abs(up)%10 + 48;
                            up/=10;
                        }
                    }
                }
                ans[j][l] = 47;
                //printf("down:%d\n", down);
                b = down;
                q = 0;
                while(1){
                    b /= 10;
                    q += 1;
                    if(b == 0) break;
                }
                if(q==1){
                    ans[j][l+1] = down + 48;
                }
                else{
                    /*printf("l:%d\n", l);
                    printf("q:%d\n", q);*/
                    for(p=0; p<q; p++){
                        /*printf("l+q-p%d\n", l+q-p);
                        printf("a[l+q-p]%d\n", ans[j][l+q-p]);*/
                        ans[j][l+q-p] = down%10 + 48;
                        down/=10;
                    }
                }
            }
            //printf("%d %d\n", up, down);
            printf("%s\n", ans[j]);
        }
    }
    return 0;
}
