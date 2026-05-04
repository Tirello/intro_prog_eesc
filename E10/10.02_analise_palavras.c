#include <stdio.h>
#include <string.h>

int eh_palindromo(char palavra[]) {
    int len = strlen(palavra);
    for (int i = 0; i < len / 2; i++) {
        if (palavra[i] != palavra[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int eh_vogal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int contar_vogais(char palavra[]) {
    int count = 0;
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (eh_vogal(palavra[i])) count++;
    }
    return count;
}

int contar_consoantes(char palavra[]) {
    int count = 0;
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (!eh_vogal(palavra[i])) count++;
    }
    return count;
}

void para_maiusculas(char palavra[], char resultado[]) {
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] >= 'a' && palavra[i] <= 'z') {
            resultado[i] = palavra[i] - 32;
        } else {
            resultado[i] = palavra[i];
        }
    }
    resultado[strlen(palavra)] = '\0';
}

void inverter(char palavra[], char invertida[]) {
    int len = strlen(palavra);
    for (int i = 0; i < len; i++) {
        invertida[i] = palavra[len - 1 - i];
    }
    invertida[len] = '\0';
}

int main() {
    char palavra[101];
    char maiuscula[101];
    char invertida[101];

    scanf("%s", palavra);

    if (eh_palindromo(palavra)) {
        printf("Palindromo: SIM\n");
    } else {
        printf("Palindromo: NAO\n");
    }

    printf("Vogais: %d | Consoantes: %d\n", contar_vogais(palavra), contar_consoantes(palavra));

    para_maiusculas(palavra, maiuscula);
    printf("Maiuscula: %s\n", maiuscula);

    inverter(palavra, invertida);
    printf("Invertida: %s\n", invertida);

    return 0;
}
