#include <stdio.h>
#include <stdlib.h>

int main()
{
    int op;
    float i, i100, n, ic, ik, k;

    do{
        printf("\t\tMenu Conversao de Taxas: ");
        printf("\n1- Calcular Maior para Menor (i = (1+i)^(1/n)):");
        printf("\n2- Calcular Menor para Maior (i = (1+i)^(n)):");
        printf("\n3- Calcular Taxa Efetiva (i = ik/k):");
        printf("\nSelecione a opcao: ");
        scanf("%d", &op);

        switch(op){
        case 1:
            printf("\nOpcao selecionada: i = (1+i)^(1/12)-1\n");
            printf("Insira o Tempo 'n': ");
            scanf("%f", &n);
            printf("Insira a Taxa Conhecida 'ic': ");
            scanf("%f", &ic);
            i = pow((1+(ic/100)),(1/n))-1;
        
            i100 = i*100;
      
            printf("\nO valor da Nova Taxa eh: %.6f ou %.6f%%", i, i100);
            printf("\n------------------------------------------------");
            break;

        case 2:
            printf("\nOpcao selecionada: i = (1+i)^(n)\n");
            printf("Insira o Tempo 'n': ");
            scanf("%f", &n);
            printf("Insira a Taxa Conhecida 'ic': ");
            scanf("%f", &ic);
            i = pow((1+(ic/100)),(n))-1;
            i100 = i*100;
           
            printf("\nO valor da Nova Taxa eh: %.6f ou %.6f%%.", i, i100);
            printf("\n------------------------------------------------");
            break;

        case 3:
            printf("\nOpcao selecionada: i = ik/k");
            printf("\nInsira a Taxa Nominal (ik): ");
            scanf("%f", &ik);
            printf("Insira o periodo (k): ");
            scanf("%f", &k);
            i = ik/k;

            printf("\nA taxa efetiva eh: %.6f.", i);
            printf("\n------------------------------------------------");
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
