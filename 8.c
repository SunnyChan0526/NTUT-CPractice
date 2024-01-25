/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int type=0, num=0, column = 0;
    scanf("%d", &type);
    scanf("%d", &num);
    column = num / 2;
    if(type == 1){
        for(int i=1; i<=column+1; i++){
            for(int j=0 ; j<i; j++){
                printf("*");
            }
            printf("\n");
        }
        for(int i=column; i>0; i--){
            for(int j=0; j<i; j++){
                printf("*");
            }
            printf("\n");
        }
    }
    if(type == 2){
        for(int i=column; i>=0; i--){
            for(int j=0; j<i; j++){
                printf(".");
            }
            for(int j=0; j<column+1-i; j++){
                printf("*");
            }
            printf("\n");
        }
        for(int i=1; i<=column; i++){
            for(int j=0; j<i; j++){
                printf(".");
            }
            for(int j=0; j<column+1-i; j++){
                printf("*");
            }
            printf("\n");
        }
    }
    if(type == 3){
        int k = 1;
        for(int i=column; i>=0; i--){
            for(int j=0; j<i; j++){
                printf(".");
            }
            for(int j=0; j<k; j++){
                printf("*");
            }
            k += 2; //k==7
            printf("\n");
        }
        k -= 4;
        for(int i=1; i<=column; i++){
            for(int j=0; j<i; j++){
                printf(".");
            }
            for(int j=0; j<k; j++){
                printf("*");
            }
            k -= 2; 
            printf("\n");
        }
    }
    return 0;
}
