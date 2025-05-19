#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Navio vertical
    for (int i = 1; i <= 3; i++) {
        tabuleiro[i][2] = 3;
    }

    // Navio horizontal
    for (int j = 5; j <= 7; j++) {
        tabuleiro[4][j] = 3;
    }

    // Navio diagonal (principal)
    for (int i = 0; i < 3; i++) {
        tabuleiro[i + 6][i + 1] = 3;
    }

    // Navio diagonal (secundária)
    for (int i = 0; i < 3; i++) {
        tabuleiro[i + 6][8 - i] = 3;
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar habilidade
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemX, int origemY) {
    int offset = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int x = origemX + (i - offset);
                int y = origemY + (j - offset);

                if (x >= 0 && x < TAM && y >= 0 && y < TAM && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 1;  // 1 indica área de habilidade
                }
            }
        }
    }
}

// Função para construir a habilidade CONE
void construirCone(int matriz[TAM_HAB][TAM_HAB]) {
    int i, j;
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = 0;
        }
    }

    matriz[0][2] = 1;
    matriz[1][1] = 1; matriz[1][2] = 1; matriz[1][3] = 1;
    for (int j = 0; j < TAM_HAB; j++) {
        matriz[2][j] = 1;
    }
}

// Função para construir a habilidade CRUZ
void construirCruz(int matriz[TAM_HAB][TAM_HAB]) {
    int i, j;
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (i == 2 || j == 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para construir a habilidade OCTAEDRO (losango)
void construirOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    int i, j;
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = 0;
        }
    }

    matriz[0][2] = 1;
    matriz[1][1] = 1; matriz[1][2] = 1; matriz[1][3] = 1;
    matriz[2][2] = 1;
    matriz[3][2] = 1;
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 2, 2);      // Ponto central do cone
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // Ponto central da cruz
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Ponto central do octaedro

    exibirTabuleiro(tabuleiro);

    return 0;
}
