#include <stdio.h>

int contar_pares(int v[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) count++;
    }
    return count;
}

int contar_impares(int v[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 != 0) count++;
    }
    return count;
}

int encontrar_maior(int v[], int n) {
    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maior) maior = v[i];
    }
    return maior;
}

int encontrar_menor(int v[], int n) {
    int menor = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < menor) menor = v[i];
    }
    return menor;
}

double calcular_media(int v[], int n) {
    long long soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return (double)soma / n;
}

int contar_acima_media(int v[], int n, double media) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > media) count++;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int v[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int pares = contar_pares(v, n);
    int impares = contar_impares(v, n);
    int maior = encontrar_maior(v, n);
    int menor = encontrar_menor(v, n);
    double media = calcular_media(v, n);
    int acima = contar_acima_media(v, n, media);

    printf("Pares: %d | Impares: %d\n", pares, impares);
    printf("Maior: %d | Menor: %d\n", maior, menor);
    printf("Media: %.2f\n", media);
    printf("Acima da media: %d\n", acima);

    return 0;
}