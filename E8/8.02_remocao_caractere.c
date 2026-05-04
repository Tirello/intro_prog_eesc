#include <stdio.h>

int main() {
    char s[1002];
    char c;

    scanf("%s", s);
    scanf(" %c", &c);

    int imprimiu = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            printf("%c", s[i]);
            imprimiu = 1;
        }
    }

    if (imprimiu) {
        printf("\n");
    }

    return 0;
}