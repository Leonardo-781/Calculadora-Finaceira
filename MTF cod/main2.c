#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int op;
    float VP, VF, i, n, J;
    float i100;

    do {
        printf("\n\n\tMenu: Calculadora Financeira\n\n");

        printf("1 - Juros Compostos\n");
        printf("2 - Juros Simples\n");
        printf("3 - calcFVP (Price)\n");
        printf("4 - Desconto Comercial Composto\n");
        printf("5 - Desconto Racional Composto\n");
        printf("6 - SAC - Sistema de Amortizacao Constante\n");
        printf("7 - Taxas Equivalentes\n");
        printf("8 - VPL - Valor Presente Liquido\n");
        printf("0 - Encerrar\n");

        printf("\nSelecione uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                // Juros Compostos
                printf("\n\tOpcao Selecionada: Juros Compostos.\n");
                printf("\nInsira o Valor Presente (VP): ");
                scanf("%f", &VP);

                printf("Insira a Taxa Unitaria (i): ");
                scanf("%f", &i);

                printf("Insira o Tempo (n): ");
                scanf("%f", &n);

                VF = VP * pow((1 + i), n);

                printf("\nO valor futuro eh: R$%.2f", VF);
                break;

            case 2:
                // Juros Simples
                printf("\n\tOpcao Selecionada: Juros Simples.\n");
                printf("\nInsira o Valor Presente (VP): ");
                scanf("%f", &VP);

                printf("Insira a Taxa Unitaria (i): ");
                scanf("%f", &i);

                printf("Insira o Tempo (n): ");
                scanf("%f", &n);

                VF = VP * (1 + i * n);

                printf("\nO valor futuro eh: R$%.2f", VF);
                break;

            case 3:
                // calcFVP (Price)
                printf("\n\tOpcao Selecionada: calcFVP (Price).\n");
                printf("\nInsira o numero de parcelas (n): ");
                scanf("%f", &n);

                printf("Insira a taxa unitaria de juros (i): ");
                scanf("%f", &i);

                float pot = pow((1 + i), -n);
                float fvp = (1 - pow((1 + i), -n)) / i;

                printf("\nFVP = %.6f", fvp);
                printf("\nInsira o valor presente: ");
                scanf("%f", &VP);

                float pmt = VP * (1 / fvp);

                printf("\nPMT = %.6f", pmt);
                printf("\nMultiplicar por: ");

                float multPor;

                scanf("%f", &multPor);
                multPor = fvp * multPor;

                printf("\nResultado: R$%.2f", multPor);
                break;

            // ... (Other cases remain unchanged)

            case 7:
                // Taxas Equivalentes
                printf("\n\tOpcao Selecionada: Taxas Equivalentes.");
                do {
                    printf("\n\n\tMenu: Conversao de Taxas\n");
                    printf("\n1 - Calcular Maior para Menor (i = (1+i)^(1/n)):");
                    printf("\n2 - Calcular Menor para Maior (i = (1+i)^(n)):");
                    printf("\n3 - Calcular Taxa Efetiva (i = ik/k):");
                    printf("\n4 - Voltar para o Menu Principal\n");
                    printf("\nSelecione a opcao: ");
                    scanf("%d", &op);

                    switch (op) {
                        case 1:
                            // Calcular Maior para Menor
                            printf("\nOpcao selecionada: i = (1+i)^(1/n)\n");
                            printf("Insira o Tempo 'n': ");
                            scanf("%f", &n);
                            printf("Insira a Taxa Conhecida 'ic': ");
                            scanf("%f", &i);
                            i = pow((1 + i), (1 / n)) - 1;
                            i100 = i * 100;
                            printf("\nO valor da Nova Taxa eh: %.6f ou %.6f%%", i, i100);
                            break;

                        case 2:
                            // Calcular Menor para Maior
                            printf("\nOpcao selecionada: i = (1+i)^(n)\n");
                            printf("Insira o Tempo 'n': ");
                            scanf("%f", &n);
                            printf("Insira a Taxa Conhecida 'ic': ");
                            scanf("%f", &i);
                            i = pow((1 + i), n) - 1;
                            i100 = i * 100;
                            printf("\nO valor da Nova Taxa eh: %.6f ou %.6f%%.", i, i100);
                            break;

                        case 3:
                            // Calcular Taxa Efetiva
                            printf("\nOpcao selecionada: i = ik/k");
                            printf("\nInsira a Taxa Nominal (ik): ");
                            scanf("%f", &i);
                            printf("Insira o periodo (k): ");
                            scanf("%f", &n);
                            i = i / n;

                            printf("\nA taxa efetiva eh: %.6f.", i);
                            break;

                        case 4:
                            printf("\nVoltando para o Menu Principal...\n");
                            break;

                        default:
                            printf("\nOpcao invalida!");
                    }

                } while (op != 4);
                break;

            // ... (Other cases remain unchanged)

        }
    } while (op != 0);

    return 0;
}
