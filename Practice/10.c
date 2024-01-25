/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    char in[100][8], out[4];
    int rRecord[100];
    int i=0, j=0, sum=0, a=1, m=0, r=0, stop=0;
    while(1){
        sum=0, a=1, m=0, r=0;
        for(j=0; j<8; j++){
            scanf("%c", &in[i][j]);
            in[i][j] -= 48;
        }
        getchar();
        for(j=7; j>=0; j--){
            sum += a*in[i][j];
            a *= 2;
        }
        //printf("%d\n", sum);
        m = sum;
        while(1){
            if(m==1 || m==0) break;
            if(m%2 == 0){
                m /= 2;
            }
            else{
                m = (m+1)/2;
            }
            r += 1;
        }
        rRecord[i] = r;
        scanf("%d", &stop) + getchar();
        i += 1;
        if(stop == -1) break;
    }
    
    /*for(int k=0; k<i; k++){
        printf("%d\n", rRecord[k]);  
    }*/
    //printf("%d\n", i);
    int b=0;
    for(int k=0; k<i; k++){
        b = rRecord[k];
        for(int l=3; l>=0; l--){
            out[l] = b%2;
            b /= 2;
        }
        for(int l=0; l<4; l++){
            printf("%d", out[l]);
        }
        printf("\n");
    }
    
    return 0;
}

