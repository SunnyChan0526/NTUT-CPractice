#include <stdio.h>
#include <string.h>
#include <math.h>
#define ShapeText(TYPE) \
char name[10];\
double (*perimeter)(struct TYPE*);\
double (*area)(struct TYPE*)

typedef struct shape_s { 
    ShapeText(shape_s); 
} shape_t;
double ShapeArea(shape_t *obj){ 
    return 0; 
}
double ShapePerimeter(shape_t *obj){ 
    return 0; 
}
void ShapeNew(shape_t *obj) {
    strcpy(obj->name, "Shape");
    obj->perimeter = ShapePerimeter;
    obj->area = ShapeArea;
}

typedef struct _C {
    ShapeText(_C);
    double radius;
} C;
typedef struct _R {
    ShapeText(_R);
    double length, width;
} R;
typedef struct _S {
    ShapeText(_S);
    double edge;
} S;
typedef struct _T {
    ShapeText(_T);
    double edge[3];
} T;

double CArea(C *obj){ 
    return obj->radius * obj->radius * 3.14; 
}
double CPerimeter(C *obj){ 
    return 2  * obj->radius * 3.14; 
}
void CNew(C *obj) {
    strcpy(obj->name,"C");
    obj->perimeter = CPerimeter;
    obj->area = CArea;
}

double RArea(R *obj){ 
    return obj->length * obj->width; 
}
double RPerimeter(R *obj){ 
    return 2  * (obj->length + obj->width); 
}
void RNew(R *obj) {
    strcpy(obj->name,"R");
    obj->perimeter = RPerimeter;
    obj->area = RArea;
}

double SArea(S *obj){ 
    return obj->edge * obj->edge; 
}
double SPerimeter(S *obj){ 
    return 4  * obj->edge; 
}
void SNew(S *obj) {
    strcpy(obj->name,"S");
    obj->perimeter = SPerimeter;
    obj->area = SArea;
}

double TArea(T *obj){ 
    float s, a;
    s = obj->perimeter(obj) / 2;
    a = s * (s - (obj->edge[0])) * (s - (obj->edge[1])) * (s - (obj->edge[2]));
    return pow(a, 0.5);
}
double TPerimeter(T *obj){     
    return obj->edge[0] + obj->edge[1] + obj->edge[2]; 
}
void TNew(T *obj) {
    strcpy(obj->name,"T");
    obj->perimeter = TPerimeter;
    obj->area = TArea;
}

int main() {
    int num;
    int i, j;
    char name[2];
    double radius, length, width, edge, perimeter = 0, area = 0;

    shape_t shape;
    ShapeNew(&shape);

    scanf("%d", &num);
    getchar();
    for(i=0; i<num; i++){
        scanf("%c", &name[0]);
        if(name[0] == 'C'){
            scanf("%lf", &radius);
            C c;
            CNew(&c);
            c.radius = radius;
            perimeter += c.perimeter(&c);
            area += c.area(&c);
            printf("%.2lf %.2lf\n", c.perimeter(&c), c.area(&c));
        }
        else if(name[0] == 'R'){
            scanf("%lf", &length);
            scanf("%lf", &width);
            R r;
            RNew(&r);
            r.length = length;
            r.width = width;
            perimeter += r.perimeter(&r);
            area += r.area(&r);
            printf("%.2lf %.2lf\n", r.perimeter(&r), r.area(&r));
        }
        else if(name[0] == 'S'){
            scanf("%lf", &edge);
            S s;
            SNew(&s);
            s.edge = edge;
            perimeter += s.perimeter(&s);
            area += s.area(&s);
            printf("%.2lf %.2lf\n", s.perimeter(&s), s.area(&s));
        }
        else{
            T t;
            TNew(&t);
            for(j=0; j<3; j++){
                scanf("%lf", &edge);
                t.edge[j] = edge;
            }
            perimeter += t.perimeter(&t);
            area += t.area(&t);
            printf("%.2lf %.2lf\n", t.perimeter(&t), t.area(&t));
        }
        getchar();
    }
    printf("%.2lf %.2lf", perimeter, area);
}