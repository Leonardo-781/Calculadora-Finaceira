#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para converter taxa nominal para efetiva em capitalização composta
float converteParaEfetiva(float iNominal, float n)
{
    return pow((1 + iNominal / n), n) - 1;
}

int main()
{
    int op;
    float VP, VF, i, n, J;
    float i100;

    do
    {
        printf("\n\n\tMenu: Calculadora Financeira\n\n");
        printf("1 - Juros Compostos\n");
        printf("2 - Juros Simples\n");
        printf("3 - calcFVP (Price)\n");
        printf("4 - Desconto Comercial Composto\n");
        printf("5 - Desconto Racional Composto\n");
        printf("6 - SAC - Sistema de Amortizacao Constante\n");
        printf("7 - Taxas Equivalentes\n");
        printf("8 - VPL - Valor Presente Liquido\n");
        printf("9 - Cálculos Adicionais\n");
        printf("0 - Encerrar\n");

        printf("\nSelecione uma opcao: ");
        scanf("%d", &op);

        switch (op)
        {
            {
            case 1:
                printf("\n\tOpcao Selecionada: Juros Compostos.\n");
                printf("\nInsira o Valor Futuro (VF): ");
                scanf("%f", &VF);

                printf("Insira a Taxa Unitaria (i): ");
                scanf("%f", &i);

                printf("Insira o Tempo (n): ");
                scanf("%f", &n);

                VP = VF / pow((1 + i), n);

                printf("\nO valor presente eh: R$%.2f", VP);
                break;

            case 2:
                printf("\n\tOpcao Selecionada: Juros Simples.\n");
                printf("\nInsira o Valor Presente (VP): ");
                scanf("%f", &VP);

                printf("Insira a Taxa Unitaria (i): ");
                scanf("%f", &i);

                printf("Insira o Tempo (n): ");
                scanf("%f", &n);

                VF = VP * pow((1 + i), n);

                printf("\nO valor futuro eh: R$%.2f", VF);
                break;

            case 3:
                printf("\n\tOpcao Selecionada: calcFVP (Price).\n");
                printf("\nInsira o numero de parcelas (n): ");
                scanf("%f", &n);
                printf("Insira a taxa unitaria de juros (i): ");
                scanf("%f", &i);

                float pmt = pow((1 + i), -n);
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

            case 4:
                printf("\n\tOpcao Selecionada: Desconto Comercial Composto.\n");
                printf("\n1- Calcular Valor Atual (A)\n");
                printf("\nInsira o Valor Nominal (N): ");
                scanf("%f", &VF);

                printf("Insira a Taxa Unitaria (i): ");
                scanf("%f", &i);

                printf("Insira o Tempo (n): ");
                scanf("%f", &n);

                VP = VF * pow((1 - i), n);

                printf("\nO Valor Atual eh: R$%.2f", VP);
                break;

            case 5:
                printf("\n\tOpcao Selecionada: Desconto Racional Composto.\n");
                printf("\n1- Calcular Valor Atual (A)\n");
                printf("\nInsira o Valor Nominal (N): ");
                scanf("%f", &VF);

                printf("Insira a Taxa Unitaria (i): ");
                scanf("%f", &i);

                printf("Insira o Tempo (n): ");
                scanf("%f", &n);

                VP = VF * pow((1 + i), -n);

                printf("\nO Valor Atual eh: R$%.2f", VP);
                break;

            case 6:
                printf("\n\tOpcao Selecionada: SAC - Sistema de Amortizacao Constante.\n");
                int nSAC, tSAC;
                float pmtSAC, amortSAC, jSAC, sdSAC;

                do
                {
                    printf("\n1 - Calcular PMT");
                    printf("\n2 - Calcular Amortizacao");
                    printf("\n3 - Calcular Juros");
                    printf("\n4 - Calcular Saldo Devedor");
                    printf("\n5 - Voltar para o Menu Principal\n");
                    printf("\nInsira a opcao desejada: ");
                    scanf("%d", &op);

                    switch (op)
                    {
                    case 1:
                        printf("\n\tCalcular PMT:");
                        printf("\nInsira o Valor Presente (VP): ");
                        scanf("%f", &VP);
                        printf("Insira o numero de periodos (n): ");
                        scanf("%d", &nSAC);
                        printf("Insira a taxa de juros (i): ");
                        scanf("%f", &i);
                        printf("Insira o numero da prestacao desejada (t): ");
                        scanf("%d", &tSAC);

                        amortSAC = VP / nSAC;
                        pmtSAC = amortSAC * (1 + (nSAC - tSAC + 1) * i);

                        printf("\n-----------------------");
                        printf("\nPMT{%d} = R$%.2f", tSAC, pmtSAC);
                        printf("\n-----------------------");
                        break;

                    case 2:
                        printf("\n\tCalcular Amortizacao:");
                        printf("\nInsira o Valor Presente (VP): ");
                        scanf("%f", &VP);
                        printf("Insira o numero de periodos (n): ");
                        scanf("%d", &nSAC);

                        amortSAC = VP / nSAC;

                        printf("\n-----------------------");
                        printf("\nAmortizacao = R$%.2f", amortSAC);
                        printf("\n-----------------------\n");
                        break;

                    case 3:
                        printf("\n\tCalcular Juros:");
                        printf("\nInsira o Valor Presente (VP): ");
                        scanf("%f", &VP);
                        printf("Insira o numero de periodos (n): ");
                        scanf("%d", &nSAC);
                        printf("Insira a taxa de juros (i): ");
                        scanf("%f", &i);
                        printf("Insira o numero da prestacao desejada (t): ");
                        scanf("%d", &tSAC);

                        amortSAC = VP / nSAC;
                        jSAC = amortSAC * (nSAC - tSAC + 1) * i;

                        printf("\nJuros{%d} = R$%.2f", tSAC, jSAC);
                        break;

                    case 4:
                        printf("\n\tCalcular Saldo Devedor:");
                        printf("\nInsira o Valor Presente (VP): ");
                        scanf("%f", &VP);
                        printf("Insira o numero de periodos (n): ");
                        scanf("%d", &nSAC);

                        printf("Insira o numero da prestacao desejada (t): ");
                        scanf("%d", &tSAC);

                        amortSAC = VP / nSAC;
                        sdSAC = VP - (amortSAC * tSAC);

                        printf("\n-----------------------\n");
                        printf("\nSaldo Devedor{%d} = R$%.2f", tSAC, sdSAC);
                        printf("\n-----------------------\n");
                        break;

                    case 5:
                        printf("\nVoltando para o Menu Principal...\n");
                        break;
                    }

                } while (op != 5);

                break;

            case 7:
                printf("\n\tOpcao Selecionada: Taxas Equivalentes.");
                do
                {
                    printf("\n\n\tMenu: Conversao de Taxas\n");
                    printf("\n1 - Calcular Maior para Menor (i = (1+i)^(1/n)):");
                    printf("\n2 - Calcular Menor para Maior (i = (1+i)^(n)):");
                    printf("\n3 - Calcular Taxa Efetiva (i = ik/k):");
                    printf("\n4 - Voltar para o Menu Principal\n");
                    printf("\nSelecione a opcao: ");
                    scanf("%d", &op);

                    switch (op)
                    {
                    case 1:
                        printf("\nOpcao selecionada: i = (1+i)^(1/12)-1\n");
                        printf("Insira o Tempo 'n': ");
                        scanf("%f", &n);
                        printf("Insira a Taxa Conhecida 'ic': ");
                        scanf("%f", &i);
                        i = pow((1 + i), (1 / n)) - 1;
                        i100 = i * 100;
                        printf("\nO valor da Nova Taxa eh: %.6f ou %.6f%%", i, i100);
                        break;

                    case 2:
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

            case 8:
                printf("\n\tOpcao Selecionada: VPL - Valor Presente Liquido.\n\n");
                float I, fc, vpl, temp;
                int vres, periodoVR;

                printf("Insira o valor do Investimento (I): ");
                scanf("%f", &I);

                printf("Insira a taxa (i): ");
                scanf("%f", &i);

                printf("Insira o Tempo (n): ");
                scanf("%f", &n);

                for (int j = 1; j <= n; j++)
                {
                    printf("Insira o Fluxo de Caixa do %d^o periodo: ", j);
                    scanf("%f", &fc);

                    temp = fc / pow((1 + i), j);
                    vpl += temp;
                }

                printf("\nTem valor residual?\n1-Sim\n2-Nao\nEscolha uma opcao: ");
                scanf("%d", &vres);

                switch (vres)
                {
                case 1:
                    printf("\nInsira o Valor Residual (VR): ");
                    scanf("%f", &VF);
                    printf("\nInsira o periodo do valor residual: ");
                    scanf("%d", &periodoVR);

                    VF = VF / pow((i + 1), periodoVR);

                    vpl = (vpl + VF) - I;

                    printf("\n-----------------");
                    printf("\nVPL = R$%.2f", vpl);
                    printf("\n-----------------");
                    break;

                case 2:
                    vpl = (vpl + 0) - I;

                    printf("\n-----------------");
                    printf("\nVPL = R$%.2f", vpl);
                    printf("\n-----------------");
                    break;
                }

                if (vpl < 0)
                    printf("\nVPL negativo, deve recusar!");
                else if (vpl > 0)
                    printf("\nVPL positivo, deve aceitar!");

                break;

            case 9:
                printf("\n\tOpcao Selecionada: Cálculos Adicionais.\n");
                printf("Escolha o tipo de cálculo:\n");
                printf("1 - Calcular Juros\n");
                printf("2 - Calcular Valor Presente\n");
                printf("3 - Calcular Valor Futuro\n");
                printf("4 - Calcular Taxa\n");
                printf("5 - Calcular Tempo\n");
                printf("6 - Converter Taxa para Capitalização Simples\n");
                printf("7 - Converter Taxa para Capitalização Composta\n");
                printf("0 - Voltar para o Menu Principal\n");

                printf("\nSelecione uma opcao: ");
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    printf("\nOpcao selecionada: Calcular Juros.\n");
                    printf("Insira o Valor Presente (VP): ");
                    scanf("%f", &VP);
                    printf("Insira o Valor Futuro (VF): ");
                    scanf("%f", &VF);
                    printf("Insira o Tempo (n): ");
                    scanf("%f", &n);

                    J = VF - VP;

                    printf("\nO valor dos Juros eh: R$%.2f", J);
                    break;

                case 2:
                    printf("\nOpcao selecionada: Calcular Valor Presente.\n");
                    printf("Insira o Valor Futuro (VF): ");
                    scanf("%f", &VF);
                    printf("Insira a Taxa Unitaria (i): ");
                    scanf("%f", &i);
                    printf("Insira o Tempo (n): ");
                    scanf("%f", &n);

                    VP = VF / pow((1 + i), n);

                    printf("\nO valor presente eh: R$%.2f", VP);
                    break;

                case 3:
                    printf("\nOpcao selecionada: Calcular Valor Futuro.\n");
                    printf("Insira o Valor Presente (VP): ");
                    scanf("%f", &VP);
                    printf("Insira a Taxa Unitaria (i): ");
                    scanf("%f", &i);
                    printf("Insira o Tempo (n): ");
                    scanf("%f", &n);

                    VF = VP * pow((1 + i), n);

                    printf("\nO valor futuro eh: R$%.2f", VF);
                    break;

                case 4:
                    printf("\nOpcao selecionada: Calcular Taxa.\n");
                    printf("Insira o Valor Presente (VP): ");
                    scanf("%f", &VP);
                    printf("Insira o Valor Futuro (VF): ");
                    scanf("%f", &VF);
                    printf("Insira o Tempo (n): ");
                    scanf("%f", &n);

                    i = pow(VF / VP, 1 / n) - 1;

                    printf("\nA taxa eh: %.6f", i);
                    break;

                case 5:
                    printf("\nOpcao selecionada: Calcular Tempo.\n");
                    printf("Insira o Valor Presente (VP): ");
                    scanf("%f", &VP);
                    printf("Insira o Valor Futuro (VF): ");
                    scanf("%f", &VF);
                    printf("Insira a Taxa Unitaria (i): ");
                    scanf("%f", &i);

                    n = log(VF / VP) / log(1 + i);

                    printf("\nO tempo eh: %.6f", n);
                    break;

                case 6:
                    printf("\nOpcao selecionada: Converter Taxa para Capitalização Simples.\n");
                    printf("Insira a Taxa Nominal (i): ");
                    scanf("%f", &i);

                    // Não é necessário fazer nada, pois i já representa a taxa em capitalização simples.
                    printf("\nA taxa em capitalizacao simples eh: %.6f", i);
                    break;

                case 7:
                    printf("\nOpcao selecionada: Converter Taxa para Capitalização Composta.\n");
                    printf("Insira a Taxa Nominal (i): ");
                    scanf("%f", &i);
                    printf("Insira o número de conversões por período (k): ");
                    scanf("%f", &n);

                    i = converteParaEfetiva(i, n);

                    printf("\nA taxa em capitalizacao composta eh: %.6f", i);
                    break;

                case 0:
                    printf("\nVoltando para o Menu Principal...\n");
                    break;

                default:
                    printf("\nOpcao invalida!");
                }
                break;

            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("\nOpcao invalida!");
            }
        }
        while (op != 0)
            ;

        return 0;
    }
