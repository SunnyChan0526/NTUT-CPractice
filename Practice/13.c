#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1=0, y1=0, x2=0, y2=0, mu=0, md=0, bu=0, bd=0, buu=0, bdd=0, muu=0, mdd=0;
    int i=0, j=0, k=0;
    int min=0, size_bu=0, size_bd=0, size_mu=0, size_md=0, mfront=0, bfront=0, size_mfront=0, size_bfront=0;
    char s[20];
    scanf("%d,%d", &x1, &y1);
    scanf("%d,%d", &x2, &y2);
    mu = y1-y2;
    md = x1-x2;
    bu = x2*y1-x1*y2;
    bd = x2-x1;
    //printf("%d %d %d %d\n", mu, md ,bu, bd);
    //mu=3, md=4, bu=-17, bd=2;

    for(i=0; i<20; i++) s[i] = 'a';
    s[0] = 'y';
    s[1] = '=';

    buu = abs(bu);
    bdd = abs(bd);
    if(buu>bdd) min = bdd;
    else min = buu;
    for(i=min; i>1; i--){
        if(buu%i==0 && bdd%i==0) break;
    }
    if(i>1){
        buu /= i;
        bdd /= i;
    }

    if(buu>bdd && bdd!=1){
        bfront = buu/bdd;
        buu = buu - bfront*bdd;
    }

    j = buu;
    while(1){
        j/=10;
        size_bu += 1;
        if(j==0) break;
    }
    j = bdd;
    while(1){
        j/=10;
        size_bd += 1;
        if(j==0) break;
    }
    j = bfront;
    while(1){
        j/=10;
        size_bfront += 1;
        if(j==0) break;
    }

    muu = abs(mu);
    mdd = abs(md);
    if(muu>mdd) min = mdd;
    else min = muu;
    for(i=min; i>1; i--){
        if(muu%i==0 && mdd%i==0) break;
    }
    if(i>1){
        muu /= i;
        mdd /= i;
    }

    if(muu>mdd && mdd!=1){
        mfront = muu/mdd;
        muu = muu - mfront*mdd;
    }

    j = muu;
    while(1){
        j/=10;
        size_mu += 1;
        if(j==0) break;
    }
    j = mdd;
    while(1){
        j/=10;
        size_md += 1;
        if(j==0) break;
    }
    j = mfront;
    while(1){
        j/=10;
        size_mfront += 1;
        if(j==0) break;
    }
/////////////////////////////////

    if(mu==0){
        if(bu==0) s[2] = '0';
        else{
            if(bu*bd<0){
                s[2] = '-';
                k = 2;
            }
            else k = 1;

            if(bdd==1){
                for(i=size_bu; i>0; i--){
                    s[k+i] = buu%10 + 48;
                    buu /= 10;
                }
            }
            else{
                if(bfront==0){
                    for(i=size_bu; i>0; i--){
                        s[k+i] = buu%10 + 48;
                        buu /= 10;
                    }
                    s[k+size_bu+1] = '/';
                    for(i=size_bd; i>0; i--){
                        s[k+size_bu+1+i] = bdd%10 + 48;
                        bdd /= 10;
                    }
                }
                else{
                    for(i=size_bfront; i>0; i--){
                        s[k+i] = bfront%10 + 48;
                        bfront /= 10;
                    }
                    s[k+size_bfront+1] = '(';
                    for(i=size_bu; i>0; i--){
                        s[k+size_bfront+1+i] = buu%10 + 48;
                        buu /= 10;
                    }
                    s[k+size_bfront+1+size_bu+1] = '/';
                    for(i=size_bd; i>0; i--){
                        s[k+size_bfront+1+size_bu+1+i] = bdd%10 + 48;
                        bdd /= 10;
                    }
                    s[k+size_bfront+1+size_bu+1+size_bd+1] = ')';
                }
            }
        }
    }
    else{
        if(mu*md<0){
            s[2] = '-';
            k = 2;
        }
        else k = 1;

        if(mdd==1 && muu!=1){
            for(i=size_mu; i>0; i--){
                s[k+i] = muu%10 + 48;
                muu /= 10;
            }
        }
        else{
            if((mfront==0) && !(muu==1 && mdd==1)){
                for(i=size_mu; i>0; i--){
                    s[k+i] = muu%10 + 48;
                    muu /= 10;
                }
                s[k+size_mu+1] = '/';
                for(i=size_md; i>0; i--){
                    s[k+size_mu+1+i] = mdd%10 + 48;
                    mdd /= 10;
                }
            }
            if((mfront!=0) && !(muu==1 && mdd==1)){
                for(i=size_mfront; i>0; i--){
                    s[k+i] = mfront%10 + 48;
                    mfront /= 10;
                }
                s[k+size_mfront+1] = '(';
                for(i=size_mu; i>0; i--){
                    s[k+size_mfront+1+i] = muu%10 + 48;
                    muu /= 10;
                }
                s[k+size_mfront+1+size_mu+1] = '/';
                for(i=size_md; i>0; i--){
                    s[k+size_mfront+1+size_mu+1+i] = mdd%10 + 48;
                    mdd /= 10;
                }
                s[k+size_mfront+1+size_mu+1+size_md+1] = ')';
            }
        }
     
        for(j=0; j<20; j++){
            if(s[j]=='a') break;
        }
        s[j] = 'x';
        if(buu!=0){
            if(bu*bd<0) s[j+1] = '-';
            else s[j+1] = '+';

            k = j+1;
            if(bdd==1){
                for(i=size_bu; i>0; i--){
                    s[k+i] = buu%10 + 48;
                    buu /= 10;
                }
            }
            else{
                if(bfront==0){
                    for(i=size_bu; i>0; i--){
                        s[k+i] = buu%10 + 48;
                        buu /= 10;
                    }
                    s[k+size_bu+1] = '/';
                    for(i=size_bd; i>0; i--){
                        s[k+size_bu+1+i] = bdd%10 + 48;
                        bdd /= 10;
                    }
                }
                else{
                    for(i=size_bfront; i>0; i--){
                        s[k+i] = bfront%10 + 48;
                        bfront /= 10;
                    }
                    s[k+size_bfront+1] = '(';
                    for(i=size_bu; i>0; i--){
                        s[k+size_bfront+1+i] = buu%10 + 48;
                        buu /= 10;
                    }
                    s[k+size_bfront+1+size_bu+1] = '/';
                    for(i=size_bd; i>0; i--){
                        s[k+size_bfront+1+size_bu+1+i] = bdd%10 + 48;
                        bdd /= 10;
                    }
                    s[k+size_bfront+1+size_bu+1+size_bd+1] = ')';
                }
            }
        }
    }
    i=0;
    while(1){
        if(s[i]=='a') break;
        printf("%c", s[i]);
        i+=1;
    }
    return 0;
}