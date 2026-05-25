#include <stdio.h>
#include <math.h>
const double PI = 3.1415926;
double r, n;
int main() {
    scanf("%lf,%lf", &r, &n);
    printf("Area=%.2lf", n * r * r * sin(2 * PI / n) / 2);
    return 0;
}