#include <stdio.h>

typedef struct data{
    int machine;
    int hour;
    int over;
} data_t;

int calculateOverTime(data_t work, data_t lastWork, int schedule[100][10000], int item, int machineMax[]){
    int thisMachine, start, lastWorkFinish;
    int i, j;
    thisMachine = work.machine;
    start = machineMax[thisMachine];
    if(item == 0){
        lastWorkFinish = 0;
    }
    else{
        lastWorkFinish = lastWork.over;
    }
    if(start > lastWorkFinish){
        return start + work.hour;
    }
    else{
        return lastWorkFinish + work.hour;
    }
}
int min(int selectArray[], int m){
    int min, cpy[100], value;
    int i, j;
    for(i=0; i<100; i++){
        cpy[i] = selectArray[i];
    }
    for(i=0; i<m; i++){
        min = cpy[i];
        for(j=i+1; j<m; j++){
            if(min > cpy[j]){
                min = cpy[j];
                cpy[j] = cpy[i];
                cpy[i] = min;
            }
        }
    }
    value = cpy[0];
    for(i=0; i<m; i++){
        if(value == selectArray[i]){
            break;
        }
    }
    return i;
}
void fill(int schedule[100][10000], data_t work, int select, int item){
    int thisMachine, start;
    int i;
    thisMachine = work.machine;
    for(i=work.over-1; i>work.over-1-work.hour; i--){
        schedule[thisMachine][i] = select + 1;
    }
}

int main(){
    int n, m, p;
    int i, j, k;
    int schedule[100][10000], order[100], workNum[100], selectArray[100], machineMax[100];
    int item, overTime, select, stop = 0, total = 0;
    scanf("%d %d", &n, &m);
    getchar();
    data_t work[100][100];
    for(i=0; i<m; i++){
        scanf("%d", &p);
        workNum[i] = p;
        for(j=0; j<p; j++){
            scanf("%d %d", &work[i][j].machine, &work[i][j].hour);
        }
    }
    for(i=0; i<100; i++){
        machineMax[i] = 0;
        for(j=0; j<10000; j++){
            schedule[i][j] = 0;
        }
    }
    for(i=0; i<m; i++){
        order[i] = 0;
    }
    while(1){
        for(i=0; i<100; i++){
            selectArray[i] = 0;
        }
        for(i=0; i<m; i++){
            item = order[i];
            if(item == workNum[i]){
                selectArray[i] = 100000000;
                continue;
            }
            if(item == 0){
                overTime = calculateOverTime(work[i][item], work[i][item], schedule, item, machineMax);
            }
            else{
                overTime = calculateOverTime(work[i][item], work[i][item-1], schedule, item, machineMax);
            }
            selectArray[i] = overTime;
        }
        select = min(selectArray, m);
        item = order[select];
        work[select][item].over = selectArray[select];
        machineMax[work[select][item].machine] = work[select][item].over;
        fill(schedule, work[select][item], select, item);
        order[select] += 1;
        for(i=0; i<m; i++){
            if(order[i] == workNum[i]){
                stop += 1;
            }
        }
        if(stop == m){
            break;
        }
        else{
            stop = 0;
        }
    }
    for(i=0; i<m; i++){
        total += work[i][workNum[i]-1].over;
    }
    printf("%d", total);
    return 0;
}