#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
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

void exibirMenuAtributos() {
    printf("\nAtributos disponíveis:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade demográfica\n");
    printf("0. Voltar\n");
}

Carta* compararCartas(Carta *carta1, Carta *carta2, int atributo) {
    float valor1, valor2;
    char *nome_atributo;
    int maior_valor_vence = 1;

    switch(atributo) {
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
            maior_valor_vence = 0;
            break;
        
        default:
            printf("Opção inválida\n");
            return NULL;
    }

    printf("\nComparando %s vs %s por %s\n", carta1->nome, carta2->nome, nome_atributo);
    printf("%s: %.2f\n", carta1->nome, valor1);
    printf("%s: %.2f\n", carta2->nome, valor2);

    if (valor1 == valor2) {
        printf("Empate!\n");
        return NULL;
    } else if ((maior_valor_vence && valor1 > valor2) || (!maior_valor_vence && valor1 < valor2)) {
        return carta1;
    } else {
        return carta2;
    }
}

void listarCartas(Carta cartas[], int num_cartas) {
    printf("\nCartas disponíveis:\n"); 
    for (int i = 0; i < num_cartas; i++) { 
        printf("%d. %s\n", i+1, cartas[i].nome);
    }
}

int jogarPartida(Carta cartas[], int num_cartas) {
    int escolha;
    Carta *cartaJogador, *cartaPC;

    listarCartas(cartas, num_cartas);
    printf("Escolha sua carta (1-%d, ou 0 para sair): ", num_cartas);
    scanf("%d", &escolha);
    
    if (escolha == 0) return 0;
    if (escolha < 1 || escolha > num_cartas) {
        printf("Opção inválida!\n");
        return 1;
    }
    
    cartaJogador = &cartas[escolha-1];
    
    do {
        cartaPC = &cartas[rand() % num_cartas];
    } while (cartaPC == cartaJogador);
    
    printf("\nSua carta: %s\n", cartaJogador->nome);
    printf("Carta do computador: %s\n", cartaPC->nome);

    exibirMenuAtributos();
    printf("Escolha o atributo para comparar: ");
    scanf("%d", &escolha);
    if (escolha == 0) return 1;

    Carta *vencedor = compararCartas(cartaJogador, cartaPC, escolha);

    if (vencedor) {
        printf("\n%s venceu! ", vencedor->nome);
        if (vencedor == cartaPC) {
            printf("O computador ganhou esta rodada!\n");
        } else {
            printf("Você ganhou esta rodada!\n");
        }
    } else {
        printf("Empate nesta rodada!\n");
    }
    
    return 1;
}

int main() {
    srand(time(0));
    
    Carta cartas[] = {
        {"São Paulo", 46600000, 248219.0, 2500.0, 98},
        {"Espírito Santo", 4100000, 46095.0, 170.0, 45},
        {"Rio de Janeiro", 17400000, 43750.0, 779.0, 100},
    };
    
    int num_cartas = sizeof(cartas) / sizeof(cartas[0]);

    for (int i = 0; i < num_cartas; i++) {
        calcularDensidade(&cartas[i]);
    }
    
    char jogar_novamente;
    
    printf("Bem-vindo ao Jogo de Cartas de Estados!\n");

    do {
        int resultado = jogarPartida(cartas, num_cartas);
        
        if (resultado == 0) break;
        
        printf("\nDeseja jogar novamente? (S/N): ");
        scanf(" %c", &jogar_novamente);
        jogar_novamente = toupper(jogar_novamente);
        
    } while (jogar_novamente == 'S');
    
    printf("\nFim de jogo! Obrigado por jogar!\n");
    return 0;
}