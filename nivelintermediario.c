#include <stdio.h>

// Tamanho fixo do tabuleiro e dos navios
#define TAM 10
#define TAMANHO_NAVIO 3

// Função para verificar se um navio pode ser colocado sem ultrapassar os limites e sem sobreposição
int pode_colocar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao_linha, int direcao_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * direcao_linha;
        int c = coluna + i * direcao_coluna;

        // Verifica se está dentro dos limites
        if (l < 0 || l >= TAM || c < 0 || c >= TAM)
            return 0;

        // Verifica se a posição já está ocupada
        if (tabuleiro[l][c] != 0)
            return 0;
    }
    return 1;
}

// Função para colocar o navio no tabuleiro
void colocar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao_linha, int direcao_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * direcao_linha;
        int c = coluna + i * direcao_coluna;
        tabuleiro[l][c] = 3; // Marca parte do navio
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // NAVIO 1: Horizontal (linha 0, colunas 0 a 2)
    if (pode_colocar(tabuleiro, 0, 0, 0, 1)) {
        colocar_navio(tabuleiro, 0, 0, 0, 1);
    }

    // NAVIO 2: Vertical (coluna 5, linhas 2 a 4)
    if (pode_colocar(tabuleiro, 2, 5, 1, 0)) {
        colocar_navio(tabuleiro, 2, 5, 1, 0);
    }

    // NAVIO 3: Diagonal principal (linha=6, coluna=0 -> [6][0], [7][1], [8][2])
    if (pode_colocar(tabuleiro, 6, 0, 1, 1)) {
        colocar_navio(tabuleiro, 6, 0, 1, 1);
    }

    // NAVIO 4: Diagonal secundária (linha=0, coluna=9 -> [0][9], [1][8], [2][7])
    if (pode_colocar(tabuleiro, 0, 9, 1, -1)) {
        colocar_navio(tabuleiro, 0, 9, 1, -1);
    }

    // Exibe o tabuleiro formatado
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
