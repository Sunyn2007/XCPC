#include <stdio.h>
char ch;
int main() {
    scanf("%c", &ch);
    if (ch >= 'A' && ch <= 'Z') printf("upper");
    else if (ch >= 'a' && ch <= 'z') printf("lower");
    else if (ch >= '0' && ch <= '9') printf("digit");
    else printf("others");
    return 0;
}