#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_CODIGO 10

// Estrutura que representa uma carta de cidade
struct Carta {
    char codigo[TAM_CODIGO];
    char cidade[TAM_NOME];
    long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para cadastrar uma carta
struct Carta cadastrarCarta() {
    struct Carta c;

    printf("\n=== Cadastro de Carta ===\n");
    printf("Código da carta: ");
    scanf("%s", c.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", c.cidade);
    printf("População: ");
    scanf("%ld", &c.populacao);
    printf("Área (em km²): ");
    scanf("%f", &c.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &c.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &c.pontosTuristicos);

    return c;
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta c) {
    printf("\n--- Carta %s ---\n", c.codigo);
    printf("Cidade: %s\n", c.cidade);
    printf("População: %ld\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

// Função para comparar duas cartas
void compararCartas(struct Carta c1, struct Carta c2) {
    int opcao;
    float valor1 = 0, valor2 = 0;

    printf("\nAtributos disponíveis para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("Escolha o número do atributo: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            printf("\nComparando População...\n");
            break;
        case 2:
            valor1 = c1.area;
            valor2 = c2.area;
            printf("\nComparando Área...\n");
            break;
        case 3:
            valor1 = c1.pib;
            valor2 = c2.pib;
            printf("\nComparando PIB...\n");
            break;
        case 4:
            valor1 = c1.pontosTuristicos;
            valor2 = c2.pontosTuristicos;
            printf("\nComparando Pontos Turísticos...\n");
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    if (valor1 > valor2) {
        printf("\n🏆 Carta vencedora: %s (%s)\n", c1.cidade, c1.codigo);
    } else if (valor2 > valor1) {
        printf("\n🏆 Carta vencedora: %s (%s)\n", c2.cidade, c2.codigo);
    } else {
        printf("\n🤝 Empate!\n");
    }
}

// Função principal
int main() {
    struct Carta carta1, carta2;

    printf("=== Super Trunfo - Países (Nível Novato) ===\n");

    carta1 = cadastrarCarta();
    carta2 = cadastrarCarta();

    printf("\n--- Cartas Cadastradas ---\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    compararCartas(carta1, carta2);

    return 0;
}
