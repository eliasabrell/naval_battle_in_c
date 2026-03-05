#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {

    // Matriz que representa o tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Vetores que representam os navios (cada posição vale 3)
    int navio_horizontal[TAM_NAVIO] = {3,3,3};
    int navio_vertical[TAM_NAVIO] = {3,3,3};

    // Coordenadas iniciais dos navios
    int linha_h = 2;
    int coluna_h = 4;

    int linha_v = 5;
    int coluna_v = 1;

    int i, j;

    // ---------------------------------------------------
    // Inicializando o tabuleiro com 0 (água)
    // ---------------------------------------------------
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // ---------------------------------------------------
    // Validação do navio horizontal
    // ---------------------------------------------------
    if(coluna_h + TAM_NAVIO <= TAM_TABULEIRO){

        int sobreposicao = 0;

        for(i = 0; i < TAM_NAVIO; i++){
            if(tabuleiro[linha_h][coluna_h + i] != 0){
                sobreposicao = 1;
            }
        }

        if(!sobreposicao){
            for(i = 0; i < TAM_NAVIO; i++){
                tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
            }
        } else {
            printf("Erro: Sobreposicao detectada no navio horizontal\n");
        }

    } else {
        printf("Erro: Navio horizontal fora do tabuleiro\n");
    }

    // ---------------------------------------------------
    // Validação do navio vertical
    // ---------------------------------------------------
    if(linha_v + TAM_NAVIO <= TAM_TABULEIRO){

        int sobreposicao = 0;

        for(i = 0; i < TAM_NAVIO; i++){
            if(tabuleiro[linha_v + i][coluna_v] != 0){
                sobreposicao = 1;
            }
        }

        if(!sobreposicao){
            for(i = 0; i < TAM_NAVIO; i++){
                tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
            }
        } else {
            printf("Erro: Sobreposicao detectada no navio vertical\n");
        }

    } else {
        printf("Erro: Navio vertical fora do tabuleiro\n");
    }

    // ---------------------------------------------------
    // Exibindo o tabuleiro
    // ---------------------------------------------------
    printf("\nTABULEIRO BATALHA NAVAL\n\n");

    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
