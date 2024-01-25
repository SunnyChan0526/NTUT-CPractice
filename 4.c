#include <stdio.h>
#define PI 3.14159

int main()
{
    float a, ans1, ans2;
    scanf("%f", &a);
    ans1 = a*a*PI;
    ans2 = 2*a*PI;
    printf("%.3f\n", ans1);
    printf("%.3f", ans2);
    return 0;
}