#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct {
    char nome [50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
} Carta;

void calcularDensidade(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade_demografica = carta->populacao / carta->area;
    } else {
        carta->densidade_demografica = 0;
    }
}

void exibirMenuAtributos(int atributo_excluido) {
    printf("\nAtributos Disponíveis\n");
    if (atributo_excluido != 1) printf("1. População\n");
    if (atributo_excluido != 2) printf("2. Área\n");
    if (atributo_excluido != 3) printf("3. PIB\n");
    if (atributo_excluido !=4) printf("4. Pontos Turísticos\n");
    if (atributo_excluido !=5) printf("5. Densidade Demográfica\n");
    printf("0. Voltar\n");
}

int compararAtributo(Carta *carta1, Carta carta2, Carta carta3 int atributo) {
    float valor1, valor2;
    char *nome_atributo;
    int maior_vence = 1;

    switch (atributo)
    {
    case 1:
    valor1 = carta1->populacao;
    valor2 = carta2->populacao;
    nome_atributo = "População";
        break;
    
    case 2:
    valor1 = carta1->area;
    valor2 = carta2->area;
    nome_atributo = "Área";
    break;

    case 3:
    valor1 = carta1->pib;
    valor2 = carta2->pib;
    nome_atributo = "PIB";
    break;

    case 4:
    valor1 = carta1->pontos_turisticos;
    valor2 = carta2->pontos_turisticos;
    nome_atributo = "Pontos Turísticos";
    break;

    case 5:
    valor1 = carta1->densidade_demografica;
    valor2 = carta2->densidade_demografica;
    nome_atributo = "Densidade Demográfica";
    maior_vence = 0;
    break;

    default:
    printf("Opção Inválida!\n");
    break;
    }
    if (maior_vence){
        if (valor1 > valor2)  return 1;
        if (valor2 > valor1)  return -1;
        } else {
        if (valor1 < valor2)  return 1;
        if (valor2 < valor1)  return -1;}
    }
    return 0;
    }
    void exibirCarta(Carta carta) {
        printf("\nAtributos Disponíveis\n");
        printf("Nome: %s\n", carta.nome);
        printf("População: %d\n", carta.populacao);
        printf("Área: %.2f\n", carta.area);
        printf("PIB: %.2f\n", carta.pib);
        printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
        printf("Densidade Demográfica: %.2f\n", carta.densidade_demografica);
}
void listarCartas(Carta cartas[], int num_cartas) {
    printf("\nCartas Disponíveis:\n");
    for (int i = 0; i < num_cartas; i++) {
        printf("%d. %s\n", i + 1, cartas[i].nome);
    }
}
int main (){
    srand(time(NULL));
    Carta baralho [3] = {
        {"São Paulo", 46600000, 248219.0 2500.0, 98, 0},
        {"Espíritpo Santo", 4100000, 46095, 170.0, 45, 0},
        {"Rio de Janeirp", 17400000, 43750.0, 779.0, 100, 0}
        };
        
        for (int = 0; i < 3; i++) {
            calcularDensidade(&baralho[i]);
        }
        int escolha;
        
        do {}
    }
}