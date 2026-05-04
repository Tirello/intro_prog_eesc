#include <stdio.h>

int main() {
    char a[1001], b[1001];

    scanf("%s", a);
    scanf("%s", b);

    int la = 0, lb = 0;
    while (a[la] != '\0') la++;
    while (b[lb] != '\0') lb++;

    int encontrou = 0;

    for (int i = 0; i <= la - lb; i++) {
        int igual = 1;
        for (int j = 0; j < lb; j++) {
            if (a[i + j] != b[j]) {
                igual = 0;
                break;
            }
        }
        if (igual) {
            encontrou = 1;
            break;
        }
    }

    printf("%d\n", encontrou);

    return 0;
}