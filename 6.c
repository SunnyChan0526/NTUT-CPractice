#include <stdio.h>

int main()
{
    int a[5];
    float m[3];
    for(int i=0; i<5; i++){
        scanf("%d", &a[i]);
    }
    m[0] = a[0]*0.08+a[1]*0.1393+a[2]*0.1349+a[3]*1.1287+a[4]*1.4803;
    m[1] = a[0]*0.07+a[1]*0.1304+a[2]*0.1217+a[3]*1.1127+a[4]*1.2458;
    m[2] = a[0]*0.06+a[1]*0.1087+a[2]*0.1018+a[3]*0.9572+a[4]*1.1243;

    if(m[0]<183){
        m[0] = 183;
    }
    if(m[1]<383){
        m[1] = 383;
    }
    if(m[2]<983){
        m[2] = 983;
    }
    //printf("%f %f %f", m[0], m[1], m[2]);
    float sort[3] = {m[0], m[1], m[2]}, n=0;
    for(int i=0; i<3; i++){
        for(int j=i+1; j<3; j++){
            if(sort[i]>sort[j]){
                n = sort[i];
                sort[i] = sort[j];
                sort[j] = n;
            }
        }
    }
    int name[3] = {183, 383, 983}, ans=0;
    for(int i=0; i<3; i++){
        if(sort[0] == m[i]){
            ans = i;
            break;
        }
    }
    printf("%d", name[ans]);
    return 0;
}
