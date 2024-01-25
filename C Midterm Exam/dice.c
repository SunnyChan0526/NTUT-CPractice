#include <stdio.h>

void up(int array[6]){
    int b[6];
    for(int i=0; i<6; i++) b[i] = array[i];
    array[0] = b[1];
    array[1] = b[3];
    array[2] = b[2];
    array[3] = b[4];
    array[4] = b[0];
    array[5] = b[5];
}
void down(int array[6]){
    int b[6];
    for(int i=0; i<6; i++) b[i] = array[i];
    array[0] = b[4];
    array[1] = b[0];
    array[2] = b[2];
    array[3] = b[1];
    array[4] = b[3];
    array[5] = b[5];
}
void right(int array[6]){
    int b[6];
    for(int i=0; i<6; i++) b[i] = array[i];
    array[0] = b[5];
    array[1] = b[1];
    array[2] = b[0];
    array[3] = b[2];
    array[4] = b[4];
    array[5] = b[3];
}
void left(int array[6]){
    int b[6];
    for(int i=0; i<6; i++) b[i] = array[i];
    array[0] = b[2];
    array[1] = b[1];
    array[2] = b[3];
    array[3] = b[5];
    array[4] = b[4];
    array[5] = b[0];
}

int main(){
    int n=0;
    int i=0;
    int a[100], b[100], c[100], d[100];
    int array[6] = {1, 4, 2, 6, 3, 5};
    int arrayTemp[6] = {1, 4, 2, 6, 3, 5};
    int num[4];
    scanf("%d", &n);
    getchar();
    for (i=0; i<n; i++){
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    for (i=0; i<n; i++){
        if(a[i]==1){
            up(array);
        }
        if(a[i]==2){
            down(array);
        }
        if(a[i]==3){
            right(array);
        }
        if(a[i]==4){
            left(array);
        }
    }
    num[0] = array[0];
    for(i=0; i<6; i++) array[i] = arrayTemp[i];
    for (i=0; i<n; i++){
        if(b[i]==1){
            up(array);
        }
        if(b[i]==2){
            down(array);
        }
        if(b[i]==3){
            right(array);
        }
        if(b[i]==4){
            left(array);
        }
    }
    num[1] = array[0];
    for(i=0; i<6; i++) array[i] = arrayTemp[i];
    for (i=0; i<n; i++){
        if(c[i]==1){
            up(array);
        }
        if(c[i]==2){
            down(array);
        }
        if(c[i]==3){
            right(array);
        }
        if(c[i]==4){
            left(array);
        }
    }
    num[2] = array[0];
    for(i=0; i<6; i++) array[i] = arrayTemp[i];
    for (i=0; i<n; i++){
        if(d[i]==1){
            up(array);
        }
        if(d[i]==2){
            down(array);
        }
        if(d[i]==3){
            right(array);
        }
        if(d[i]==4){
            left(array);
        }
    }
    num[3] = array[0];
    //for(i=0; i<4; i++) printf("%d ", num[i]);
    //printf("\n");

    int Carray[3];
    int count = 0, temp = 0;
    int j = 0, ans = 0;
    for(i=0; i<3; i++){
        count = 0;
        for(j=i+1; j<4; j++){
            if(num[i] == num[j]) count += 1;
        }
        Carray[i] = count;
    }
    //for(i=0; i<3; i++) printf("%d ", Carray[i]);
    //printf("\n");
    if(Carray[0] == 3) ans = 18;

    int one = 0, zero = 0, two = 0, max = num[0];
    for(i=0; i<3; i++){
        if(Carray[i] == 0) zero += 1;
        if(Carray[i] == 1){
            one += 1;
            temp = num[i];
        }
        if(Carray[i] == 2) two += 1;
        if(num[i]>max) max = num[i];
    }
    if(zero == 1 && one == 2) ans = 2*max;
    //printf("temp:%d\n", temp);
    if(zero == 2 && one == 1){
        for(i=0; i<4; i++){
            if(num[i] != temp) ans += num[i];
        }
    }
    printf("%d", ans);
    //if(zero == 3 || (two==1 && zero == 1 ))
    return 0;
}