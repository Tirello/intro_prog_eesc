#include <stdio.h>

int dentro(int i, int j) {
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

int main() {
    int tab[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    int captura_i[64], captura_j[64], n_cap = 0;
    int move_i[64], move_j[64], n_mov = 0;
    int bloq_i[64], bloq_j[64], n_bloq = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tab[i][j] != -1) continue;

            int pode_capturar = 0;
            int pode_mover = 0;

            int dj[2] = {-1, 1};
            for (int k = 0; k < 2; k++) {
                int ni = i - 1;
                int nj = j + dj[k];
                int ni2 = i - 2;
                int nj2 = j + 2 * dj[k];

                if (dentro(ni, nj) && dentro(ni2, nj2) &&
                    tab[ni][nj] == 1 && tab[ni2][nj2] == 0) {
                    pode_capturar = 1;
                }

                if (dentro(ni, nj) && tab[ni][nj] == 0) {
                    pode_mover = 1;
                }
            }

            if (pode_capturar) {
                captura_i[n_cap] = i;
                captura_j[n_cap] = j;
                n_cap++;
            } else if (pode_mover) {
                move_i[n_mov] = i;
                move_j[n_mov] = j;
                n_mov++;
            } else {
                bloq_i[n_bloq] = i;
                bloq_j[n_bloq] = j;
                n_bloq++;
            }
        }
    }

    if (n_cap == 0) {
        printf("None\n");
    } else {
        for (int k = 0; k < n_cap; k++) {
            if (k > 0) printf(" ");
            printf("(%d,%d)", captura_i[k], captura_j[k]);
        }
        printf("\n");
    }

    if (n_mov == 0) {
        printf("None\n");
    } else {
        for (int k = 0; k < n_mov; k++) {
            if (k > 0) printf(" ");
            printf("(%d,%d)", move_i[k], move_j[k]);
        }
        printf("\n");
    }

    if (n_bloq == 0) {
        printf("None\n");
    } else {
        for (int k = 0; k < n_bloq; k++) {
            if (k > 0) printf(" ");
            printf("(%d,%d)", bloq_i[k], bloq_j[k]);
        }
        printf("\n");
    }

    return 0;
}