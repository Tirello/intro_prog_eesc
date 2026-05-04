#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int matriz[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}