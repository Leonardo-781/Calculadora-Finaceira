#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int op;

    float A, N, i, n, Dc;
    float i100;

    do{
        printf("\n\n\tMenu: Desconto Comercial Composto\n\n");

        printf("1- Calcular Valor Atual (A)\n");//OK
        printf("2- Calcular Valor Nominal (N)\n");//OK
        printf("3- Calcular Desconto Comercial (Dc)\n");//OK
        printf("4- Calcular Taxa (i)\n");
        printf("5- Calcular Tempo de Antecipacao (n)\n");
        printf("0- Encerrar\n");

        printf("Selecione uma opcao: ");
        scanf("%d", &op);

        switch(op){

        case 1:
            printf("\n\tOp. Selecionada: Calcular Valor Atual (A).");
            printf("\nInsira o Valor Nominal (N): ");
            scanf("%f", &N);

            printf("Insira a Taxa Unitaria (i): ");
            scanf("%f", &i);

            printf("Insira o Tempo (n): ");
            scanf("%f", &n);

            A = (N)*pow((1-i),(n));

            printf("\n------------------------------------------------");
            printf("\nO Valor Atual eh: R$%.2f", A);
            printf("\n------------------------------------------------");
            break;

        case 2:
            printf("\n\tOp. Selecionada: Calcular Valor Nominal (N).");
            printf("\nInsira o Valor Atual (A): ");
            scanf("%f", &A);

            printf("Insira a Taxa Unitaria (i): ");
            scanf("%f", &i);

            printf("Insira o Tempo (n): ");
            scanf("%f", &n);

            N = A/(pow(1-i,n));

            printf("\n------------------------------------------------");
            printf("\nO Valor Nominal eh: R$%.2f", N);
            printf("\n------------------------------------------------");
            break;

        case 3:
            printf("\n\tOp. Selecionada: Calcular Desconto Comercial (Dc).");
            printf("\nInsira o Valor Nominal (N): ");
            scanf("%f", &N);

            printf("Insira a Taxa Unitaria (i): ");
            scanf("%f", &i);

            printf("Insira o Tempo (n): ");
            scanf("%f", &n);


            Dc = N*(1-(pow(1-i,n)));

            printf("\n------------------------------------------------");
            printf("\nO valor do Desconto Comercial eh: R$%.2f", Dc);
            printf("\n------------------------------------------------");

            break;

        case 4:

            printf("\n\tOp. Selecionada: Calcular Taxa (i).");
            printf("\nInsira o Valor Nominal (N): ");
            scanf("%f", &N);

            printf("Insira o Valor Atual (A): ");
            scanf("%f", &A);

            printf("Insira o Tempo (n): ");
            scanf("%f", &n);

            i = 1 - pow((A/N),(1/n));

            i100 = i * 100;
            printf("\n------------------------------------------------");
            printf("\nO valor da Taxa Unitaria eh: %.6f ou %.2f%%", i, i100);
            printf("\n------------------------------------------------");
            break;

        case 5:

            printf("\n\tOp. Selecionada: Calcular Tempo de Antecipacao (n).");
            printf("\nInsira o Valor Nominal (N): ");
            scanf("%f", &N);

            printf("Insira o Valor Atual (A): ");
            scanf("%f", &A);

            printf("Insira a Taxa Unitaria (i): ");
            scanf("%f", &i);


            n = (log(A/N))/(log(1-i));
         //   n = (log10(N)-log10(A))/log10(1+i);   //funciona tbm

            printf("\n------------------------------------------------");
            printf("\nO tempo eh: %f", n);
            printf("\n------------------------------------------------");
            break;

        case 0:
            printf("\n------------------------------------------------");
            printf("Encerrando...");
            printf("\n------------------------------------------------");
            break;
        default:
            printf("\nOpcao invalida!");

        }

    }while(op!=0);

    return 0;
}
