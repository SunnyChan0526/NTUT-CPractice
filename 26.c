#include <stdio.h>
#include <math.h>

double f1(double a, double x){
    // return fabs( pow( ( a - pow(x, 2) ) ,0.5) );
    return fabs( pow((a - x * x) , 0.5) );
}
double f2(double a, double x){
    // return fabs( ( ( a * pow(x, 3) ) + 7*x )  / pow((a+x), 0.5) );
    return fabs( (a*x*x*x + 7*x) / (pow( a+x , 0.5)) );
}
double integral(double (*f)(double, double), int n, double x, double y, double a) {
    int i;
    double len = 0;
    double gap = fabs(y - x) / n;
    len += (*f)(a, x);
    for (i = 0; i < n-1; i++) {
        x += gap;
        len += 2 * (*f)(a, x);
    }
    len += (*f)(a, x + gap);
    return (gap/2) * len;
}
int main() {
    int select = 0, p = 0, q = 0, err = 0, n = 0;
    double a = 0;
    double (*f)(double, double); // f: a pointer to function(double) returning double
    double n1 = 0, n2 = 0;
    while(1){
        scanf("%d", &select);
        getchar();
        if(select == 0){
            break;
        }
        if(select == 1){
            f = f1;
        }
        if(select == 2){
            f = f2;
        }
        scanf("%lf\n%d\n%d\n%d", &a, &p, &q, &err);        
        n = 2;
        while(1){
            n1 = integral(f, n, p, q, a);
            n2 = integral(f, n/2, p, q, a);
            if(fabs(n1-n2) < pow(10, -err)){
                printf("%.12lf\n", n1);
                break;
            }
            n *= 2;
        }
    }
    return 0;
}