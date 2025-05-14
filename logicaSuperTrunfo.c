#include <string.h>
#include <stdio.h>

int main() {
    //Calculo das Cartas
    float densidadep1, densidadep2, pibc1, pibc2;
    float Inversoden1, Inversoden2, superpoder1, superpoder2;
    float densidadeinv1, densidadeinv2;

    // Carta 1
    char estado1[2];
    char codigo1[4];
    char cidade1[100];
    int populacao1;
    float area1;
    float pib1;
    int pontos1;

    // Carta 2
    char estado2[2];
    char codigo2[4];
    char cidade2[100];
    int populacao2;
    float area2;
    float pib2;
    int pontos2;

    // Apresentação do jogo
    printf("\n");
    printf("Agora, iniciaremos a criação das suas cartas.\n");
    printf("Por favor, siga as instruções abaixo.\n");
    printf("\n");

    // Criando a Carta 1
    printf("Criação da Carta 1\n");
    printf("Digite uma letra de 'A' a 'H' para representar um dos oito estados:\n");
    scanf("%1s", estado1);

    printf("Digite o código da carta (Ex: A01, B03):\n");
    scanf("%3s", codigo1);

    printf("Escolha o nome da sua cidade (Ex: Rio de Jeneiro):\n");
    // o [^\n] posibilizar ler nomes com espaco
    scanf(" %99[^\n]", cidade1); 

    printf("Digite o número de habitantes da sua cidade (Ex: 1000):\n");
    scanf("%d", &populacao1);

    printf("Digite a área da cidade em quilômetros quadrados (Ex: 100, 108.75):\n");
    scanf("%f", &area1);

    printf("Digite o Produto Interno Bruto (PIB) da sua cidade (Ex 93.80, 93):\n");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos que a sua cidade possui (Ex: 50):\n");
    scanf("%d", &pontos1);
    printf("\n");

    printf("Primeira carta criada com sucesso! Agora vamos criar a segunda carta.\n");
    printf("\n");

    // Criando a Carta 2
    printf("Criação da Carta 2\n");
    printf("Digite uma letra de 'A' a 'H' para representar um dos oito estados:\n");
    scanf("%1s", estado2);

    printf("Digite o código da carta (Ex: A01, B03):\n");
    scanf("%3s", codigo2);

    printf("Escolha o nome da sua cidade (Ex: Rio de Jeneiro):\n");
    scanf(" %99[^\n]", cidade2);  

    printf("Digite o número de habitantes da sua cidade (Ex: 1000):\n");
    scanf("%d", &populacao2);

    printf("Digite a área da cidade em quilômetros quadrados (Ex: 100, 108.75):\n");
    scanf("%f", &area2);

    printf("Digite o Produto Interno Bruto (PIB) da sua cidade (Ex 93.80, 93):\n");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos que a sua cidade possui (Ex: 50):\n");
    scanf("%d", &pontos2);

    printf("\n");
    printf("Cartas criadas com sucesso! Vamos analisar os dados.\n");
    printf("\n");

    //Calculo das cartas
    densidadep1 = (float) populacao1 / area1;
    densidadep2 = (float)  populacao2 /  area2;
    pibc1 = pib1 /  populacao1;
    pibc2 = pib2 / populacao2;
    Inversoden1 = (float) area1 / populacao1;
    Inversoden2 = (float) area2 / populacao2;
    superpoder1 = populacao1 + area1 + pib1 + pontos1 + pibc1 + Inversoden1;
    superpoder2 = populacao2 + area2 + pib2 + pontos2 + pibc2 + Inversoden2;

 
    // Exibicao das cartas
    printf("============ CARTA 1 ============\n");
    printf("Estado: %s \n", estado1);
    printf("Codigo: %s \n", codigo1);
    printf("Cidade: %s \n", cidade1);
    printf("População: %d habitantes \n", populacao1);
    printf("Área: %.2f km² \n", area1);
    printf("PIB: %.2f bilhões de reais \n", pib1);
    printf("Pontos Turísticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km² \n", densidadep1);
    printf("PIB per Capita: %.2f reais/habitante \n", pibc1);
    printf("O Super Poder dessa carta seria: %.2f \n", superpoder1);
    printf("\n");

    printf("============ CARTA 2 ============\n");
    printf("Estado: %s \n", estado2);
    printf("Codigo: %s \n", codigo2);
    printf("Cidade: %s \n", cidade2);
    printf("População: %d habitantes \n", populacao2);
    printf("Área: %.2f km² \n", area2);
    printf("PIB: %.2f bilhões de reais \n", pib2);
    printf("Pontos Turísticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km² \n", densidadep2);
    printf("PIB per Capita: %.2f reais/habitantes \n", pibc2);
    printf("O Super Poder dessa carta seria: %.2f \n", superpoder2);
    printf("\n");

    //resultados 
    printf("============ RESULTADO DA COMPARAÇÃO ============\n");
    printf("\n");

    printf("Comparação de cartas (Atributo: População): \n");
    printf("Carta 1 - %s: %d \n", cidade1, populacao1);
    printf("Carta 2 - %s: %d \n", cidade2, populacao2);
    if (populacao1 > populacao2)
    {
        printf("Resultado: Carta 1 (%s) venceu! \n", cidade1); 
    }else
    {
        printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
    }
    printf("\n");
    printf("Comparação de cartas (Atributo: Área): \n");
    printf("Carta 1 - Área %s: %.2f \n", cidade1, area1);
    printf("Carta 2 - Área %s: %.2f \n", cidade2, area2);
    if (area1 > area2)
    {
        printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
    }else
    {
        printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
    }
    printf("\n");
    printf("Comparação de cartas (Atributo: PIB ): \n");
    printf("Carta 1 - PIB %s: %.2f \n", cidade1, pib1);
    printf("Carta 2 - PIB %s: %.2f \n", cidade2, pib2);
    if (pib1 > pib2)
    {
        printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
    }else
    {
        printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
    }
    printf("\n");
    printf("Comparação de cartas (Atributo: Pontos Turísticos): \n");
    printf("Carta 1 - Pontos Turísticos %s: %d \n", cidade1, pontos1);
    printf("Carta 2 - Pontos Turísticos %s: %d \n", cidade2, pontos2);
    if (pontos1 > pontos2)
    {
        printf("Resultado: Carta 1 (%s) venceu! \n", cidade1); 
    }else
    {
        printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
    }
    printf("\n");
    printf("Comparação de cartas (Atributo: Densidade Populacional): \n");
    printf("Carta 1 - Densidade Populacional %s: %.2f \n", cidade1, densidadep1);
    printf("Carta 2 - Densidade Populacional %s: %.2f \n", cidade2, densidadep2);
    if (densidadep1 < densidadep2)
    {
        printf("Resultado: Carta 1 (%s) venceu! \n", cidade1); 
    }else
    {
        printf("Resultado: Carta 2 (%s) venceu! \n", cidade2); 
    }
    printf("\n");
    printf("Comparação de cartas (Atributo: PIB per Capita): \n");
    printf("Carta 1 - PIB per Capita %s: %.2f \n", cidade1, pibc1);
    printf("Carta 2 - PIB per Capita %s: %.2f \n", cidade2, pibc2);
    if (pibc1 > pibc2)
    {
        printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
    }else
    {
        printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
    }
    printf("\n");
    printf("Comparação de cartas (Atributo: Super Poder): \n");
    printf("Carta 1 - Super Poder %s: %.2f \n", cidade1, superpoder1);
    printf("Carta 2 - Super Poder %s: %.2f \n", cidade2, superpoder2);
    if (superpoder1 > superpoder2)
    {
        printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
    }else
    {
        printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
    }
    
    
    
    
    
    


return 0;
}