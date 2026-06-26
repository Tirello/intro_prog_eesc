#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_JOGADORES 100
#define MAX_SELECOES 100
#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    char selecao[MAX_NOME];
    double habilidade;
} Jogador;

typedef struct {
    char nome[MAX_NOME];
    double soma_habilidades;
    int qtd_jogadores;
} Selecao;

void normalizar_nome(char *dest, const char *orig) {
    int i = 0, j = 0;
    int em_espaco = 1;

    while (orig[i] != '\0') {
        if (isspace((unsigned char)orig[i])) {
            if (!em_espaco) {
                dest[j++] = ' ';
                em_espaco = 1;
            }
        } else {
            dest[j++] = toupper((unsigned char)orig[i]);
            em_espaco = 0;
        }
        i++;
    }

    if (j > 0 && dest[j - 1] == ' ') {
        j--;
    }
    
    dest[j] = '\0';
}

int obter_indice_selecao(Selecao selecoes[], int *total_selecoes, const char *nome_selecao) {
    for (int i = 0; i < *total_selecoes; i++) {
        if (strcmp(selecoes[i].nome, nome_selecao) == 0) {
            return i;
        }
    }
    strcpy(selecoes[*total_selecoes].nome, nome_selecao);
    selecoes[*total_selecoes].soma_habilidades = 0.0;
    selecoes[*total_selecoes].qtd_jogadores = 0;
    (*total_selecoes)++;
    return (*total_selecoes - 1);
}

int main() {
    int N, Q;
    Jogador jogadores[MAX_JOGADORES];
    Selecao selecoes[MAX_SELECOES];
    int total_selecoes = 0;

    if (scanf("%d", &N) != 1) return 1;

    for (int i = 0; i < N; i++) {
        char nome_temp[MAX_NOME], selecao_temp[MAX_NOME];
        int ataque, estamina, defense;

        scanf(" %[^\n]", nome_temp);
        scanf(" %[^\n]", selecao_temp);
        scanf("%d %d %d", &ataque, &estamina, &defense);

        normalizar_nome(jogadores[i].nome, nome_temp);
        normalizar_nome(jogadores[i].selecao, selecao_temp);

        jogadores[i].habilidade = (ataque + estamina + defense) / 3.0;

        int idx = obter_indice_selecao(selecoes, &total_selecoes, jogadores[i].selecao);
        selecoes[idx].soma_habilidades += jogadores[i].habilidade;
        selecoes[idx].qtd_jogadores++;
    }

    if (scanf("%d", &Q) != 1) return 1;

    for (int i = 0; i < Q; i++) {
        char sel1_temp[MAX_NOME], sel2_temp[MAX_NOME];
        char sel1_norm[MAX_NOME], sel2_norm[MAX_NOME];

        scanf(" %[^\n]", sel1_temp);
        scanf(" %[^\n]", sel2_temp);

        normalizar_nome(sel1_norm, sel1_temp);
        normalizar_nome(sel2_norm, sel2_temp);

        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < total_selecoes; j++) {
            if (strcmp(selecoes[j].nome, sel1_norm) == 0) idx1 = j;
            if (strcmp(selecoes[j].nome, sel2_norm) == 0) idx2 = j;
        }

        if (idx1 == -1 || idx2 == -1) {
            continue; 
        }

        double forca1 = selecoes[idx1].soma_habilidades / selecoes[idx1].qtd_jogadores;
        double forca2 = selecoes[idx2].soma_habilidades / selecoes[idx2].qtd_jogadores;

        printf("SELECAO 1: %s\n", selecoes[idx1].nome);
        printf("FORCA 1: %.2f\n", forca1);
        printf("SELECAO 2: %s\n", selecoes[idx2].nome);
        printf("FORCA 2: %.2f\n", forca2);

        if (forca1 > forca2) {
            printf("VENCEDOR: %s\n", selecoes[idx1].nome);
        } else if (forca2 > forca1) {
            printf("VENCEDOR: %s\n", selecoes[idx2].nome);
        } else {
            printf("EMPATE\n");
        }

        if (i < Q - 1) { 
            printf("\n");
        }
    }

    return 0;
}
