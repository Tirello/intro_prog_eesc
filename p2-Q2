#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_JOGADORES 100
#define TAM_NOME 105

typedef struct {
    char nome[TAM_NOME];
    char selecao[TAM_NOME];
    int ataque;
    int estamina;
    int defesa;
    double habilidade;
} Jogador;

Jogador jogadores[MAX_JOGADORES];
int total_jogadores = 0;

void normalizar_string(char str[]) {
    int i, j = 0;
    int espaco_anterior = 1;

    for (i = 0; str[i] != '\0'; i++) {
        char atual = toupper((unsigned char)str[i]);

        if (atual == ' ') {
            if (!espaco_anterior) {
                str[j++] = ' ';
                espaco_anterior = 1;
            }
        } else {
            str[j++] = atual;
            espaco_anterior = 0;
        }
    }

    if (j > 0 && str[j - 1] == ' ') {
        j--;
    }

    str[j] = '\0';
}

Jogador* buscar_jogador(char nome[], char selecao[]) {
    for (int i = 0; i < total_jogadores; i++) {
        if (strcmp(jogadores[i].nome, nome) == 0 && strcmp(jogadores[i].selecao, selecao) == 0) {
            return &jogadores[i];
        }
    }
    return NULL;
}

int main() {
    int N, Q;

    if (scanf("%d", &N) != 1) return 1;

    while (getchar() != '\n');

    for (int i = 0; i < N; i++) {
        fgets(jogadores[i].nome, TAM_NOME, stdin);
        jogadores[i].nome[strcspn(jogadores[i].nome, "\n")] = '\0';

        fgets(jogadores[i].selecao, TAM_NOME, stdin);
        jogadores[i].selecao[strcspn(jogadores[i].selecao, "\n")] = '\0';

        scanf("%d %d %d", &jogadores[i].ataque, &jogadores[i].estamina, &jogadores[i].defesa);

        while (getchar() != '\n');

        normalizar_string(jogadores[i].nome);
        normalizar_string(jogadores[i].selecao);

        int soma = jogadores[i].ataque + jogadores[i].estamina + jogadores[i].defesa;
        jogadores[i].habilidade = (double)soma / 3.0;

        total_jogadores++;
    }

    if (scanf("%d", &Q) != 1) return 1;

    while (getchar() != '\n');

    for (int i = 0; i < Q; i++) {
        char nome_consulta[TAM_NOME];
        char selecao_consulta[TAM_NOME];

        fgets(nome_consulta, TAM_NOME, stdin);
        nome_consulta[strcspn(nome_consulta, "\n")] = '\0';

        fgets(selecao_consulta, TAM_NOME, stdin);
        selecao_consulta[strcspn(selecao_consulta, "\n")] = '\0';

        normalizar_string(nome_consulta);
        normalizar_string(selecao_consulta);

        Jogador *j = buscar_jogador(nome_consulta, selecao_consulta);

        if (j != NULL) {
            printf("JOGADOR: %s\n", j->nome);
            printf("SELECAO: %s\n", j->selecao);
            printf("ATRIBUTOS: %d %d %d\n", j->ataque, j->estamina, j->defesa);
            printf("HABILIDADE: %.2f\n", j->habilidade);
        } else {

            printf("JOGADOR NAO ENCONTRADO\n");
        }


        if (i < Q - 1) { 
            printf("\n");
        }
    }

    return 0;
}
