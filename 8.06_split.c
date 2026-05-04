#include <stdio.h>

int main() {
    char sep;
    char s[501];

    scanf(" %c", &sep);
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == sep) {
            printf("\n");
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    return 0;
}
