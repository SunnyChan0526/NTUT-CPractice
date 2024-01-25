#include <stdio.h>

int main()
{
    char s1[100], s2[100];
    char temp[100], sub[100];
    int i=0, j=0, k=0;
    int size=0, n=0, c=0;
    scanf("%s", s1);
    getchar();
    scanf("%s", s2);
    while(1){
        if(s2[size]=='\0') break;
        size += 1;
    }
    for(i=0; i<size; i++) sub[i] = s1[i];
    while(1){
        for(i=1; i<10; i++){
            temp[0] = '0';
            for(j=size-1; j>=0; j--){
                n = (s2[j]-48) * i + c;
                if(n<10){
                    temp[j+1] = n+48;
                    c = 0;
                }
                else{
                    temp[j+1] = n%10 +48;
                    c = n/10;
                }
            }
            if(c>0) temp[0] = c+48;
            else temp[0] = '0';
            if(temp[0]==sub[0]){
                if(temp)
            }
           
        }
        printf("%c %c %d %d", temp[0], sub[0], k, size-1);
        if((temp[0]==sub[0]) && (k==size-1)) break; 
    }
    printf("%d %s", i, temp);



    return 0;
}
