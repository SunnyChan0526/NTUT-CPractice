#include <stdio.h>

int main(){
    int n = 0, name = 0, hour = 0, class = 0;
    int array[100]; 
    int i = 0, j = 0;
    int a1 = 0, b1 = 0, c1 = 0;
    scanf("%d", &n);
    getchar();
    for(i=0; i<100; i++) array[i] = 0;
    for(i=0; i<n; i++){
        scanf("%d", &name);
        getchar();
        scanf("%d", &hour);
        for(j=0; j<hour; j++){
            scanf("%d", &class);
            getchar();
            if(array[class] == 0) array[class] = name;
            else{
                a1 = array[class];
                b1 = name;
                c1 = class;
            }
        }
    }
    printf("%d and %d conflict on %d", a1, b1, c1);
    return 0;
}