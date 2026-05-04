#include <stdio.h>

int main() {
    int matriz[4][5];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int a, b;
    scanf("%d %d", &a, &b);

    int contador = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] >= a && matriz[i][j] <= b) {
                contador++;
            }
        }
    }

    printf("%d\n", contador);

    return 0;
}