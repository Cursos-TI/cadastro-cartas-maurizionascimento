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

    printf("\n== Cadastro de Carta ==\n");
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
    printf("\nCódigo: %s", c.codigo);
    printf("\nCidade: %s", c.cidade);
    printf("\nPopulação: %ld", c.populacao);
    printf("\nÁrea: %.2f km²", c.area);
    printf("\nPIB: %.2f bilhões", c.pib);
    printf("\nPontos turísticos: %d\n", c.pontosTuristicos);
}

// Função principal
int main() {
    struct Carta carta1, carta2;

    printf("=== SUPER TRUNFO - Países (Nível Novato) ===\n");

    // Cadastro das duas cartas
    carta1 = cadastrarCarta();
    carta2 = cadastrarCarta();

    // Cálculo dos novos atributos
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;
    float pibPerCapita1 = carta1.pib / carta1.populacao;
    float pibPerCapita2 = carta2.pib / carta2.populacao;

    // Exibição das cartas
    printf("\n=== Cartas Cadastradas ===\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Escolha do atributo fixo para comparação
    // Você pode mudar aqui: 1=População, 2=Área, 3=PIB, 4=Pontos, 5=Densidade, 6=PIB per capita
    int atributo = 1; // <-- altere o número conforme quiser comparar

    printf("\n=== Comparação de Cartas ===\n");

    if (atributo == 1) {
        printf("Comparando População...\n");
        if (carta1.populacao > carta2.populacao)
            printf("Carta vencedora: %s (%s)\n", carta1.cidade, carta1.codigo);
        else if (carta2.populacao > carta1.populacao)
            printf("Carta vencedora: %s (%s)\n", carta2.cidade, carta2.codigo);
        else
            printf("Empate!\n");
    } 
    else if (atributo == 2) {
        printf("Comparando Área...\n");
        if (carta1.area > carta2.area)
            printf("Carta vencedora: %s (%s)\n", carta1.cidade, carta1.codigo);
        else if (carta2.area > carta1.area)
            printf("Carta vencedora: %s (%s)\n", carta2.cidade, carta2.codigo);
        else
            printf("Empate!\n");
    } 
    else if (atributo == 3) {
        printf("Comparando PIB...\n");
        if (carta1.pib > carta2.pib)
            printf("Carta vencedora: %s (%s)\n", carta1.cidade, carta1.codigo);
        else if (carta2.pib > carta1.pib)
            printf("Carta vencedora: %s (%s)\n", carta2.cidade, carta2.codigo);
        else
            printf("Empate!\n");
    } 
    else if (atributo == 4) {
        printf("Comparando Pontos Turísticos...\n");
        if (carta1.pontosTuristicos > carta2.pontosTuristicos)
            printf("Carta vencedora: %s (%s)\n", carta1.cidade, carta1.codigo);
        else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
            printf("Carta vencedora: %s (%s)\n", carta2.cidade, carta2.codigo);
        else
            printf("Empate!\n");
    } 
    else if (atributo == 5) {
        printf("Comparando Densidade Populacional...\n");
        if (densidade1 < densidade2)
            printf("Carta vencedora: %s (%s)\n", carta1.cidade, carta1.codigo);
        else if (densidade2 < densidade1)
            printf("Carta vencedora: %s (%s)\n", carta2.cidade, carta2.codigo);
        else
            printf("Empate!\n");
    } 
    else if (atributo == 6) {
        printf("Comparando PIB per Capita...\n");
        if (pibPerCapita1 > pibPerCapita2)
            printf("Carta vencedora: %s (%s)\n", carta1.cidade, carta1.codigo);
        else if (pibPerCapita2 > pibPerCapita1)
            printf("Carta vencedora: %s (%s)\n", carta2.cidade, carta2.codigo);
        else
            printf("Empate!\n");
    } 
    else {
        printf("Atributo inválido.\n");
    }

printf("Novo commit/n");

    return 0;
}