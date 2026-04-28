#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float fvp, i, n, pot, pmt, vp;
    float multPor;

    printf("\nInsira o numero de parcelas (n): ");
    scanf("%f", &n);
    printf("\nInsira a taxa unitaria de juros (i): ");
    scanf("%f", &i);

    //printf("\n\nMostrando valores inseridos: n=%.6f e i=%.6f", n, i);

    pot = pow((1+i),(-n));
    //printf("\nPotencia = %.6f\n", pot);

    fvp = (1-(pow((1+i),(-n))))/i;

    //fvp = (1-pot)/i;
    printf("\n\nFVP = %.6f", fvp);

    printf("\nInsira o valor presente: ");
    scanf("%f", &vp);
    pmt = vp * (1/fvp);
    printf("\nO PMT eh: %.6f", pmt);
    printf("\nMultiplicar por: ");
    scanf("%f", &multPor);
    multPor = fvp * multPor;

    printf("\nResultado: R$%.2f", multPor);
    return 0;
}
