/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    int n[100], k[100], ans[100];
    int i=0, stop=0, num=0, a=0, b=0, j=0, l=0, judge=0;
    while(1){
        scanf("%d %d", &n[i], &k[i]);
        i += 1;
        scanf("%d", &stop);
        num += 1;
        if(stop == -1) break;
    }
    for(i=0; i<num; i++){
        a = n[i];
        b = k[i];
        j = 0;
        while(1){
            judge = pow(2, a-1);
            //printf("%d %d %d\n", a, b, judge);
            if(b < judge){
                ans[j] = 0;
            }
            if(b >= judge){
                ans[j] = 1;
                b = pow(2, a)-1-b;
            }
            a -= 1;
            j += 1;
            if(a == 0) break;
        }
        for(l=0; l<j; l++){
            printf("%d", ans[l]);
        }
        printf("\n");
    }
    
    
    return 0;
}
