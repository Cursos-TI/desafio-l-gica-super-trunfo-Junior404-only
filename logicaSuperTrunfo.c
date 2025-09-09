#include <stdio.h>

// Criando uma struct para armazenar os atributos das cartas
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao; // Densidade demografica: populacao / area
    float area;
    float pib;
    int pontosTuristicos;

};

// Criando uma funcao comparar_atributos
// Declarando uma funcao que retorne um valor inteiro
int comparar_atributos(int atributo, struct Carta cartas[2]) {
    switch (atributo) {

        // Caso o usuario escolha o atributo Populacao
        case 1:
            printf("Jogador escolheu atributo: Populacao\n");
            if(cartas[0].populacao > cartas[1].populacao) {
                printf("Cidade: %s\n", cartas[0].nomeCidade);
                printf("Populacao da carta 1 = %d\n", cartas[0].populacao);
                printf("Populacao da carta 2 = %d\n\n", cartas[1].populacao);
                printf("Cidade: %s\n", cartas[0].nomeCidade);
                printf("Carta 1 possui o maior valor\n\n");
            }
            else if (cartas[0].populacao < cartas[1].populacao) {
                printf("Populacao da carta 1 = %d\n", cartas[0].populacao);
                printf("Populacao da carta 2 = %d\n\n", cartas[1].populacao);
                printf("Pais: %s\n", cartas[1].nomeCidade);
                printf("Carta 2 possui o maior valor!\n\n");
            }
            else {
                printf("Empate!\n\n");
            }
        break;

        // Caso o usuario escolha o atributo Area
        case 2:
            printf("Jogador escolheu atributo: Area\n");
            if (cartas[0].area > cartas[1].area) {
                printf("Area da carta 1 = %.2f\n", cartas[0].area);
                printf("Area da carta 2 = %.2f\n\n", cartas[1].area);
                printf("Pais: %s\n", cartas[0].nomeCidade);
                printf("Carta 1 possui o maior valor!\n\n");
            }
            else if (cartas[0].area < cartas[1].area) {
                printf("Area da carta 1 = %.2f\n", cartas[0].area);
                printf("Area da carta 2 = %.2f\n\n", cartas[1].area);
                printf("Pais: %s\n", cartas[1].nomeCidade);
                printf("Carta 2 possui o maior valor!\n\n");
            }
            else {
                printf("Empate!\n\n");
            }
        break;

        // Caso o usuario escolha o atributo PIB
        case 3:
            printf("Jogador escolheu atributo: PIB\n");
            if (cartas[0].pib > cartas[1].pib) {
                printf("PIB da carta 1 = %.2f\n", cartas[0].pib);
                printf("PIB da carta 2 = %.2f\n\n", cartas[1].pib);
                printf("Pais: %s\n", cartas[0].nomeCidade);
                printf("Carta 1 possui o maior valor!\n\n");
            }
            else if (cartas[0].pib < cartas[1].pib) {
                printf("PIB da carta 1 = %.2f\n", cartas[0].pib);
                printf("PIB da carta 2 = %.2f\n\n", cartas[1].pib);
                printf("Pais: %s\n", cartas[1].nomeCidade);
                printf("Carta 2 possui o maior valor!\n\n");
            }
            else {
                printf("Empate!\n\n");
            }
        break;


        // Caso o usuario escolha o atributo Pontos turisticos
        case 4:
            printf("Jogador escolheu atributo: Pontos turisticos\n");
            if (cartas[0].pontosTuristicos > cartas[1].pontosTuristicos) {
                printf("Pontos turisticos da carta 1 = %d\n", cartas[0].pontosTuristicos);
                printf("Pontos turisticos da carta 2 = %d\n\n", cartas[1].pontosTuristicos);
                printf("Pais: %s\n", cartas[0].nomeCidade);
                printf("Carta 1 possui o maior valor!\n\n");
            }
            else if (cartas[0].pontosTuristicos < cartas[1].pontosTuristicos) {
                printf("Pontos turisticos da carta 1 = %d\n", cartas[0].pontosTuristicos);
                printf("Pontos turisticos da carta 2 = %d\n\n", cartas[1].pontosTuristicos);
                printf("Pais: %s\n", cartas[1].nomeCidade);
                printf("Carta 2 possui o maior valor!\n\n");
            }
            else {
                printf("Empate!\n\n");
            }
        break;


        // Caso o usuario escolha o atributo Densidade demografica
        case 5:
            printf("Jogador escolheu atributo: Densidade demografica\n\n");
            float dens1 = (float) cartas[0].populacao / cartas[0].area;
            float dens2 = (float) cartas[1].populacao / cartas[1].area;
            printf("Densidade carta 1 = %.2f\n", dens1);
            printf("Densidade carta 2 = %.2f\n", dens2);

            if (dens1 < dens2) {
                printf("Carta 1 possui a menor densidade demografica!\n");
                printf("Carta 1 vencedora!!!\n");
                return 1; // Retorne 1 (encerre o programa de vez) caso a carta possui a menor densidade demografica
            }
            else if (dens2 < dens1) {
                printf("Carta 2 possui a menor densidade demografica!\n");
                printf("Carta 2 vencedora!!!\n");
                return 1; // Retorne 1 (encerre o programa de vez) caso a carta possui a menor densidade demografica
            }
            else {
                printf("Empate!\n");
            }
        break;
    }
    return 0; // Retorne 0 (Caso o usuario nao escolha o atributo Densidade demografica) e continue prosseguindo com a continuacao e execucao do codigo
}


