#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    int x[n], y[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    double total = 0.0;

    for (int i = 1; i < n; i++) {
        int dx = x[i] - x[i-1];
        int dy = y[i] - y[i-1];
        total += sqrt(dx*dx + dy*dy);
    }

    printf("%.4f\n", total);

    return 0;
}