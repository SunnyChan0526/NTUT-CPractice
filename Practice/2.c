#include <stdio.h>
#include <math.h>
int main()
{
    int data = 8, out = 0;
    char a;
    for(int i=0; i<5; i++){
        scanf("%c", &a) + getchar(); 
        if (49<=a & a<=51){
            //printf("yes");
            a -= 48;
            data = data >> a;
            data += 8;
        }
        if(a == 72){ //H
            data = 8;
        }
        if(a == 79){ //O
            out += 1;
        }
        if(out == 3){
            out = 0;
            data = 8;
        }
        //printf("%d\n", data);
    }
    int n = data-8;
    //printf("%d\n", n);
    if (n == 0){
        for (int i=0; i<3; i++)
            printf("%d\n", 0);
    }
    else{
        //printf("------\n");
        int c[3], i = 0;
        while(n>0){
            c[i] = n%2;
            i++;
            n /= 2;
        }
        for(int i = 2; i>=0; i--){
            printf("%d\n", c[i]);   
        }    
    }
    return 0;
}