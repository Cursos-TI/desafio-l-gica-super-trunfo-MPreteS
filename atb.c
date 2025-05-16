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
        int opcao;
        
        do {
            printf("\nSuper Trunfo\n");
            printf("1. Jogar\n");
            printf("2. Ver Cartas\n");
            printf("0. Sair\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);

            if (escolha ==1) {
                listarCartas(cartas, num_cartas);
                printf("\nEscolha sua carta(1-%d): ", num_cartas);
                int escolha_jogador;
                scanf("%d", &escolha_jogador);

                if (escolha_jogador < 1 || escolha_jogador > num_cartas) {
                    printf("Escolha Inválida!\n");
                    continue;
                }
                
                Carta carta_jogador = num_cartas[escolha_jogador-1];
                
                int indice_comp;
                do {
                    indice_comp = rand() % num_cartas;
                } while (indice_comp == escolha_jogador-1);

                Carta carta_PC = num_cartas[escolha_jogador-1];
                
                printf("\nVocê escolheu: %s\n", carta_jogador.nome);
                printf("O Computador está com: %s\n", carta_PC.nome);

                int atributo1, atributo2;

                printf("\nEscolha o primeiro atributo:\n");
                exibirMenuAtributos(0);
                printf("Digite o número do atributo: ");
                scanf("%d", &atributo1);

                if (atributo1 < 1 || atributo1 > 5) {
                    printf("Atributo Inválido!\n");
                    continue;
                }
                
                printf("\nEscolha um segundo atributo:\n");
                exibirMenuAtributos(atributo1);
                printf("Digite o número do atributo: ");
                scanf("%d", &atributo2);

                 if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
                    printf("Atributo Inválido!\n");
                    continue;

            }

            int resultado1 = compararAtributo(carta_jogador, carta_PC, atributo1);
            int resultado2 = compararAtributo(carta_jogador, carta_PC, atributo2);
            
            float soma_jogador = 0, soma_pc = 0;
            
            switch(atributo) {
                case 1:
                soma_jogador += carta_jogador.populacao;
                soma_pc += carta_PC.populacao;
                break;
                
                case 2:
                soma_jogador += carta_jogador.area;
                soma_pc += carta_PC.area;
                break;

                case 3:
                soma_jogador += carta_jogador.pib;
                soma_pc += carta_PC.pib;
                break;

                case 4:
                soma_jogador += carta_jogador.pontos_turisticos;
                soma_pc += carta_PC.pontos_turisticos;
                break;

                case 5:
                soma_jogador += carta_jogador.densidade_demografica;
                soma_pc += carta_PC.densidade_demografica;
                break;
            }

            switch(atributo2) {
                case 1:
                soma_jogador += carta_jogador.populacao;
                soma_pc += carta_PC.populacao;
                break;

                case 2:
                soma_jogador += carta_jogador.area;
                soma_pc += carta_PC.area;
                break;

                case 3:
                soma_jogador += carta_jogador.pib;
                soma_pc += carta_PC.pib;
                break;

                case 4:
                soma_jogador += carta_jogador.pontos_turisticos;
                soma_pc += carta_PC.pontos_turisticos;
                break;

                case 5:
                soma_jogador += carta_jogador.densidade_demografica;
                soma_pc += carta_PC.densidade_demografica;
                break;
            }

            printf("\nResultado\n");
            printf("Jogador: %s\n", carta_jogador.nome);
            printf("Computador: %s\n", carta_PC.nome);

            void exibirComparacaoAtributo(int atributo, Carta c1, Carta c2) {
                char *nome;
                float v1, v2;

                switch(atributo) {
                    case 1: nome = "População"; v1 = c1.populacao; v2 = c2.populacao; break;
                    case 2: nome = "Área"; v1 = c1.area; v2 = c2.area; break;
                    case 3: nome = "PIB"; v1 = c1.pib; v2 = c2.pib; break;
                    case 4: nome = "Pontos Turisticos"; v1 = c1.pontos_turisticos; v2 = c2.pontos_turisticos; break;
                    case 5: nome = "Densidade demográfica"; v1 = c1.densidade_demografica; v2 = c2.densidade_demografica; break;
                }

                printf("%s: Jogador (%.2f) VS Computador (%.2f)\n", nome, v1, v2);

                printf("\nPrimeiro Atributo:\n");
                exibirComparacaoAtributo(atributo1, carta_jogador, carta_PC);
                printf("Vencedor: %s\n",
                resultado1 == 1 ? "Jogador" : (resultado1 == -1 ? "Computador" : "Empate")
                );

                printf("\nSegundo Atributo:\n");
                exibirComparacaoAtributo(atributo2, carta_jogador, carta_PC);
                printf("Vencedor: %s\n",
                resultado2 == 1 ? "Jogador" : (resultado2 == -1 ? "Computador" : "Empate"));

                printf("\nSoma dos Atributos\n");
                printf("Jogaodor: %2.f\n", soma_jogador);
                printf("Computador: %2.f\n", soma_pc);

                if (soma_jogador > soma_pc) {
                    printf("\nVencedor Final: Jogador (%s)!\n", carta_jogador.nome);
                } else if (soma_pc > soma_jogador) {
                    printf("\nVencedor Final: Computador (%s)!\n", carta_PC.nome);
                } else {
                    printf("\nEmpate\n");
                }
            } else if (opcao == 2) {
                printf("\nCartas Disponíveis\n");
                for (int i = 0; i < num_cartas; i++) {
                    exibirCarta(num_cartas[i]);
                }
            }
        } while (opcao != 0);

        printf("Obrigado!\n");

        return 0;
    }
}