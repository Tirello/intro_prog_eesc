#include <stdio.h>

int main() {
    int matriz[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int j = 0; j < 5; j++) {
        int tmp = matriz[2][j];
        matriz[2][j] = matriz[j][2];
        matriz[j][2] = tmp;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j > 0) printf(" ");
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
