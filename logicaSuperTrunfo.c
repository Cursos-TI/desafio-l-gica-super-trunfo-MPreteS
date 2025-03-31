#include <stdio.h>
#include <string.h>

/* Armazena as propriedades das cidades */
struct Cidade {
    char nome[50];
    char codigo[10];
    int populacao;
    float area;
    float pib;
    int turisticos;

};

int main () {
    /* DEclaração das variáveis*/
    struct Cidade cidadeA, cidadeB;
    char atributo[20];
    int vencedor;

/*Calculo da densidade populacional*/
float densidade_populacional1 = 
(float)cidadeA.populacao / cidadeA.area;

float densidade_populacional2 =
(float)cidadeA.populacao / cidadeB.area;

/*Calculo do pib per capita*/
float pib_per_capita1 = cidadeA.pib / cidadeA.populacao;
float pib_per_capita2 = cidadeB.pib / cidadeB.populacao;


    /*Solicitação dos dados das cidades*/
    printf("Digite o nome da cidade A:");
    scanf("%s", cidadeA.nome);
    printf("\nDigite o código da cidade A:");
    scanf("%s", cidadeA.codigo);
    printf("\nDigite a população da cidae A:");
    scanf("%d", &cidadeA.populacao);
    printf("\nDigite a área da cidade A:");
    scanf("%f", &cidadeA.area);
    printf("\nDigite o PIB da cidade A:");
    scanf("%f", &cidadeA.pib);
    printf("\nDigite quantos pontos turístircos na cidade A:");
    scanf("%d", &cidadeA.turisticos);

    printf("\nDigite o nome da cidade B: ");
    scanf("%s", cidadeB.nome);
    printf("\nDigite o código da cidade B: ");
    scanf("%s", cidadeB.codigo);
    printf("\nDigite a população da cidade B: ");
    scanf("%d", &cidadeB.populacao);
    printf("\nDigite a área da cidade B: ");
    scanf("%f", &cidadeB.area);
    printf("\nDigite o PIB da cidade B: ");
    scanf("%f", &cidadeB.pib);
    printf("\nDigite quantos pontos turísticos na cidade B:");
    scanf("%d", &cidadeB.turisticos);
    
    if (cidadeA.populacao > cidadeB.populacao) {
    printf("A população da carta 1 é maior, portanto Cidade 1 é a vencedora.\n");
    } else {
    printf("A população da carta 2 é maior, portanto Cidade 2 é a vencedora.\n");  
    }   

    
    return 0;
}