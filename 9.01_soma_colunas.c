#include <stdio.h>

int main() {
    int matriz[4][5];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int soma[5] = {0};

    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 4; i++) {
            soma[j] += matriz[i][j];
        }
    }

    for (int j = 0; j < 5; j++) {
        if (j > 0) printf(" ");
        printf("%d", soma[j]);
    }
    printf("\n");

    return 0;
}
