#include <stdio.h>
#include <ctype.h>

int main() {
    char s[1001];

    scanf("%s", s);

    int len = 0;
    while (s[len] != '\0') len++;

    int palindromo = 1;

    for (int i = 0; i < len / 2; i++) {
        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[len - 1 - i])) {
            palindromo = 0;
            break;
        }
    }

    if (palindromo) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

    return 0;
}