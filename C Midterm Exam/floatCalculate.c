#include <stdio.h>
#include <stdlib.h>

int add(char s1[200], char s2[200], char ans[200], int max){
    int i = 0, sum = 0, carry = 0;
    char ansTemp[200];
    for(i=max; i>=0; i--){
        if(s1[i] == '.'){
            ans[i] = '.';
            continue;
        }
        sum = s1[i]-'0' + s2[i]-'0' + carry;
        if(sum<10){
            ans[i] = sum + '0';
            carry = 0;
        }
        else{
            ans[i] = sum%10 + '0';
            carry = sum/10;
        }
    }
    if(carry != 0){
        for(i=0; i<200; i++) ansTemp[i] = ans[i];
        ans[0] = carry + '0';
        for(i=0; i<200; i++) ans[i+1] = ansTemp[i];
        max++;
    }
    return max;
}

void sub(char s1[200], char s2[200], char ans[200], int max){
    int i = 0, k = 0;
    for(i=max; i>=0; i--){
        if(s1[i] == '.'){
            ans[i] = '.';
            continue;
        }
        if(s1[i]>=s2[i]) ans[i] = s1[i] - s2[i] + '0';
        else{
            k = i-1;
            while(1){
                if(s1[k] == '.'){  //!
                    k -= 1;
                    continue;
                }
                if(s1[k]>'0'){
                    s1[k] -= 1;
                    ans[i] = 10 + s1[i] - s2[i] + '0';
                    break;
                }
                s1[k] = '9';
                k -= 1;
            }
        } 
    }
}

int typeAdd4sub3(char s1[200], char s2[200], char ans[200], int max){
    int i = 0;
    char ansTemp[200];
    max = add(s1, s2, ans, max);
    for(i=0; i<200; i++) ansTemp[i] = ans[i];
    ans[0] = '-';
    for(i=0; i<200; i++) ans[i+1] = ansTemp[i];
    return max;
}

void typeAdd2sub1(char s1[200], char s2[200], char ans[200], int max){
    int i = 0;
    char ansTemp[100];
    if(s1[0]>s2[0]) sub(s1, s2, ans, max);
    if(s1[0]<s2[0]){
        sub(s2, s1, ans, max);
        for(i=0; i<81; i++) ansTemp[i] = ans[i];
        ans[0] = '-';
        for(i=0; i<81; i++) ans[i+1] = ansTemp[i];
    }
    if(s1[0]==s2[0]){
        i = 1;
        while(1){
            if(s1[i]>s2[i]){
                sub(s1, s2, ans, max);
                break;
            }
            if(s1[i]<s2[i]){
                sub(s2, s1, ans, max);
                for(i=0; i<81; i++) ansTemp[i] = ans[i];
                ans[0] = '-';
                for(i=0; i<81; i++) ans[i+1] = ansTemp[i];
                break;
            }
            i += 1;
            if(i==40){
                for(i=0; i<83; i++) ans[i] = '0';
                break;
            }
        }
    }
}

void typeAdd3sub4(char s1[200], char s2[200], char ans[200], int max){
    int i = 0;
    char ansTemp[200];
    if(s1[0]<s2[0]) sub(s2, s1, ans, max);
    if(s1[0]>s2[0]){
        sub(s1, s2, ans, max);
        for(i=0; i<200; i++) ansTemp[i] = ans[i];
        ans[0] = '-';
        for(i=0; i<200; i++) ans[i+1] = ansTemp[i];
    }
    if(s1[0]==s2[0]){
        i = 1;
        while(1){
            if(s1[i]<s2[i]){
                sub(s2, s1, ans, max);
                break;
            }
            if(s1[i]>s2[i]){
                sub(s1, s2, ans, max);
                for(i=0; i<200; i++) ansTemp[i] = ans[i];
                ans[0] = '-';
                for(i=0; i<200; i++) ans[i+1] = ansTemp[i];
                break;
            }
            i += 1;
            if(i==120){
                for(i=0; i<83; i++) ans[i] = '0';
                break;
            }
        }
    }
}

