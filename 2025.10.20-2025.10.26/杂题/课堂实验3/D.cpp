#include <stdio.h>
int x1, y1, x2, y2, x, y;
int main() {
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x, &y);
    if (x >= x1 && x <= x2 && y >= y2 && y <= y1) printf("IN");
    else printf("OUT");
    return 0;
}