#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 50

typedef struct {
    char nome[50];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

Carta baralho[MAX_CARTAS];
int totalCartas = 0;

void cadastrarCarta() {
    if (totalCartas >= MAX_CARTAS) {
        printf("Limite de cartas atingido.\n");
        return;
    }

    printf("Nome da carta: ");
    scanf(" %[^\n]", baralho[totalCartas].nome);

    printf("Força: ");
    scanf("%d", &baralho[totalCartas].forca);

    printf("Velocidade: ");
    scanf("%d", &baralho[totalCartas].velocidade);

    printf("Inteligência: ");
    scanf("%d", &baralho[totalCartas].inteligencia);

    totalCartas++;
    printf("Carta cadastrada com sucesso!\n");
}

void listarCartas() {
    printf("\nCartas cadastradas:\n");
    for (int i = 0; i < totalCartas; i++) {
        printf("%d - %s (Força: %d, Velocidade: %d, Inteligência: %d)\n",
               i + 1, baralho[i].nome, baralho[i].forca,
               baralho[i].velocidade, baralho[i].inteligencia);
    }
}

void simularRodada() {
    int i1, i2;
    if (totalCartas < 2) {
        printf("Cadastre pelo menos 2 cartas para simular.\n");
        return;
    }

    listarCartas();
    printf("Escolha o número da primeira carta: ");
    scanf("%d", &i1);
    printf("Escolha o número da segunda carta: ");
    scanf("%d", &i2);

    if (i1 < 1 || i2 < 1 || i1 > totalCartas || i2 > totalCartas || i1 == i2) {
        printf("Cartas inválidas.\n");
        return;
    }

    Carta c1 = baralho[i1 - 1];
    Carta c2 = baralho[i2 - 1];

    int pontosC1 = 0, pontosC2 = 0;

    if (c1.forca > c2.forca) pontosC1++; else if (c2.forca > c1.forca) pontosC2++;
    if (c1.velocidade > c2.velocidade) pontosC1++; else if (c2.velocidade > c1.velocidade) pontosC2++;
    if (c1.inteligencia > c2.inteligencia) pontosC1++; else if (c2.inteligencia > c1.inteligencia) pontosC2++;

    printf("\nResultado:\n");
    printf("%s %d x %d %s\n", c1.nome, pontosC1, pontosC2, c2.nome);

    if (pontosC1 > pontosC2)
        printf("Vencedor: %s\n", c1.nome);
    else if (pontosC2 > pontosC1)
        printf("Vencedor: %s\n", c2.nome);
    else
        printf("Empate!\n");
}

int main() {
    int opcao;
    do {
        printf("\n--- Super Trunfo ---\n");
        printf("1. Cadastrar carta\n");
        printf("2. Listar cartas\n");
        printf("3. Simular rodada\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarCarta(); break;
            case 2: listarCartas(); break;
            case 3: simularRodada(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
