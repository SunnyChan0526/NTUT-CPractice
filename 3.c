#include <stdio.h>
int main()
{
    int m1h = 0, m2h = 0, x = 0, y = 0;
    float get = 0, lb = 0, tax = 0;
    scanf("%d", &m1h);
    scanf("%d", &m2h);
    scanf("%d", &x);
    scanf("%d", &y);
    lb = y*0.05;
    tax = (m1h + m2h)*x*0.08;
    get = (m1h + m2h)*x - lb - tax;

    printf("%.1f\n", get);
    printf("%.1f\n", lb);
    printf("%.1f", tax);
    return 0;
}