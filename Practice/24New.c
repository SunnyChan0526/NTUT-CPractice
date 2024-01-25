#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum scoreType_ {G, GPA, S} scoreType;
typedef enum G_ {A1=95, A=87, A0=82, B1=78, B=75, B0=70, C1=68, C=65, C0=60, F=50} G_t;
typedef enum GPA_ {a=95, b=87, c=82, d=78, e=75, f=70, g=68, h=65, i=60, j=50} GPA_t;
typedef enum S_ {aa=95, bb=87, cc=82, dd=78, ee=75, ff=70, gg=68, hh=65, ii=60, jj=50} S_t;
typedef union score_{
    G_t gradeG;
    GPA_t gradeGPA;
    S_t gradeS;
} score;

int main(){
    int m, n;
    double totalScore, average;
    int i, j, k;
    char way[10][5], id[20][10], inSocre[5];
    scanf("%d", &m);
    getchar();
    for(i=0; i<m; i++){
        scanf("%s", way[i]);
        getchar();
    }
    scanf("%d", &n);
    getchar();
    scoreType type[m];
    score student[n];
    for(i=0; i<n; i++){
        scanf("%s", id[i]);
        getchar();
        totalScore = 0;
        for(j=0; j<m; j++){
            for(k=0; k<5; k++){
                inSocre[k] = '\0';
            }
            scanf("%s", inSocre);
            getchar();
            if(!strcmp(way[j], "G")){
                type[j] = G;
                if(!strcmp(inSocre, "A+")){
                    student[i].gradeG = A1;
                }
                else if(!strcmp(inSocre, "A")){
                    student[i].gradeG = A;
                }
                else if(!strcmp(inSocre, "A-")){
                    student[i].gradeG = A0;
                }
                else if(!strcmp(inSocre, "B+")){
                    student[i].gradeG = B1;
                }
                else if(!strcmp(inSocre, "B")){
                    student[i].gradeG = B;
                }
                else if(!strcmp(inSocre, "B-")){
                    student[i].gradeG = B0;
                }
                else if(!strcmp(inSocre, "C+")){
                    student[i].gradeG = C1;
                }
                else if(!strcmp(inSocre, "C")){
                    student[i].gradeG = C;
                }
                else if(!strcmp(inSocre, "C-")){
                    student[i].gradeG = C0;
                }
                else{
                    student[i].gradeG = F;
                }
                totalScore += student[i].gradeG;
            }
            else if(!strcmp(way[j], "GPA")){
                type[j] = GPA;
                if(!strcmp(inSocre, "4.3")){
                    student[i].gradeGPA = a;
                }
                else if(!strcmp(inSocre, "4.0")){
                    student[i].gradeGPA = b;
                }
                else if(!strcmp(inSocre, "3.7")){
                    student[i].gradeGPA = c;
                }
                else if(!strcmp(inSocre, "3.3")){
                    student[i].gradeGPA = d;
                }
                else if(!strcmp(inSocre, "3.0")){
                    student[i].gradeGPA = e;
                }
                else if(!strcmp(inSocre, "2.7")){
                    student[i].gradeGPA = f;
                }
                else if(!strcmp(inSocre, "2.3")){
                    student[i].gradeGPA = g;
                }
                else if(!strcmp(inSocre, "2.0")){
                    student[i].gradeGPA = h;
                }
                else if(!strcmp(inSocre, "1.7")){
                    student[i].gradeGPA = i;
                }
                else{
                    student[i].gradeGPA = j;
                }
                totalScore += student[i].gradeGPA;
            }
            else{
                type[j] = S;
                if(!strcmp(inSocre, "4.3")){
                    student[i].gradeS = aa;
                }
                else if(!strcmp(inSocre, "4.0")){
                    student[i].gradeS = bb;
                }
                else if(!strcmp(inSocre, "3.7")){
                    student[i].gradeS = cc;
                }
                else if(!strcmp(inSocre, "3.3")){
                    student[i].gradeS = dd;
                }
                else if(!strcmp(inSocre, "3.0")){
                    student[i].gradeS = ee;
                }
                else if(!strcmp(inSocre, "2.7")){
                    student[i].gradeS = ff;
                }
                else if(!strcmp(inSocre, "2.3")){
                    student[i].gradeS = gg;
                }
                else if(!strcmp(inSocre, "2.0")){
                    student[i].gradeS = hh;
                }
                else if(!strcmp(inSocre, "1.7")){
                    student[i].gradeS = ii;
                }
                else{
                    student[i].gradeS = jj;
                }
                totalScore += student[i].gradeS;
            }
            // printf("%d\n", totalScore);
        }
        // printf("%f\n", totalScore);
        average = totalScore / m;
        printf("%.5lf\n", average);
    }
    return 0;
}