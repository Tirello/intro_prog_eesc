#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matriz[3][3];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int eh_pico = 1;

            if (i > 0 && matriz[i-1][j] >= matriz[i][j]) eh_pico = 0;
            if (i < n-1 && matriz[i+1][j] >= matriz[i][j]) eh_pico = 0;
            if (j > 0 && matriz[i][j-1] >= matriz[i][j]) eh_pico = 0;
            if (j < n-1 && matriz[i][j+1] >= matriz[i][j]) eh_pico = 0;

            if (eh_pico) {
                printf("Pico encontrado em [%d][%d]: %d\n", i, j, matriz[i][j]);
            }
        }
    }

    return 0;
}