#include <stdio.h>
#include <stdlib.h>
#define GATEVALUE(TYPE) int(*GateValue)(int a, int b) 
typedef struct _Gate{ 
    GATEVALUE(); 
}Gate; 
int GateGetValue(){
    return 0;
}
void CreateGate(Gate *obj, int a, int b){ 
    obj->GateValue = GateGetValue; 
} 

typedef struct _GateAnd{ 
    GATEVALUE();
}GateAnd; 
int GateAndValue(int a, int b){
    return a * b;
} 
void CreateGateAND(GateAnd *obj, int a, int b){ 
    obj->GateValue = GateAndValue; 
}

typedef struct _GateOR{ 
    GATEVALUE();
}GateOR; 
int GateORValue(int a, int b){
    if(a + b >= 1){
        return 1;
    }
    else{
        return 0;
    }
} 
void CreateGateOR(GateOR *obj, int a, int b){ 
    obj->GateValue = GateORValue; 
}

typedef struct _GateXOR{ 
    GATEVALUE();
}GateXOR; 
int GateXORValue(int a, int b){
    if(a == b){
        return 0;
    }
    else{
        return 1;
    }
} 
void CreateGateXOR(GateXOR *obj, int a, int b){ 
    obj->GateValue = GateXORValue; 
}

typedef struct _GateNOT{ 
    GATEVALUE();
}GateNOT; 
int GateNOTValue(int a, int b){
    if(a == 0){
        return 1;
    }
    else{
        return 0;
    }
} 
void CreateGateNOT(GateNOT *obj, int a, int b){ 
    obj->GateValue = GateNOTValue; 
}

int main(int argc, char *argv[]){ 
    int i1, i2, i3, i4, o1, o2, o3;
    int i, j;
    int output;
    char gates[6];
    Gate gate; 
    CreateGate(&gate, i1, i2); 
    
    scanf("%d,%d,%d,%d", &i1, &i2, &i3, &i4);
    getchar();
    for(i=0; i<5; i++){
        scanf("%c,", &gates[i]);
    }
    scanf("%c", &gates[5]);
    if(gates[0] == 'A'){
        GateAnd and; 
        CreateGateAND(&and, i1, i2); 
        output = and.GateValue(i1, i2);
    }
    else if(gates[0] == 'O'){
        GateOR or; 
        CreateGateOR(&or, i1, i2); 
        output = or.GateValue(i1, i2);
    }
    else{
        GateXOR xor; 
        CreateGateXOR(&xor, i1, i2); 
        output = xor.GateValue(i1, i2);
    }
    // printf("gate:%c 0:%d\n", gates[0], output);
    if(gates[1] == 'N'){
        GateNOT not; 
        CreateGateNOT(&not, output, i2); 
        o1 = not.GateValue(output, i2); 
    }
    else{
        o1 = output;
    }
    // printf("gate:%c 1:%d\n", gates[1], o1);
    if(gates[2] == 'A'){
        GateAnd and; 
        CreateGateAND(&and, output, i3); 
        output = and.GateValue(output, i3); 
    }
    else if(gates[2] == 'O'){
        GateOR or; 
        CreateGateOR(&or, output, i3); 
        output = or.GateValue(output, i3); 
    }
    else{
        GateXOR xor; 
        CreateGateXOR(&xor, output, i3); 
        output = xor.GateValue(output, i3); 
    }
    // printf("gate:%c 2:%d\n", gates[2], output);
    if(gates[3] == 'A'){
        GateAnd and; 
        CreateGateAND(&and, output, o1); 
        o2 = and.GateValue(output, o1); 
    }
    else if(gates[3] == 'O'){
        GateOR or; 
        CreateGateOR(&or, output, o1); 
        o2 = or.GateValue(output, o1); 
    }
    else{
        GateXOR xor; 
        CreateGateXOR(&xor, output, o1); 
        o2 = xor.GateValue(output, o1); 
    }
    // printf("gate:%c 3:%d\n", gates[3], o2);
    if(gates[4] == 'A'){
        GateAnd and; 
        CreateGateAND(&and, output, i4); 
        output = and.GateValue(output, i4); 
    }
    else if(gates[4] == 'O'){
        GateOR or; 
        CreateGateOR(&or, output, i4); 
        output = or.GateValue(output, i4); 
    }
    else{
        GateXOR xor; 
        CreateGateXOR(&xor, output, i4); 
        output = xor.GateValue(output, i4); 
    }
    // printf("gate:%c 4:%d\n", gates[4], output);
    if(gates[5] == 'A'){
        GateAnd and; 
        CreateGateAND(&and, output, o2); 
        o3 = and.GateValue(output, o2); 
    }
    else if(gates[5] == 'O'){
        GateOR or; 
        CreateGateOR(&or, output, o2); 
        o3 = or.GateValue(output, o2); 
    }
    else{
        GateXOR xor; 
        CreateGateXOR(&xor, output, o2); 
        o3 = xor.GateValue(output, o2); 
    }
    // printf("gate:%c 5:%d\n", gates[5], o3);
    printf("%d,%d,%d", o1, o2, o3);
    return 0; 
}