// Criando uma funcao para somar os valores dos atributos individualmente
float soma_valor_atributos(int atributo, struct Carta cartas) {
   switch (atributo) {
        case 1: return cartas.populacao;
        case 2: return cartas.area;
        case 3: return cartas.pib;
        case 4: return cartas.pontosTuristicos;
        case 5: return cartas.populacao / cartas.area;
        default: return 0;

   }
}

int main() {
    struct Carta cartas[2]; // vetor para armazenar 2 cartas


    for (int i = 0; i < 2; i++) {
        printf("\n--- Cadastro da Carta %d ---\n", i + 1);

        printf("Estado (A-H): ");
        scanf(" %c", &cartas[i].estado); // espaco antes do %c evita problemas com enter

        printf("Codigo da carta (ex: A01): ");
        scanf("%s", cartas[i].codigo);

        printf("Nome da cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade); // le string com espaco

        printf("Populacao: ");
        scanf("%d", &cartas[i].populacao);

        printf("Area em km2: ");
        scanf("%f", &cartas[i].area);

        printf("PIB: ");
        scanf("%f", &cartas[i].pib);

        printf("Numero de pontos turisticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);
    }

    // Mostrando na tela do usuario todos os dados das cartas dos valores de seus atributos
    printf("\n=== Cartas Cadastradas ===\n");
    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Codigo: %s\n", cartas[i].codigo);
        printf("Cidade: %s\n", cartas[i].nomeCidade);
        printf("Populacao: %d\n", cartas[i].populacao);
        printf("Area: %.2f km2\n", cartas[i].area);
        printf("PIB: %.2f\n", cartas[i].pib);
        printf("Pontos Turisticos: %d\n\n", cartas[i].pontosTuristicos);
    }



    // Criando duas variaveis, uma para cada carta, para cada carta, o usuario ira digitar o atributo escolhido
    int atributo1, atributo2;

    printf("======== Escolha os atributo para comparar as cartas ========\n");
    printf("** 1.Populacao**\n");
    printf("** 2.Area**\n");
    printf("** 3.PIB**\n");
    printf("** 4.Numero de pontos turisticos**\n");
    printf("** 5.Densidade demografica**\n");
    printf("== Escolha um atributo: ");
    printf("\n");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("Tente novamente, atributo invalido!\n");
        return 1; // Caso o usuario digitar um valor menor que 1 ou maior que 5, o programa se encerrar de vez e acaba aqui
    }

    // Antes de chamar a funcao, saber primeiro qual vai ser o digito em que o usuario ira digitar

    // Caso o usuario digitar um valor dentro das opcoes, chamar a funcao dentro do if e logo em seguida
    // executar os comando abaixo.
    if (comparar_atributos(atributo1, cartas) == 1) {
        return 0;
    }

   do {
        printf("======== Escolha um segundo atributo para comparar as cartas ========\n");
        printf("1.Populacao**\n");
        printf("2.Area**\n");
        printf("3.PIB**\n");
        printf("4.Numero de pontos turisticos**\n");
        printf("5.Densidade demografica\n");
        printf("==== Escolha um segundo atributo: ");
        scanf("%d", &atributo2);

        if (atributo1 == atributo2) {
            printf("Erro o atributo anterior ja foi escolhido\n\n");
        }
        else if (atributo1 < 1 || atributo2 > 5) {
            printf("Erro atributo invalido\n\n");
        }
        else {
            // Se nenhum dos ifs acima for validado, execute o else, chamando a funcao, consequentemente ele ira mostrar
            // todos os dados de cada carta
            if (comparar_atributos(atributo2, cartas) == 1) {
                return 0;
            }
        }

   } while (atributo1 == atributo2 || atributo1 < 1 || atributo2 > 5); // Enquanto o usuario digitar o atributo2
                                                                       // igual ao atributo1 ou atributo1 menor que 1 ou
                                                                       // atributo2 maior que 5, o processo do "do" se repete
                                                                       // enquanto o usuario nao digitar um valor desejado

    // Criando uma variavel para armazenar as somas de cada carta
    float somaCarta1 = 0, somaCarta2 = 0;


   // Chamando a funcao de somar os valores dos atributos e armazenando na variavel
   somaCarta1 = soma_valor_atributos(atributo1, cartas[0]) + soma_valor_atributos(atributo2, cartas[0]);
   somaCarta2 = soma_valor_atributos(atributo1, cartas[1]) + soma_valor_atributos(atributo2, cartas[1]);

   printf("======= Soma dos atributos de cada carta =======\n\n");
   printf("%s\n", (somaCarta1 > somaCarta2) ? "A carta 1 venceu a rodada pela soma dos atributos." :
                (somaCarta1 < somaCarta2) ? "A carta 2 venceu a rodada pela soma dos atributos." :
                                            "Empate nos atributos!");

    // Retorne o valor Verdadeiro (0) caso nao tenha nenhuma falha com o codigo
    return 0;
}