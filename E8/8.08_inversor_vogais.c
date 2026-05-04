#include <stdio.h>
#include <string.h>

int eh_vogal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    char s[102];

    fgets(s, sizeof(s), stdin);

    int len = strlen(s);
    if (s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }

    int vogais = 0;
    for (int i = 0; i < len; i++) {
        if (eh_vogal(s[i])) {
            vogais++;
        }
    }

    int inicio = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            int fim = i - 1;
            while (inicio < fim) {
                char tmp = s[inicio];
                s[inicio] = s[fim];
                s[fim] = tmp;
                inicio++;
                fim--;
            }
            inicio = i + 1;
        }
    }

    printf("%s\n", s);
    printf("Vogais: %d\n", vogais);

    return 0;
}