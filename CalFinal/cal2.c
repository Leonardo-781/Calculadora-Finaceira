#include <stdio.h>
#include <math.h>

// Função para calcular a primeira fórmula: i = i / (1 - i * n)
double calcularFormula1(double i, double n) {
    if (fabs(1 - i * n) < 1e-9) {
        printf("Divisao por zero. Escolha valores diferentes.\n");
        return 0.0;
    }
    return i / (1 - i * n);
}

// Função para calcular a segunda fórmula: i = i / (1 + i * n)
double calcularFormula2(double i, double n) {
    if (fabs(1 + i * n) < 1e-9) {
        printf("Divisao por zero. Escolha valores diferentes.\n");
        return 0.0;
    }
    return i / (1 + i * n);
}

int main() {
    double i, n;
    int escolha;

    do {
        printf("Escolha uma opcao:\n");
        printf("1. Calcular i = i / (1 - i * n)\n");
        printf("2. Calcular i = i / (1 + i * n)\n");
        printf("0. Sair\n");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor de i: ");
                scanf("%lf", &i);
                printf("Digite o valor de n: ");
                scanf("%lf", &n);
                printf("Resultado: %lf\n", calcularFormula1(i, n));
                break;

            case 2:
                printf("Digite o valor de i: ");
                scanf("%lf", &i);
                printf("Digite o valor de n: ");
                scanf("%lf", &n);
                printf("Resultado: %lf\n", calcularFormula2(i, n));
                break;

            case 0:
                printf("Saindo do programa. Obrigado!\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (escolha != 0);

    return 0;
}