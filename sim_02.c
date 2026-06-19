#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de cada seleção
typedef struct {
    char nome[50];
    int pontos;
    int gols_marcados;
    int gols_sofridos;
    int saldo;
} Selecao;

int main() {
    int N, Q;

    // Lê a quantidade de seleções
    if (scanf("%d", &N) != 1) return 0;

    Selecao selecoes[100];

    // Lê os dados de cada seleção
    for (int i = 0; i < N; i++) {
        scanf("%s %d %d %d", selecoes[i].nome, 
                            &selecoes[i].pontos, 
                            &selecoes[i].gols_marcados, 
                            &selecoes[i].gols_sofridos);
        
        // Calcula o saldo de gols antecipadamente
        selecoes[i].saldo = selecoes[i].gols_marcados - selecoes[i].gols_sofridos;
    }

    // Lê a quantidade de consultas
    scanf("%d", &Q);

    // Processa cada consulta
    for (int i = 0; i < Q; i++) {
        char nome_consulta[50];
        char atributo[30];
        scanf("%s %s", nome_consulta, atributo);

        // Busca a seleção correspondente na lista
        for (int j = 0; j < N; j++) {
            if (strcmp(selecoes[j].nome, nome_consulta) == 0) {
                // Imprime o valor do atributo solicitado
                if (strcmp(atributo, "pontos") == 0) {
                    printf("%d\n", selecoes[j].pontos);
                } else if (strcmp(atributo, "gols_marcados") == 0) {
                    printf("%d\n", selecoes[j].gols_marcados);
                } else if (strcmp(atributo, "gols_sofridos") == 0) {
                    printf("%d\n", selecoes[j].gols_sofridos);
                } else if (strcmp(atributo, "saldo") == 0) {
                    printf("%d\n", selecoes[j].saldo);
                }
                break; // Encerra a busca para esta consulta
            }
        }
    }

    return 0;
}
