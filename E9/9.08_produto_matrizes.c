#include <stdio.h>

int main() {
    int la, ca, lb, cb;
    scanf("%d %d", &la, &ca);
    scanf("%d %d", &lb, &cb);

    int a[10][10], b[10][10];

    for (int i = 0; i < la; i++) {
        for (int j = 0; j < ca; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < lb; i++) {
        for (int j = 0; j < cb; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    if (ca != lb) {
        printf("Produto inexistente\n");
        return 0;
    }

    int c[10][10];

    for (int i = 0; i < la; i++) {
        for (int j = 0; j < cb; j++) {
            c[i][j] = 0;
            for (int k = 0; k < ca; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < la; i++) {
        for (int j = 0; j < cb; j++) {
            if (j > 0) printf(" ");
            printf("%d", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}