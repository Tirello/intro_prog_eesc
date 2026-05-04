#include <stdio.h>

int soma_divisores(int k) {
    int soma = 0;
    for (int i = 1; i < k; i++) {
        if (k % i == 0) soma += i;
    }
    return soma;
}

int classifica(char t, int n) {
    int soma = soma_divisores(n);

    if (t == '<') return soma < n;
    if (t == '=') return soma == n;
    if (t == '>') return soma > n;

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int defeituosos = 0, perfeitos = 0, abundantes = 0;

    for (int k = 1; k <= n; k++) {
        if (classifica('<', k)) defeituosos++;
        if (classifica('=', k)) perfeitos++;
        if (classifica('>', k)) abundantes++;
    }

    printf("%d\n", defeituosos);
    printf("%d\n", perfeitos);
    printf("%d\n", abundantes);

    return 0;
}
