#include <stdio.h>
#include <string.h>
#include <math.h>
#define shapeText(TYPE) char name[10];\
int (*perimeter)(struct TYPE*);\
int (*area)(struct TYPE*);

typedef struct shape_s { 
    shapeText(shape_s); 
} shape_t;

typedef struct circle_s { 
    shapeText(circle_s); 
    int radius;
} circle_t;

int CP(circle_t *obj){
    return 2 * obj->radius * 4;
}
int CA(circle_t *obj){
    return obj->radius * obj->radius * 4;
}
void newC(circle_t *obj){
    obj->perimeter = CP;
    obj->area = CA;
}

typedef struct rectangle_s { 
    shapeText(rectangle_s);
    int width, height; 
} rectangle_t;
int RP(rectangle_t *obj){
    return 2 * (obj->width + obj->height);
}
int RA(rectangle_t *obj){
    return obj->width * obj->height;
}
void newR(rectangle_t *obj){
    obj->perimeter = RP;
    obj->area = RA;
}

typedef struct square_s{ 
    shapeText(square_s);
    int side; 
} square_t;
int SP(square_t *obj){
    return 4 * obj->side;
}
int SA(square_t *obj){
    return obj->side * obj->side;
}
void newS(square_t *obj){
    obj->perimeter = SP;
    obj->area = SA;
}

typedef struct triangle_s { 
    shapeText(triangle_s); 
    int s1, s2, s3;
} triangle_t;
int TP(triangle_t *obj){
    return obj->s1 + obj->s2 + obj->s3;
}
int TA(triangle_t *obj){
    double s = (obj->s1 + obj->s2 + obj->s3) / 2;
    return pow( s * (s-obj->s1) * (s-obj->s2) * (s-obj->s3) , 0.5 );
}
void newT(triangle_t *obj){
    obj->perimeter = TP;
    obj->area = TA;
}

int main(){
    int n, radius, width, height, side, s1, s2, s3, tp = 0, ta = 0;
    char name[10];
    circle_t c;
    rectangle_t r;
    square_t s;
    triangle_t t;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            name[j] = '\0';
        }
        scanf("%s", name);
        getchar();
        if(!strcmp(name, "circle")){
            scanf("%d", &radius);
            newC(&c);
            c.radius = radius;
            tp += c.perimeter(&c);
            ta += c.area(&c);
            printf("circle %d %d\n", c.perimeter(&c), c.area(&c));
        }
        else if(!strcmp(name, "rectangle")){
            scanf("%d %d", &width, &height);
            newR(&r);
            r.width = width;
            r.height = height;
            tp += r.perimeter(&r);
            ta += r.area(&r);
            printf("rectangle %d %d\n", r.perimeter(&r), r.area(&r));
        }   
        else if(!strcmp(name, "square")){
            scanf("%d", &side);
            newS(&s);
            s.side = side;
            tp += s.perimeter(&s);
            ta += s.area(&s);
            printf("square %d %d\n", s.perimeter(&s), s.area(&s));
        }
        else if(!strcmp(name, "triangle")){
            scanf("%d %d %d", &s1, &s2, &s3);
            newT(&t);
            t.s1 = s1;
            t.s2 = s2;
            t.s3 = s3;
            tp += t.perimeter(&t);
            ta += t.area(&t);
            printf("triangle %d %d\n", t.perimeter(&t), t.area(&t));
        }
        getchar();
    }
    printf("%d %d", tp, ta);
    return 0;
}