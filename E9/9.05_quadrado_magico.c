#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matriz[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int soma_referencia = 0;
    for (int j = 0; j < n; j++) {
        soma_referencia += matriz[0][j];
    }

    int magico = 1;

    for (int i = 1; i < n && magico; i++) {
        int soma = 0;
        for (int j = 0; j < n; j++) {
            soma += matriz[i][j];
        }
        if (soma != soma_referencia) magico = 0;
    }

    for (int j = 0; j < n && magico; j++) {
        int soma = 0;
        for (int i = 0; i < n; i++) {
            soma += matriz[i][j];
        }
        if (soma != soma_referencia) magico = 0;
    }

    if (magico) {
        int soma_diag = 0;
        for (int i = 0; i < n; i++) {
            soma_diag += matriz[i][i];
        }
        if (soma_diag != soma_referencia) magico = 0;
    }

    if (magico) {
        int soma_sec = 0;
        for (int i = 0; i < n; i++) {
            soma_sec += matriz[i][n - 1 - i];
        }
        if (soma_sec != soma_referencia) magico = 0;
    }

    if (magico) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

    return 0;
}