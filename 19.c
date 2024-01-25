#include <stdio.h> 
#include <string.h> 
#include <math.h>

int ans(int k, int *yy, int *xx){
    int n=0, m=0, r=0, base=0;
    int aa=0;
    int i=0;
    int ax[] = {0, 1, 4, 5},
        bx[] = {2, 3, 6, 7},
        cx[] = {8, 9, 12, 13},
        dx[] = {10, 11, 14, 15},
        ay[] = {0, 2, 8, 10},
        by[] = {1, 3, 9, 11},
        cy[] = {4, 6, 12, 14},
        dy[] = {5, 7, 13, 15};
    int y[] = {0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 3, 3, 2, 2, 3, 3},
        x[] = {0, 1, 0, 1, 2, 3, 2, 3, 0, 1, 0, 1, 2, 3, 2, 3};
    n = k/16;
    m = k%16; //m:0~15
    aa=3;
    r = pow(4, aa);
    while(1){
        if(n<r) break;
        aa+=1;
        r = pow(4, aa);
    }
    for(i=0; i<4; i++){
        if(n%16==ax[i] || n%16==bx[i] || n%16==cx[i] || n%16==dx[i]) break; 
    }
    if(aa==3) base = 0;
    else base = pow(4, aa-1);
    if(n-base>=16) i+=4;
    r = aa-3;
    *xx = x[m]+4*i+32*r;

    aa = 7;
    r = pow(2, aa);
    while(1){
        if(n<r) break;
        aa+=2;
        r = pow(2, aa);
    }
    for(i=0; i<4; i++){
        if(n%16==ay[i] || n%16==by[i] || n%16==cy[i] || n%16==dy[i]) break;
    }
    if(aa==7) base=0;
    else base = pow(2, base-2);
    if(n-base>=32) i+=4;
    r = (aa-7)/2;
    *yy = y[m]+4*i+32*r;
}

int count(int level) {
    int ans=1;
    for (int i=0; i<level;i++) ans = ans*2; 
    return (ans*ans);
}

int main() {
    int N=0;
    char data[100];
    int xxs[100], yys[100];
    int level =0, index =0, sum=0;
    int i=0, j=0, n=0, k=0;
    int yy, xx, kk=0;
    int comp[100]={0};
    scanf("%s", data);
    getchar();
    scanf("%d", &N);
    int len = strlen(data);

    for (int i=0; i<100; i++) comp[i]=0; 
    while (index <len) {
        if (data[index]=='2') level++;
        if (data[index]=='1') {
            sum = (N*N)/count(level);
            for(i=k; i<k+sum; i++) {
                //printf("k:%d\n", i);
                ans(i, &yy, &xx);
                yys[kk] = yy;
                xxs[kk] = xx;
                kk += 1;
            }
            k = i;
        }
        if (data[index]=='0') {
            sum = (N*N)/count(level);
            k += sum;
        }
        if (data[index]!='2') comp[level]++;
        if (comp[level]>=4) { 
            comp[level]=0;
            level--;
            comp[level]++;
            while(1){
                if(comp[level]>=4){
                    comp[level]=0;
                    level--;
                    comp[level]++;
                }
                else break;
            }
        }

        /*printf("index, level, k:%d %d %d\n", index, level, k);
        for(j=0;j<100; j++) printf("%d", comp[j]);
        printf("\n");*/
        index++;
    }
    
    /*for(i=0; i<kk; i++){
        printf("%d,%d\n", yys[i], xxs[i]);
    }*/
    if(data[0]=='0' && data[1]=='\0') printf("all white");
    else{
        i=0, j=0, n=0;
        while(1){
            if(yys[i]==j){
                printf("%d,%d\n", yys[i], xxs[i]);
                n+=1;
            }
            i+=1;
            if(i>=kk){
                j+=1;
                i=0;
            }
            if(n>=kk) break;
        }
    }
    return 0;
}