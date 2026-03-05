#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5  // Tamanho das matrizes de habilidade (exemplo: 5x5)

void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
  for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" 0 "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf(" X "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf(" * "); // Área de efeito
            }
        }
        printf("\n");
    }
}

// Função para gerar a matriz de habilidade em formato de Cone
void gerarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j <= i; j++) {
            habilidade[i][j] = 1; // Preenche o cone com 1 (área afetada)
        }
    }
}

// Função para gerar a matriz de habilidade em formato de Cruz
void gerarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        habilidade[origem_linha][i] = 1; // Linha da cruz
        habilidade[i][origem_coluna] = 1; // Coluna da cruz
    }
}

// Função para gerar a matriz de habilidade em formato de Octaedro
void gerarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - origem_linha) + abs(j - origem_coluna) < TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1; // Preenche a área afetada do octaedro
            }
        }
    }
}

// Função para aplicar a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    // Aplica a habilidade no tabuleiro, ajustando as coordenadas para não ultrapassar os limites
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha_tab = origem_linha + i - TAM_HABILIDADE / 2;
            int coluna_tab = origem_coluna + j - TAM_HABILIDADE / 2;

            if (linha_tab >= 0 && linha_tab < TAM_TABULEIRO && coluna_tab >= 0 && coluna_tab < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linha_tab][coluna_tab] = 5; // Marca a área de efeito com 5
                }
            }
        }
    }
}

// Função para posicionar os navios no tabuleiro
void posicionarNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Posicionamento de um navio horizontal
    int linha_h = 2, coluna_h = 4;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3; // Marca a posição do navio
    }

    // Posicionamento de um navio vertical
    int linha_v = 5, coluna_v = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = 3; // Marca a posição do navio
    }

    // Posicionamento de um navio diagonal crescente
    int linha_dc = 0, coluna_dc = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_dc + i][coluna_dc + i] = 3; // Marca a posição do navio
    }

    // Posicionamento de um navio diagonal decrescente
    int linha_dd = 0, coluna_dd = 9;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_dd + i][coluna_dd - i] = 3; // Marca a posição do navio
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidadeCone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int habilidadeCruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int habilidadeOctaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios no tabuleiro
    posicionarNavios(tabuleiro);

    // Gera as habilidades
    gerarCone(habilidadeCone, TAM_HABILIDADE / 2, TAM_HABILIDADE / 2);
    gerarCruz(habilidadeCruz, TAM_HABILIDADE / 2, TAM_HABILIDADE / 2);
    gerarOctaedro(habilidadeOctaedro, TAM_HABILIDADE / 2, TAM_HABILIDADE / 2);

    // Aplica as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, 4, 4); // Aplica habilidade de cone no centro
    aplicarHabilidade(tabuleiro, habilidadeCruz, 6, 6); // Aplica habilidade de cruz
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 2, 2); // Aplica habilidade de octaedro

    // Exibe o tabuleiro final
    printf("Tabuleiro Final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
