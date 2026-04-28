#include<stdio.h>
#include<math.h>

int main()
{
    int op, n, t;
    float pmt,amort, j, sd, vp, i;

    do{
    printf("\n\tSAC - Sistema de Amortizacao Constante");
    printf("\n1- Calcular PMT");
    printf("\n2- Calcular Amortizacao");
    printf("\n3- Calcular Juros");
    printf("\n4- Calcular Saldo Devedor");
    printf("\n0- Encerrar");
    printf("\n\nInsira a opcao desejada: ");
    scanf("%d", &op);


    switch(op){
        case 1:
            printf("\nCalcular PMT");
            printf("\nInsira o Valor Presente (VP): ");
            scanf("%f", &vp);
            printf("\nInsira o numero de periodos (n): ");
            scanf("%d", &n);
            printf("\nInsira a taxa de juros (i): ");
            scanf("%f", &i);
            printf("\nInsira o numero da prestacao desejada (t): ");
            scanf("%d", &t);

            amort = vp/n;

            pmt = amort * (1+((n -t +1)*i));

            printf("\nPMT{%d} = R$%.2f", t, pmt);
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");

            printf("\n");
            printf("\n");
            break;

        case 2:
            printf("\nCalcular Amortizacao");
            printf("\nInsira o Valor Presente (VP): ");
            scanf("%f", &vp);
            printf("\nInsira o numero de periodos (n): ");
            scanf("%d", &n);

            amort = vp/n;
            printf("\n-------------------");

            printf("\nAmortizacao = R$%.2f",amort);
            printf("\n-------------------\n");
            break;

        case 3:
            printf("\nCalcular Juros");
            printf("\nInsira o Valor Presente (VP): ");
            scanf("%f", &vp);
            printf("\nInsira o numero de periodos (n): ");
            scanf("%d", &n);
            printf("\nInsira a taxa de juros (i): ");
            scanf("%f", &i);
            printf("\nInsira o numero da prestacao desejada (t): ");
            scanf("%d", &t);

            amort = vp/n;

            j = amort*(n -t +1)*i;

            printf("\nJuros{%d} = R$%.2f", t, j);


            printf("\n");
            printf("\n");
            printf("\n");

            printf("\n");
            printf("\n");
            break;

        case 4:
            printf("\nCalcular Saldo Devedor");
            printf("\nInsira o Valor Presente (VP): ");
            scanf("%f", &vp);
            printf("\nInsira o numero de periodos (n): ");
            scanf("%d", &n);

            printf("\nInsira o numero da prestacao desejada (t): ");
            scanf("%d", &t);

            amort = vp/n;

            sd = vp - (amort*t);

            printf("\nSaldo Devedor{%d} = R$%.2f", t, sd);


            printf("\n");
            printf("\n");
            break;

        case 0:
            printf("\nEncerrando...");
            break;
    }

    }while(op!=0);

    return 0;
}
