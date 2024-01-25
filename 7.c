/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    char c[2];
    float a=0, b=0;
    for(int i=0; i<3; i++){
        scanf("%s", c) + getchar();
        if(c[1] > 0)
            a += 10;
        else{
            if(c[0] == 65){
                a += 1;
            }
            else{
                if(c[0] <= 57){
                    a += c[0] - 48;
                }
                else{
                    a += 0.5;
                }
            }
        }
    }
    
    for(int i=0; i<3; i++){
        scanf("%s", c) + getchar();
        if(c[1] > 0)
            b += 10;
        else{
            if(c[0] == 65){
                b += 1;
            }
            else{
                if(c[0] <= 57){
                    b += c[0] - 48;
                }
                else{
                    b += 0.5;
                }
            }
        }
    }
    if(a>10.5)
        a = 0;
    if(b>10.5)
        b = 0;
    printf("%.1f\n", a);
    printf("%.1f\n", b);
    if(a > b)
        printf("A wins.");
    if(a < b)
        printf("B wins.");
    if(a == b)
        printf("It's a tie.");
    return 0;
}
