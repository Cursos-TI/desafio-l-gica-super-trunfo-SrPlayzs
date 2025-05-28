#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// Estrutura para representar uma carta
typedef struct {
    char estado[3];
    char codigo[4];
    char cidade[100];
    int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
    float pib_per_capita;
    float inverso_densidade;
    float super_poder;
} Carta;

// Função para calcular métricas derivadas
void calcular_metricas(Carta *carta) {
    if (carta->area != 0) {  // Proteção contra divisão por zero
        carta->densidade = (float)carta->populacao / carta->area;
        carta->inverso_densidade = carta->area / carta->populacao;
    } else {
        carta->densidade = 0;
        carta->inverso_densidade = 0;
    }
    
    if (carta->populacao != 0) {  // Proteção contra divisão por zero
        carta->pib_per_capita = carta->pib * 1000000000 / carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }
    
    carta->super_poder = carta->populacao + carta->area + carta->pib + 
                         carta->pontos + carta->pib_per_capita + carta->inverso_densidade;
}

// Função para exibir uma carta
void exibir_carta(Carta carta, int numero) {
    printf("\n============ CARTA %d ============\n", numero);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f reais/habitante\n", carta.pib_per_capita);
    printf("Inverso da Densidade: %.6f km²/habitante\n", carta.inverso_densidade);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

// Função para criar uma carta
void criar_carta(Carta *carta, int numero) {
    printf("\nCriação da Carta %d\n", numero);
    
    printf("Digite uma letra de 'A' a 'H' para representar um dos oito estados:\n");
    scanf("%2s", carta->estado);
    getchar(); // Limpa o buffer do teclado

    printf("Digite o código da carta (Ex: A01, B03):\n");
    scanf("%3s", carta->codigo);
    getchar();

    printf("Escolha o nome da sua cidade:\n");
    scanf(" %99[^\n]", carta->cidade);
    getchar();

    printf("Digite o número de habitantes da sua cidade:\n");
    while(scanf("%d", &carta->populacao) != 1 || carta->populacao < 0) {
        printf("Valor inválido! Digite um número positivo: ");
        while(getchar() != '\n'); // Limpa o buffer
    }

    printf("Digite a área da cidade em quilômetros quadrados:\n");
    while(scanf("%f", &carta->area) != 1 || carta->area <= 0) {
        printf("Valor inválido! Digite um número positivo: ");
        while(getchar() != '\n');
    }

    printf("Digite o Produto Interno Bruto (PIB) da sua cidade em bilhões:\n");
    while(scanf("%f", &carta->pib) != 1 || carta->pib < 0) {
        printf("Valor inválido! Digite um número positivo: ");
        while(getchar() != '\n');
    }

    printf("Digite o número de pontos turísticos que a sua cidade possui:\n");
    while(scanf("%d", &carta->pontos) != 1 || carta->pontos < 0) {
        printf("Valor inválido! Digite um número positivo: ");
        while(getchar() != '\n');
    }

    calcular_metricas(carta);
}

// Função para comparar dois atributos
int comparar_atributos(float valor1, float valor2, bool menor_vence) {
    if (menor_vence) {
        if (valor1 < valor2) return 1;
        if (valor2 < valor1) return 2;
    } else {
        if (valor1 > valor2) return 1;
        if (valor2 > valor1) return 2;
    }
    return 0; // Empate
}

int main() {
    Carta carta1, carta2;
    int opcao;
    int atributo1, atributo2;
    
    printf("\n=== SUPER TRUNFO ===\n");
    printf("Bem-vindo ao jogo Super Trunfo!\n");
    
    // Criar as cartas
    criar_carta(&carta1, 1);
    criar_carta(&carta2, 2);
    
    printf("\nCartas criadas com sucesso!\n");
    
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Exibir cartas\n");
        printf("2. Comparar cartas\n");
        printf("3. Comparar cartas\n");
        printf("4. Comparar cartas\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        
        while(scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 5) {
            printf("Opção inválida! Digite um número entre 1 e 5: ");
            while(getchar() != '\n');
        }
        
        switch(opcao) {
            case 1:
                exibir_carta(carta1, 1);
                exibir_carta(carta2, 2);
                break;
                
            case 2: {
                // Nível Novato - Comparação com densidade populacional (menor valor vence)
                int resultado = comparar_atributos(carta1.densidade, carta2.densidade, true);
                
                printf("\n=== RESULTADO (Nível Novato) ===\n");
                printf("Atributo comparado: Densidade Populacional (menor vence)\n");
                printf("%s: %.2f hab/km²\n", carta1.cidade, carta1.densidade);
                printf("%s: %.2f hab/km²\n", carta2.cidade, carta2.densidade);
                
                if (resultado == 1) {
                    printf("Vencedor: %s\n", carta1.cidade);
                } else if (resultado == 2) {
                    printf("Vencedor: %s\n", carta2.cidade);
                } else {
                    printf("Empate!\n");
                }
                break;
            }
                
            case 3: {
                int atributo;
                bool menor_vence = false;
                
                printf("\nEscolha o atributo para comparação:\n");
                printf("1. População (maior vence)\n");
                printf("2. Área (maior vence)\n");
                printf("3. PIB (maior vence)\n");
                printf("4. Pontos Turísticos (maior vence)\n");
                printf("5. Densidade Populacional (menor vence)\n");
                printf("6. PIB per Capita (maior vence)\n");
                printf("7. Super Poder (maior vence)\n");
                printf("Opção: ");
                
                while(scanf("%d", &atributo) != 1 || atributo < 1 || atributo > 7) {
                    printf("Opção inválida! Digite um número entre 1 e 7: ");
                    while(getchar() != '\n');
                }
                
                float valor1, valor2;
                const char* nome_atributo;
                
                switch(atributo) {
                    case 1:
                        valor1 = carta1.populacao;
                        valor2 = carta2.populacao;
                        nome_atributo = "População";
                        break;
                    case 2:
                        valor1 = carta1.area;
                        valor2 = carta2.area;
                        nome_atributo = "Área";
                        break;
                    case 3:
                        valor1 = carta1.pib;
                        valor2 = carta2.pib;
                        nome_atributo = "PIB";
                        break;
                    case 4:
                        valor1 = carta1.pontos;
                        valor2 = carta2.pontos;
                        nome_atributo = "Pontos Turísticos";
                        break;
                    case 5:
                        valor1 = carta1.densidade;
                        valor2 = carta2.densidade;
                        nome_atributo = "Densidade Populacional";
                        menor_vence = true;
                        break;
                    case 6:
                        valor1 = carta1.pib_per_capita;
                        valor2 = carta2.pib_per_capita;
                        nome_atributo = "PIB per Capita";
                        break;
                    case 7:
                        valor1 = carta1.super_poder;
                        valor2 = carta2.super_poder;
                        nome_atributo = "Super Poder";
                        break;
                }
                
                int resultado = comparar_atributos(valor1, valor2, menor_vence);
                
                printf("\n=== RESULTADO (Nível Aventureiro) ===\n");
                printf("Atributo comparado: %s (%s)\n", nome_atributo, menor_vence ? "menor vence" : "maior vence");
                printf("%s: %.2f\n", carta1.cidade, valor1);
                printf("%s: %.2f\n", carta2.cidade, valor2);
                
                if (resultado == 1) {
                    printf("Vencedor: %s\n", carta1.cidade);
                } else if (resultado == 2) {
                    printf("Vencedor: %s\n", carta2.cidade);
                } else {
                    printf("Empate!\n");
                }
                break;
            }
                
            case 4: {
                printf("\nEscolha o primeiro atributo:\n");
                printf("1. População\n");
                printf("2. Área\n");
                printf("3. PIB\n");
                printf("4. Pontos Turísticos\n");
                printf("5. Densidade Populacional\n");
                printf("6. PIB per Capita\n");
                printf("7. Super Poder\n");
                printf("Opção: ");
                
                while(scanf("%d", &atributo1) != 1 || atributo1 < 1 || atributo1 > 7) {
                    printf("Opção inválida! Digite um número entre 1 e 7: ");
                    while(getchar() != '\n');
                }
                
                printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
                for (int i = 1; i <= 7; i++) {
                    if (i != atributo1) {
                        printf("%d. %s\n", i, 
                            i == 1 ? "População" :
                            i == 2 ? "Área" :
                            i == 3 ? "PIB" :
                            i == 4 ? "Pontos Turísticos" :
                            i == 5 ? "Densidade Populacional" :
                            i == 6 ? "PIB per Capita" : "Super Poder");
                    }
                }
                printf("Opção: ");
                
                while(scanf("%d", &atributo2) != 1 || atributo2 < 1 || atributo2 > 7 || atributo2 == atributo1) {
                    printf("Opção inválida ou igual ao primeiro atributo! Digite novamente: ");
                    while(getchar() != '\n');
                }
                
                // Arrays para mapear atributos
                const char* nomes_atributos[] = {
                    "", "População", "Área", "PIB", "Pontos Turísticos", 
                    "Densidade Populacional", "PIB per Capita", "Super Poder"
                };
                
                const bool menor_vence[] = {
                    false, false, false, false, false, true, false, false
                };
                
                // Valores dos atributos para cada carta
                float valores1[] = {
                    0, (float)carta1.populacao, carta1.area, carta1.pib, 
                    (float)carta1.pontos, carta1.densidade, 
                    carta1.pib_per_capita, carta1.super_poder
                };
                
                float valores2[] = {
                    0, (float)carta2.populacao, carta2.area, carta2.pib, 
                    (float)carta2.pontos, carta2.densidade, 
                    carta2.pib_per_capita, carta2.super_poder
                };
                
                // Comparar atributos
                int res_attr1 = comparar_atributos(
                    valores1[atributo1], valores2[atributo1], menor_vence[atributo1]);
                
                int res_attr2 = comparar_atributos(
                    valores1[atributo2], valores2[atributo2], menor_vence[atributo2]);
                
                // Soma dos atributos
                float soma1 = valores1[atributo1] + valores1[atributo2];
                float soma2 = valores2[atributo1] + valores2[atributo2];
                
                printf("\n=== RESULTADO (Nível Mestre) ===\n");
                
                // Resultado do primeiro atributo
                printf("\nAtributo 1: %s (%s)\n", 
                    nomes_atributos[atributo1], 
                    menor_vence[atributo1] ? "menor vence" : "maior vence");
                printf("%s: %.2f\n", carta1.cidade, valores1[atributo1]);
                printf("%s: %.2f\n", carta2.cidade, valores2[atributo1]);
                printf("Vencedor: %s\n", 
                    res_attr1 == 1 ? carta1.cidade : 
                    res_attr1 == 2 ? carta2.cidade : "Empate");
                
                // Resultado do segundo atributo
                printf("\nAtributo 2: %s (%s)\n", 
                    nomes_atributos[atributo2], 
                    menor_vence[atributo2] ? "menor vence" : "maior vence");
                printf("%s: %.2f\n", carta1.cidade, valores1[atributo2]);
                printf("%s: %.2f\n", carta2.cidade, valores2[atributo2]);
                printf("Vencedor: %s\n", 
                    res_attr2 == 1 ? carta1.cidade : 
                    res_attr2 == 2 ? carta2.cidade : "Empate");
                
                // Resultado final
                printf("\nSoma dos atributos:\n");
                printf("%s: %.2f\n", carta1.cidade, soma1);
                printf("%s: %.2f\n", carta2.cidade, soma2);
                
                if (soma1 > soma2) {
                    printf("\nRESULTADO FINAL: %s venceu!\n", carta1.cidade);
                } else if (soma2 > soma1) {
                    printf("\nRESULTADO FINAL: %s venceu!\n", carta2.cidade);
                } else {
                    printf("\nRESULTADO FINAL: Empate!\n");
                }
                break;
            }
                
            case 5:
                printf("Saindo do jogo...\n");
                break;
        }
    } while (opcao != 5);
    
    return 0;
}