void mul(char s1[200], char s2[200], char s1t[200], char s2t[200], int mulDot, int mulLen){
    int i=0, j=0, k=0, l=0, x=0, y=0, o=0;
    int size1=0, size2=0, base=0, bs=0, n=0, m=0, c=0, a=0, b=0, neg=0, sum=0, dot, len1, len2;
    char ans[200], ans2[200], carry[200], sub1[200], sub2[200], mul[400][10000];
    
    if(size1>=size2){
        for(i=0; i<200; i++){
            sub1[i] = s1[i];
            sub2[i] = s2[i];
        }
        i = size1-1;
        j = size2-1;
        len1 = size1;
        len2 = size2;
    }
    if(size1<size2){
        for(i=0; i<200; i++){
            sub1[i] = s2[i];
            sub2[i] = s1[i];
        }
        j = size1-1;
        i = size2-1;
        len1 = size1;
        len2 = size2;
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
    if(c > 0){
        mulLen++;
    }
    printf("mulLen:%d\n", mulLen);
    sum = 0;
    for(i=0; i<base; i++) sum += ans2[i]-48;
    base = mulLen;
    printf("base:%d\n", base);
    printf("ans:%s\n", ans2);    
    // if(base < 120){
    //     if(ans[base-1] == '0'){
    //         i = base - 1;
    //         while(ans[i] == '0'){
    //             base = i;
    //             i--;
    //             // printf("base i ansi: %d %d %d\n", base, i, ans[i]);
    //         }
    //     }
    // }
    // else{
    //     base = 120;
    // }
    // printf("base muldot:%d %d\n", base, mulDot);
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
            mulDot = base  - mulDot;
            if((s1t[0] != '-' && s2t[0] != '-') || (s1t[0] == '-' && s2t[0] == '-')){
                for(i=0; i<mulDot; i++) printf("%c", ans2[i]);
                printf(".");
                for(i=mulDot; i<base; i++) printf("%c", ans2[i]);
            }
            else{
                printf("-");
                for(i=0; i<mulDot; i++) printf("%c", ans2[i]);
                printf(".");
                for(i=mulDot; i<base+1; i++) printf("%c", ans2[i]);
            }
        }
        else{
            base = base  - j - 2;
            mulDot = base + 1  - mulDot;
            printf("base muldot:%d %d\n", base, mulDot);
            printf("ans:%s\n", ans2);
            if((s1t[0] != '-' && s2t[0] != '-') || (s1t[0] == '-' && s2t[0] == '-')){
                for(i=j+1; i<mulDot+j+1; i++) printf("%c", ans2[i]);
                printf(".");
                for(i=mulDot+j+1; i<base+j+1; i++) printf("%c", ans2[i]);
            }
            else{
                printf("-");
                for(i=j+1; i<mulDot+j+1; i++) printf("%c", ans2[i]);
                printf(".");
                for(i=mulDot+j+1; i<base+1+j+1; i++) printf("%c", ans2[i]);
            }
        }
    }
}

