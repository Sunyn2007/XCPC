#include <stdio.h>
int y, m, d;
int main() {
    scanf("%d-%d-%d", &y, &m, &d);
    if (y % m == 3 && m % d == 3) printf("YES");
    else printf("NO");
    return 0;
}