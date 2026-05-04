#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int v1[n], v2[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &v1[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &v2[i]);
    }

    int iguais = 1;

    for (int i = 0; i < n; i++) {
        int encontrou = 0;
        for (int j = 0; j < n; j++) {
            if (v1[i] == v2[j]) {
                encontrou = 1;
                break;
            }
        }
        if (!encontrou) {
            iguais = 0;
            break;
        }
    }

    printf("%d\n", iguais);

    return 0;
}