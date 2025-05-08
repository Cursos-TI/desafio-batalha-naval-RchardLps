#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se o navio pode ser posicionado (1 = pode, 0 = não pode)
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int vertical) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (vertical ? i : 0);
        int c = coluna + (vertical ? 0 : i);

        // Verifica se está fora dos limites ou se a posição já está ocupada
        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != AGUA) {
            return 0; // Não pode posicionar
        }
    }
    return 1; // Pode posicionar
}

// Posiciona o navio na matriz
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int vertical) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (vertical ? i : 0);
        int c = coluna + (vertical ? 0 : i);
        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 4;
    int linhaVertical = 5, colunaVertical = 6;

    // Tenta posicionar navio horizontal
    if (podePosicionar(tabuleiro, linhaHorizontal, colunaHorizontal, 0)) {
        posicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 0);
    } else {
        printf("Erro: navio horizontal fora dos limites ou em posição ocupada.\n");
        return 1;
    }

    // Tenta posicionar navio vertical
    if (podePosicionar(tabuleiro, linhaVertical, colunaVertical, 1)) {
        posicionarNavio(tabuleiro, linhaVertical, colunaVertical, 1);
    } else {
        printf("Erro: navio vertical fora dos limites ou em posição ocupada.\n");
        return 1;
    }

    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}

//UTILIZEI AJUDA POIS TIVE DIFICULDADES PARA REALIZAR O DESAFIO