#include <stdio.h>
#include <stdlib.h>

int main(){
    char s1[100], s2[100];
    scanf("%s", s1);
    getchar();
    scanf("%s", s2);
    getchar();
    printf("%c\n", s1[0]);
    printf("s1:%s\n", s1);
    printf("s1:%s\n", s2);

    return 0;
}