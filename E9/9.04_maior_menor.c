#include <stdio.h>

int main() {
    int matriz[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int maior = matriz[0][0];
    int linha_maior = 0, col_maior = 0;
    int menor = matriz[0][0];
    int linha_menor = 0, col_menor = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                linha_maior = i;
                col_maior = j;
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
                linha_menor = i;
                col_menor = j;
            }
        }
    }

    printf("%d %d %d\n", maior, linha_maior, col_maior);
    printf("%d %d %d\n", menor, linha_menor, col_menor);

    return 0;
}