int main(){
    char s1[200], s2[200], s11[200], s22[200];
    char s1t[200], s2t[200];
    char ans[200], ansTemp[200];
    int i = 0, j = 0, k = 0;
    int s1Dot = 0, s2Dot = 0, space = 0, mulDot = 0, muls1dot, muls2dot, maxx, dot;
    char stemp[200];

    scanf("%s", s1);
    getchar();
    scanf("%s", s2);

    for(i=0; i<200; i++){
        s1t[i] = s1[i];
        s2t[i] = s2[i];
    }
    
    //remove '-'
    if(s1[0] == '-'){
        for(i=0; i<199; i++) s1[i] = s1t[i+1];
    }
    if(s2[0] == '-'){
        for(i=0; i<199; i++) s2[i] = s2t[i+1];
    }
    //front align
    for(int i=0; i<200; i++){
        if(s1[i] == '.') s1Dot = i;
        if(s2[i] == '.') s2Dot = i;
    }
    space = abs(s1Dot-s2Dot);
    if(s1Dot>s2Dot){
        for(i=0; i<space; i++) stemp[i] = '0';
        for(i=0; i<200-space; i++) stemp[i+space] = s2[i];
        for(i=0; i<200; i++) s2[i] = stemp[i];
        s2Dot += space;
    }
    if(s1Dot<s2Dot){
        for(i=0; i<space; i++) stemp[i] = '0';
        for(i=0; i<200-space; i++) stemp[i+space] = s1[i];
        for(i=0; i<200; i++) s1[i] = stemp[i];
        s1Dot += space;
    }
    //back align
    int s1Back = 0, s2Back = 0, max = 0;
    for(int i=0; i<200; i++){
        if(s1[i] == '\0'){
            s1Back = i-1;
            break;
        }
    }
    for(int i=0; i<200; i++){
        if(s2[i] == '\0'){
            s2Back = i-1;
            break;
        }
    }
    if(s1Back>s2Back){
        max = s1Back;
        for(i=s1Back; i>s2Back; i--) s2[i] = '0';
    }
    if(s1Back<s2Back){
        max = s2Back;
        for(i=s2Back; i>s1Back; i--) s1[i] = '0';
    }
    if(s1Back==s2Back) max = s1Back;
    for(i=0; i<81; i++){
        s11[i] = s1[i];
        s22[i] = s2[i];
    }

    //add
    maxx = max;
    if(s1t[0] != '-' && s2t[0] != '-') maxx = add(s1, s2, ans, max);
    else if(s1t[0] == '-' && s2t[0] == '-'){
        maxx = typeAdd4sub3(s1, s2, ans, max);
    }

    else if(s1t[0] != '-' && s2t[0] == '-'){
        typeAdd2sub1(s1, s2, ans, max);
    }
    else{
        typeAdd3sub4(s1, s2, ans, max);
    }
    j = 0;
    for(i=0; i<122; i++){
        if(ans[i] == '\0') break;
        if(ans[i] != '0' && ans[i] != '-'  && ans[i] != '.'){
            j += 1;
        }
    }
    if(j == 0){
        printf("0");
    }
    else{
        i = 0;
        while(ans[i] != '.'){
            i++;
        }
        dot = i+1;
        i = dot;
        k = 0;
        while(ans[i] != '\0'){
            if(ans[i] != '0'){
                k++;
            }
            i++;
        }
        if(k == 0){
            for(i=0; i<dot-1; i++) printf("%c", ans[i]);
        }
        else{
            if(ans[0] != '-'){
                if(maxx+1 < 121){
                    for(i=0; i<maxx+1; i++) printf("%c", ans[i]);
                }
                else{
                    for(i=0; i<121; i++) printf("%c", ans[i]);
                }
            }
            else{
                if(maxx+2 < 122){
                    for(i=0; i<maxx+2; i++) printf("%c", ans[i]);
                }
                else{
                    for(i=0; i<122; i++) printf("%c", ans[i]);
                }
            }
        }
    }
    printf("\n");

    //sub
    maxx = max;
    for(i=0; i<200; i++){  //!
        s1[i] = s11[i];
        s2[i] = s22[i];
    }
    for(i=0; i<200; i++) ans[i] = '\0';
    if(s1t[0] != '-' && s2t[0] == '-') {
        maxx = add(s1, s2, ans, max);
    }
    else if(s1t[0] == '-' && s2t[0] != '-') {
        maxx = typeAdd4sub3(s1, s2, ans, max);
    }
    else if(s1t[0] != '-' && s2t[0] != '-'){
        typeAdd2sub1(s1, s2, ans, max);
    }
    else{
    // if(s1t[0] == '-' && s2t[0] == '-'){
        typeAdd3sub4(s1, s2, ans, max);
    }
    j = 0;
    for(i=0; i<122; i++){
        if(ans[i] == '\0') break;
        if(ans[i] != '0' && ans[i] != '-'  && ans[i] != '.'){
            j += 1;
        }
    }
    if(j == 0){
        printf("0");
    }
    else{
        // printf("%s\n", ans);
        i = 0;
        while(ans[i] != '.'){
            i++;
        }
        dot = i+1;
        i = dot;
        k = 0;
        while(ans[i] != '\0'){
            if(ans[i] != '0'){
                k++;
            }
            i++;
        }
        if(k == 0){
            for(i=0; i<dot-1; i++) printf("%c", ans[i]);
        }
        else{
            if(ans[0] != '-'){
                if(maxx+1 < 121){
                    for(i=0; i<maxx+1; i++) printf("%c", ans[i]);
                }
                else{
                    for(i=0; i<121; i++) printf("%c", ans[i]);
                }
            }
            else{
                if(maxx+2 < 122){
                    for(i=0; i<maxx+2; i++) printf("%c", ans[i]);
                }
                else{
                    for(i=0; i<122; i++) printf("%c", ans[i]);
                }
            }
        }
    }
    printf("\n");

    //mul
    int size1, size2, len1, len2, mulLen;
    i = 0;
    while(1){
        if(s1t[i]=='\0') break;
        else i+=1;
    }
    size1 = i-1;
    i=0;
    while(1){
        if(s2t[i]=='\0') break;
        else i+=1;
    }
    size2 = i-1;
    if(size1>=size2){
        len1 = size1;
        len2 = size2;
    }
    if(size1<size2){
        len1 = size1;
        len2 = size2;
    }
    mulLen = len1 + len2 - 1;

    for(i=0; i<200; i++) ans[i] = '0';
    //remove '.'
    for(i=0; i<max+1; i++){
        s1[i] = '\0';
        s2[i] = '\0';
    }
    for(i=0; i<s1Dot; i++){
        s1[i] = s11[i];
        s2[i] = s22[i];
    }
    for(i=s1Dot+1; i<max+1; i++){
        s1[i-1] = s11[i];
        s2[i-1] = s22[i];
    }
    i = 0;
    while(s1t[i] != '\0'){
        if(s1t[i] == '.'){
            s1Dot = i;
        }
        i++;
    }
    muls1dot = i-1 - s1Dot;
    i = 0;
    while(s2t[i] != '\0'){
        if(s2t[i] == '.'){
            s2Dot = i;
        }
        i++;
    }
    muls2dot = i-1 - s2Dot;
    mulDot = muls1dot + muls2dot;
    mul(s1, s2, s1t, s2t, mulDot, mulLen);
    return 0;
}