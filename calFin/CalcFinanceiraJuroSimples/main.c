#include <stdio.h>
#include <stdlib.h>

int main()
{
    int op;

    float VP, VF, i, n, J;
    float i100;

    do{
        printf("\n\n\tMenu: Juros Simples\n\n");

        printf("1- Calcular Capital (VP)\n");
        printf("2- Calcular Montante (VF)\n");
        printf("3- Calcular Juros (J)\n");
        printf("4- Calcular Taxa (i)\n");
        printf("5- Calcular Tempo (n)\n");
        printf("0- Encerrar\n");

        printf("Selecione uma opcao: ");
        scanf("%d", &op);

        switch(op){

        case 1:
            printf("\n\tOp. Selecionada: Calcular Capital (VP).");
            printf("\nInsira o Valor Futuro (VF): ");
            scanf("%f", &VF);

            printf("Insira a Taxa Unitaria (i): ");
            scanf("%f", &i);

            printf("Insira o Tempo (n): ");
            scanf("%f", &n);


            VP = (VF)/(1+(i*n));

            printf("\nO valor presente eh: R$%.2f", VP);
            break;

        case 2:
            printf("\n\tOp. Selecionada: Calcular Montante (VF).");
            printf("\nInsira o Valor Presente (VP): ");
            scanf("%f", &VP);

            printf("Insira a Taxa Unitaria (i): ");
            scanf("%f", &i);

            printf("Insira o Tempo (n): ");
            scanf("%f", &n);


            VF = (VP)*(1+(i*n));

            printf("\nO valor futuro eh: R$%.2f", VF);
            break;

        case 3:
            printf("\n\tOp. Selecionada: Calcular Juros (J).");
            printf("\nInsira o Valor Presente (VP): ");
            scanf("%f", &VP);

            printf("Insira a Taxa Unitaria (i): ");
            scanf("%f", &i);

            printf("Insira o Tempo (n): ");
            scanf("%f", &n);

            J = (VP*i*n);

            printf("\nO valor dos juros eh: R$%.2f", J);
            break;

        case 4:

            printf("\n\tOp. Selecionada: Calcular Taxa (i).");
            printf("\nInsira o Valor Presente (VP): ");
            scanf("%f", &VP);

            printf("Insira o Valor Futuro (VF): ");
            scanf("%f", &VF);

            printf("Insira o Tempo (n): ");
            scanf("%f", &n);

            i = ((VF/VP)-1)/n;
            i100 = i * 100;

            printf("\nO valor da Taxa Unitaria eh: %f ou %f%%", i, i100);
            break;

        case 5:

            printf("\n\tOp. Selecionada: Calcular Tempo (n).");
            printf("\nInsira o Valor Presente (VP): ");
            scanf("%f", &VP);

            printf("Insira o Valor Futuro (VF): ");
            scanf("%f", &VF);

            printf("Insira a Taxa Unitaria (i): ");
            scanf("%f", &i);

            n = ((VF/VP)-1)/i;
            i100 = i * 100;

            printf("\nO tempo eh: %f", n);
            break;

        case 0:
            printf("Encerrando...");
            break;

        default:
            printf("\nOpcao invalida!");

        }

    }while(op!=0);

    return 0;
}
