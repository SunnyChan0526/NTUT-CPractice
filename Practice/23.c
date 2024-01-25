#include <stdio.h>

void c(int magic[54], int add){
    int temp[54];
    int i = 0, j = 0;
    for(i=0; i<54; i++) temp[i] = magic[i];
    j = 9;
    for(i=0; i<=24; i+=3){
        magic[i+add] = temp[j+add];
        j += 3;
    }
    magic[27+add] = temp[0+add];
    magic[30+add] = temp[3+add];
    magic[33+add] = temp[6+add];
}
void r(int magic[54], int add){
    int temp[54];
    int i = 0, j = 0;
    for(i=0; i<54; i++) temp[i] = magic[i];
    j = 9;
    for(i=36; i<=38; i++){
        magic[i+add] = temp[j+add];
        j++;
    }
    j = 45;
    for(i=9; i<=11; i++){
        magic[i+add] = temp[j+add];
        j++;
    }
    j = 27;
    for(i=45; i<=47; i++){
        magic[i+add] = temp[j+add];
        j++;
    }
    j = 36;
    for(i=27; i<=29; i++){
        magic[i+add] = temp[j+add];
        j++;
    }
}

int main(){
    int n = 0, s = 0, add = 0;
    int i = 0, j = 0, k = 0;
    int magic[54] = {1, 1, 1, 1, 1, 1, 1, 1, 1,
                     4, 4, 4, 4, 4, 4, 4, 4, 4,
                     6, 6, 6, 6, 6, 6, 6, 6, 6,
                     3, 3, 3, 3, 3, 3, 3, 3, 3,
                     5, 5, 5, 5, 5, 5 ,5 ,5 ,5,
                     2, 2, 2, 2, 2, 2, 2, 2, 2};
    int a1[9] = {42, 39, 36, 43, 40, 37, 44, 41, 38},
        a2[9] = {51, 48, 45, 52, 49, 46, 53, 50, 47},
        a3[9] = {6, 3, 0, 7, 4, 1, 8, 5, 2},
        a4[9] = {24, 21, 18, 25, 22, 19, 26, 23, 20};
    int temp[54];
    scanf("%d", &n);
    getchar();
    for(i=0; i<n; i++){
        scanf("%d", &s);
        getchar();
        if(s == 10){
            add = 0;
            c(magic, add);
            for(j=0; j<54; j++) temp[j] = magic[j];
            k = 0;
            for(j=36; j<=44; j++){
                magic[j] = temp[a1[k]];
                k++;
            }
        }
        if(s == 11){
            add = 1;
            c(magic, add);
        }
        if(s == 12){
            add = 2;
            c(magic, add);
            for(j=0; j<54; j++) temp[j] = magic[j];
            k = 0;
            for(j=45; j<=53; j++){
                magic[j] = temp[a2[k]];
                k++;
            }
        }
        if(s == 20){
            add = 0;
            r(magic, add);
            for(j=0; j<54; j++) temp[j] = magic[j];
            k = 0;
            for(j=0; j<=8; j++){
                magic[j] = temp[a3[k]];
                k++;
            }
        }
        if(s == 21){
            add = 3;
            r(magic, add);
        }
        if(s == 22){
            add = 6;
            r(magic, add);
            for(j=0; j<54; j++) temp[j] = magic[j];
            k = 0;
            for(j=18; j<=26; j++){
                magic[j] = temp[a4[k]];
                k++;
            }
        }
    }
    for(i=0; i<9; i++){
        printf("%d ", magic[i]);
        if(i == 2 || i == 5 || i == 8) printf("\n");
    }
    return 0;
}