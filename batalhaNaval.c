#include <stdio.h>

#include <stdio.h>

int main() {
    // Letras das colunas (A até J)
    char coluna[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // 1. Criando e inicializando o tabuleiro com 0 (água)
    int tabuleiro[10][10] = {0};

    // 2. Criando os navios com valor 3 representando navio
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // 3. Coordenadas iniciais dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 1;

    // 4. Verificando se os navios cabem no tabuleiro
    if (coluna_horizontal + 3 <= 10 && linha_vertical + 3 <= 10) {

        // Verificando sobreposição
        int sobreposicao = 0;

        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
                sobreposicao = 1;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                sobreposicao = 1;
            }
        }

        if (sobreposicao) {
            printf("Erro: Sobreposição de navios detectada.\n");
            return 1;
        }

        // Posicionando navios
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }

        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
        }

    } else {
        printf("Erro: Navio fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibindo o tabuleiro com letras nas colunas e números nas linhas
    printf("   "); // Espaço para alinhar o canto superior esquerdo
    for (int i = 0; i < 10; i++) {
        printf(" %c", coluna[i]); // Letras das colunas
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf(" %d ", i); // Número da linha na esquerda
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]); // Valores da matriz
        }
        printf("\n");
    }

    return 0;
}
