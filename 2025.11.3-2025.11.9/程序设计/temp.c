#include <stdio.h>

int main() {
    int n;
    float x;
    scanf("%d %f", &n, &x);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if(j > 1) printf("%6.2f", x);
            else printf("%.2f", x);  
        }
        printf("\n");
    }
    
    return 0;
}