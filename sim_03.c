#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SELECOES 100
#define TAM_NOME 50
#define TAM_ATRIBUTO 30
#define TAM_ARQ 100

// Estrutura para armazenar os dados de cada seleção
typedef struct {
    char nome[TAM_NOME];
    int pontos;
    int gols_marcados;
    int gols_sofridos;
} Selecao;

// Função para buscar uma seleção pelo nome
int buscarSelecao(Selecao selecoes[], int totalSelecoes, char nome[]) {
    for (int i = 0; i < totalSelecoes; i++) {
        if (strcmp(selecoes[i].nome, nome) == 0) {
            return i; // Retorna a posição caso encontre
        }
    }
    return -1; // Retorna -1 se não existir
}

int main() {
    Selecao selecoes[MAX_SELECOES];
    int totalSelecoes = 0;
    int Q;

    if (scanf("%d", &Q) != 1) return 0;

    for (int i = 0; i < Q; i++) {
        char operacao[20];
        scanf("%s", operacao);

        if (strcmp(operacao, "load") == 0) {
            char nome_arquivo[TAM_ARQ];
            scanf("%s", nome_arquivo);

            FILE *file = fopen(nome_arquivo, "r");
            if (file == NULL) {
                printf("Arquivo %s Indexistente\n", nome_arquivo);
            } else {
                printf("Arquivo %s Carregado\n", nome_arquivo);
                
                int N;
                fscanf(file, "%d", &N);
                
                for (int j = 0; j < N; j++) {
                    char nome_sel[TAM_NOME];
                    int pt, gm, gs;
                    fscanf(file, "%s %d %d %d", nome_sel, &pt, &gm, &gs);

                    // Verificar se a seleção já existe para atualizar
                    int idx = buscarSelecao(selecoes, totalSelecoes, nome_sel);
                    if (idx != -1) {
                        selecoes[idx].pontos = pt;
                        selecoes[idx].gols_marcados = gm;
                        selecoes[idx].gols_sofridos = gs;
                    } else {
                        // Adicionar nova seleção
                        if (totalSelecoes < MAX_SELECOES) {
                            strcpy(selecoes[totalSelecoes].nome, nome_sel);
                            selecoes[totalSelecoes].pontos = pt;
                            selecoes[totalSelecoes].gols_marcados = gm;
                            selecoes[totalSelecoes].gols_sofridos = gs;
                            totalSelecoes++;
                        }
                    }
                }
                fclose(file);
            }
        } 
        else if (strcmp(operacao, "consulta") == 0) {
            char nome_sel[TAM_NOME];
            char atributo[TAM_ATRIBUTO];
            scanf("%s %s", nome_sel, atributo);

            int idx = buscarSelecao(selecoes, totalSelecoes, nome_sel);
            
            if (idx == -1) {
                printf("Consulta Invalida\n");
            } else {
                if (strcmp(atributo, "pontos") == 0) {
                    printf("%d\n", selecoes[idx].pontos);
                } else if (strcmp(atributo, "gols_marcados") == 0) {
                    printf("%d\n", selecoes[idx].gols_marcados);
                } else if (strcmp(atributo, "gols_sofridos") == 0) {
                    printf("%d\n", selecoes[idx].gols_sofridos);
                } else if (strcmp(atributo, "saldo") == 0) {
                    int saldo = selecoes[idx].gols_marcados - selecoes[idx].gols_sofridos;
                    printf("%d\n", saldo);
                } else {
                    printf("Consulta Invalida\n"); // Atributo inválido
                }
            }
        }
    }

    return 0;
}
