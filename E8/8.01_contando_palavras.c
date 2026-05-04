#include <stdio.h>
#include <ctype.h>

int main() {
    char s[10001];
    fgets(s, sizeof(s), stdin);

    int contador = 0;
    int dentro_palavra = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha((unsigned char)s[i])) {
            if (!dentro_palavra) {
                contador++;
                dentro_palavra = 1;
            }
        } else {
            dentro_palavra = 0;
        }
    }

    printf("%d\n", contador);

    return 0;
}

