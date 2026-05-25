#include <stdio.h>
char ch;
int main() {
    scanf("%c", &ch);
    ch += 4;
    if (ch > 'Z') ch -= 26;
    printf("%c", ch);
}