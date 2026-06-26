#include <stdio.h>
#include <string.h>
#include <ctype.h>

void normalizar_nome(char nome[]) {
    int i = 0, j = 0;
    int espaco = 0;

    while (nome[i] != '\0') {
        char c = nome[i];

        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }

        if ((c >= 'A' && c <= 'Z') || c == ' ') {
            if (c == ' ') {
                if (!espaco) {
                    nome[j++] = c;
                    espaco = 1;
                }
            } else {
                nome[j++] = c;
                espaco = 0;
            }
        }
        i++;
    }

    nome[j] = '\0';

    if (j > 0 && nome[j - 1] == ' ') {
        nome[j - 1] = '\0';
    }

    if (nome[0] == ' ') {
        for (i = 0; nome[i + 1] != '\0'; i++) {
            nome[i] = nome[i + 1];
        }
        nome[i] = '\0';
    }
}

int main() {
    int n, i;

    if (scanf("%d", &n) != 1) return 0;

    while (getchar() != '\n'); 

    for (i = 0; i < n; i++) {
        char nome[102];

        fgets(nome, sizeof(nome), stdin);

        nome[strcspn(nome, "\r\n")] = '\0';

        normalizar_nome(nome);

        printf("%s\n", nome);
    }

    return 0;
}
