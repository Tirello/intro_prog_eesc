#include <stdio.h>
#include <math.h>

double soma(double v[], int n) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        s += v[i];
    }
    return s;
}

double quadrado(double x) {
    return x * x;
}

double media(double v[], int n) {
    return soma(v, n) / n;
}

double desvio(double v[], int n) {
    double m = media(v, n);
    double soma_quadrados = 0;
    for (int i = 0; i < n; i++) {
        soma_quadrados += quadrado(v[i] - m);
    }
    return sqrt(soma_quadrados / n);
}

int main() {
    int n;
    scanf("%d", &n);

    double v[1000];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v[i]);
    }

    printf("Soma: %.2f\n", soma(v, n));
    printf("Media: %.2f\n", media(v, n));
    printf("Desvio: %.2f\n", desvio(v, n));

    return 0;
}