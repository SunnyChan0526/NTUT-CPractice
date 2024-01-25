#include <stdio.h>

int main(){
    int select=0, i=0, j=0, k=0, l=0, x=0, y=0, o=0;
    int size1=0, size2=0, base=0, bs=0, n=0, m=0, c=0, a=0, b=0, neg=0, sum=0;
    char in1[40], in2[40], ans[100], ans2[100], carry[100], sub1[40], sub2[40], mul[40][10000];

    scanf("%d", &select);
    getchar();
    scanf("%s", in1);
    getchar();
    scanf("%s", in2);
    while(1){
        if(in1[i]=='\0') break;
        else i+=1;
    }
    size1 = i;
    i=0;
    while(1){
        if(in2[i]=='\0') break;
        else i+=1;
    }
    size2 = i;
    if (select==1){
        if(size1>size2){
            base = size1;
        }
        if(size1<size2) base = size2;
        if(size1==size2) base = size1;
        for(i=0; i<=base; i++){
            ans[i] = '0';
        }
        i = size1-1;
        j = size2-1;
        bs = base;
        while(1){
            if(i<0) a = 0;
            else a = in1[i]-48;
            if(j<0) b = 0;
            else b = in2[j]-48;
            n = a + b + c;
            if(n<10){
                ans[bs] = n + 48;
                c = 0;
            }
            else{
                ans[bs] = n%10 + 48;
                c = (n/10)%10;
            }
            bs -= 1;
            i-=1;
            j-=1;
            if(bs<0) break;
        }
        j=-1;
        for(i=0; i<=base; i++){
            if(ans[0]=='0'){
                if(ans[i]=='0') j = i;
                else break;
            }
        }
        sum = 0;
        for(i=0; i<=base; i++) sum += ans[i]-48;
        if(sum==0) printf("0");
        else{
            if(j==-1){
                for(i=0; i<=base; i++) printf("%c", ans[i]);
            }
            else{
                for(i=j+1; i<=base; i++) printf("%c", ans[i]);
            }
        }    
    }

    else if (select==2)
    {
        if(size1>size2){
            base = size1;
            for(i=0; i<40; i++){
                sub1[i] = in1[i];
                sub2[i] = in2[i];
            }
            i = size1-1;
            j = size2-1;
        }
        if(size1<size2){
            base = size2;
            for(i=0; i<40; i++){
                sub1[i] = in2[i];
                sub2[i] = in1[i];
            }
            j = size1-1;
            i = size2-1;
            neg = -1;
        }
        if(size1==size2){
            base = size1;
            if(in1[0]>=in2[0]){
                for(i=0; i<40; i++){
                    sub1[i] = in1[i];
                    sub2[i] = in2[i];
                }
                i = size1-1;
                j = size2-1;
            }
            else{
                for(i=0; i<40; i++){
                    sub1[i] = in2[i];
                    sub2[i] = in1[i];
                }
                j = size1-1;
                i = size2-1;
                neg = -1;
            }
        }
        for(k=0; k<=base; k++){
            ans[k] = '0';
        }
        bs = base;
        while(1){
            if(i<0) a = 0;
            else a = sub1[i]-48;
            if(j<0) b = 0;
            else b = sub2[j]-48;
            
            n = a - b;
            if(n>=0){
                ans[bs] = n + 48;
            }
            else{
                ans[bs] = 10+n + 48;
                k = i-1;
                if(sub1[k]!='0') sub1[k] -= 1;
                else{
                    k -= 1;
                    while(1){
                        if(sub1[k]!='0'){
                            sub1[k] -= 1;
                            break;
                        }
                        else k-=1;
                    }
                    for(l=k+1; l<i; l++){
                        sub1[l] = '9';
                    }
                }
            }
            bs -= 1;
            i-=1;
            j-=1;
            if(bs<0) break;
        }

        if(neg==-1){
            printf("-");
            for(i=1; i<=base; i++) printf("%c", ans[i]);
        }
        else{
            sum = 0;
            for(i=1; i<=base; i++) sum += ans[i]-48;
            if(sum==0) printf("0");
            else for(i=1; i<=base; i++) printf("%c", ans[i]);
        }
    }

    else{
        if(size1>=size2){
            for(i=0; i<40; i++){
                sub1[i] = in1[i];
                sub2[i] = in2[i];
            }
            i = size1-1;
            j = size2-1;
        }
        if(size1<size2){
            for(i=0; i<40; i++){
                sub1[i] = in2[i];
                sub2[i] = in1[i];
            }
            j = size1-1;
            i = size2-1;
        }
        base = (i+1)*2;
        for(k=0; k<base; k++){
            carry[k] = '0';
            ans[k] = '0';
            ans2[k] = '0';
        }
        x = 0;
        for(k=j; k>=0; k--){
            bs = base-1;
            bs -= x;
            for(l=0; l<base; l++){
                mul[x][l] = '0';
            }
            c = 0;
            for(l=i; l>=0; l--){
                n = (sub2[k]-48) * (sub1[l]-48) + c;
                if(n<10){
                    mul[x][bs] = n+48;
                    c = 0;
                }
                else{
                    mul[x][bs] = n%10 + 48;
                    c = (n/10)%10;
                }
                bs-=1;
            }
            if(c>0) mul[x][bs] = c+48;
            x+=1; 
        }
        n=0;
        for(k=base-1; k>=0; k--){
            n = 0;
            for(l=0; l<x; l++){
                n += mul[l][k] - 48;
            }
            if(n<10){
                ans[k] = n + 48;
                carry[k] += 0;
            }
            else{
                ans[k] = n%10 + 48;
                o = k;
                while(1){
                    n /= 10;
                    if(n==0) break;
                    o -= 1;
                    m = carry[o]-48 + n%10;
                    if(m <= 9){
                        carry[o] += n%10;
                    }
                    else{
                        carry[o] = m%10 + 48;
                        carry[o-1] += (m/10)%10;
                    }
                }
            }
        }
        c = 0;
        for(k=base-1; k>=0; k--){
            n = ans[k]-48 + carry[k]-48 + c;
            if(n<10){
                ans2[k] = n + 48;
                c = 0;
            }
            else{
                ans2[k] = n%10 + 48;
                c = (n/10)%10;
            }
        }
        sum = 0;
        for(i=0; i<base; i++) sum += ans2[i]-48;
        if(sum==0) printf("0");
        else{
            j=-1;
            for(i=0; i<base; i++){
                if(ans2[0]=='0'){
                    if(ans2[i]=='0') j = i;
                    else break;
                }
            }
            if(j==-1){
                for(i=0; i<base; i++) printf("%c", ans2[i]);
            }
            else{
                for(i=j+1; i<base; i++) printf("%c", ans2[i]);
            }
        }
    }
    return 0;
}