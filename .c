#include <stdio.h>

typedef struct {
    char estado;
    int cidade_num;
    char codigo[4]; // Ex: A01, B02
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    // Nível Aventureiro
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// =====================================================
// Função para preencher e exibir uma carta (Novato)
void cadastroNovato(Carta *carta) {
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);
    printf("Digite o número da cidade (1-4): ");
    scanf("%d", &carta->cidade_num);
    // Código da carta
    sprintf(carta->codigo, "%c%02d", carta->estado, carta->cidade_num);

    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB: ");
    scanf("%f", &carta->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    printf("\n=== Dados da Carta %s ===\n", carta->codigo);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f\n", carta->pib);
    printf("Pontos turísticos: %d\n", carta->pontos_turisticos);
}

// =====================================================
// Função para exibir carta com atributos calculados (Aventureiro)
void exibirAventureiro(Carta *carta) {
    // Cálculo de densidade populacional e PIB per capita
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;

    printf("\n=== Dados da Carta %s ===\n", carta->codigo);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f\n", carta->pib);
    printf("Pontos turísticos: %d\n", carta->pontos_turisticos);
    printf("Densidade populacional: %.2f hab/km²\n", carta->densidade_populacional);
    printf("PIB per capita: %.2f\n", carta->pib_per_capita);
}

// =====================================================
// MAIN
// =====================================================
int main() {
    Carta carta1, carta2;

    printf("=== Cadastro das Cartas - Nível Novato ===\n");
    cadastroNovato(&carta1);
    cadastroNovato(&carta2);

    printf("\n=== Cadastro das Cartas - Nível Aventureiro ===\n");
    exibirAventureiro(&carta1);
    exibirAventureiro(&carta2);

    return 0;
}
