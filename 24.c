#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum scoreType_s {G, GPA, S} scoreType_t;
typedef enum gradeG_s {APlus=95, A=87, AMinus=82, BPlus=78, B=75, BMinus=70, CPlus=68, C=65, CMinus=60, F=50} gradeG_t;
typedef enum gradeGPA_s {a=95, b=87, c=82, d=78, e=75, f=70, g=68, h=65, i=60, j=50} gradeGPA_t;
typedef enum gradeS_s {aa=95, bb=87, cc=82, dd=78, ee=75, ff=70, gg=68, hh=65, ii=60, jj=50} gradeS_t;
typedef union score_s {
    gradeG_t gradeG;
    gradeGPA_t gradeGPA;
    gradeS_t gradeS;
} score_t;

int indexx(char grade[10], char s[10][10]){
    int i = 0;
    for(i=0; i<10; i++){
        if(!strcmp(grade, s[i])){
            break;
        }
    }
    return i;
}

int main (){
    int m = 0, n = 0, indexs = 0;
    int i = 0, j = 0, k = 0;
    char id[50][50];
    char grade[10], way[50][10];
    char Gs[10][10] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "F"};
    char GPAs[10][10] = {"4.3", "4.0", "3.7", "3.3", "3.0", "2.7", "2.3", "2.0", "1.7", "0"};
    char Ss[10][10] = {"90-100", "85-89", "80-84", "77-79", "73-76", "70-72", "67-69", "63-66", "60-62", "0-59"};
    int score[10] = {95, 87, 82, 78, 75, 70, 68, 65, 60, 50};
    int indexStudent[3];
    double StudentScore[50], StudentScoreS[50], max = 0;
    for(i=0; i<50; i++){
        StudentScore[i] = 0;
    }

    scanf("%d", &m);
    getchar();
    scoreType_t type[m];
    for(i=0; i<m; i++){
        scanf("%s", way[i]);
        getchar();
    }
    scanf("%d", &n);
    getchar();
    score_t student[n];
    for(i=0; i<n; i++){
        scanf("%s", id[i]);
        getchar();
        for(j=0; j<m; j++){
            for(k=0; k<10; k++){
                grade[k] = '\0';
            }
            scanf("%s", grade);
            getchar();
            if(!strcmp(way[j], "G")){
                type[j] = G;
                indexs = indexx(grade, Gs);
                student[i].gradeG = score[indexs];
                StudentScore[i] += student[i].gradeG;
            }
            if(!strcmp(way[j], "GPA")){
                type[j] = GPA;
                indexs = indexx(grade, GPAs);
                student[i].gradeGPA = score[indexs];
                StudentScore[i] += student[i].gradeGPA;
            }
            if(!strcmp(way[j], "S")){
                type[j] = S;
                indexs = indexx(grade, Ss);
                student[i].gradeS = score[indexs];
                StudentScore[i] += student[i].gradeS;
            }
        }
        StudentScore[i] /= m;
    }
    for(i=0; i<n; i++){
        StudentScoreS[i] = StudentScore[i];
        // printf("%f %f\n", StudentScore[i], StudentScoreS[i]);
    }
    for(i=0; i<n; i++){
        max = StudentScoreS[i];
        for(j=i+1; j<n; j++){
            if(StudentScoreS[j] > max){
                max = StudentScoreS[j];
                StudentScoreS[j] = StudentScoreS[i];
                StudentScoreS[i] = max;
            }
        }
    }
    // printf("------\n");
    // for(i=0; i<n; i++){
    //     printf("%f\n", StudentScoreS[i]);
    // }
    
    //id
    for(i=0; i<3; i++){
        for(j=0; j<n; j++){
            if(StudentScoreS[i] == StudentScore[j]){
                indexStudent[i] = j;
                break;
            }
        }
    }
    // printf("------\n");
    for(i=0; i<3; i++){
        printf("%s\n", id[indexStudent[i]]);
        printf("%ld\n", lround(StudentScoreS[i]));
    }
    return(0);
}