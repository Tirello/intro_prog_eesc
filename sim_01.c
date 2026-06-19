#include <stdio.h>

int main() {
    int valor;
    
    if (scanf("%d", &valor) != 1) {
        return 1;
    }

    int denominacoes[] = {200, 100, 50, 10, 2, 1};
    int quantidade;

    for (int i = 0; i < 6; i++) {
        quantidade = valor / denominacoes[i];
        
        if (quantidade > 0) {
            printf("%d nota(s)/moeda(s) de R$%d\n", quantidade, denominacoes[i]);
        }
        
        valor = valor % denominacoes[i];
    }

    return 0;
}
