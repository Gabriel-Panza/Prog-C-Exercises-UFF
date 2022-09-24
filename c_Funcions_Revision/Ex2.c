#include<stdio.h>
#include<stdlib.h>

void calcula_integral(int* p, int* it, int tamPol)
{
    for (int i=0;i<tamPol;i++)
    {
        it[i] = p[i]/(i+1);
    }
}
void calcula_derivada(int* p, int* dv, int tamPol)
{
    for (int i=0;i<tamPol;i++)
    {
        dv[i] = p[i]*i;
    }
}
void printa_integral(int* it, int tamIt)
{
    printf("\nOs coeficientes da integral do polinomio sao: ");
    for (int i=0;i<tamIt;i++)
    {
        if (i==0)
            printf("%d ", 0);
        else
            printf("%d ", it[i-1]);
    }
}
void printa_derivada(int* dv, int tamDv)
{
    printf("\nOs coeficientes da derivada do polinomio sao: ");
    for (int i=1;i<tamDv+1;i++)
    {
        printf("%d ", dv[i]);
    }
}
void main()
{
    int i, grau, tamPol, tamIt, tamDv;
    do
    {
        printf("\nDiga o grau do polinomio: ");
        scanf("%d", &grau);
        if (grau<=0)
            break;
        
        // Definimos os tamanhos dos polinomios com base no maior coeficiente
        tamPol = grau+1;
        int *p = (int*) malloc(tamPol * sizeof(int));
        if (p==NULL)
            exit(1);

        tamIt = grau+2;
        int *it = (int*) malloc(tamIt * sizeof(int));
        if (it==NULL)
            exit(1);

        tamDv = grau;
        int *dv = (int*) malloc(tamDv * sizeof(int));
        if (dv==NULL)
            exit(1);
        
        for (i=0;i<grau+1;i++)
        {
            printf("\nDigite o coeficiente de grau %d do polinomio: ", i);
            scanf("%d", &p[i]);
        }

        /* Letra a */
        printf("O coeficiente de maior grau do polinomio eh o: %d", p[grau]);

        /* Letra b */
        calcula_integral(p, it, tamPol);
        calcula_derivada(p, dv, tamPol);

        /* Letra c */
        printa_integral(it, tamIt);
        printa_derivada(dv, tamDv);
    } while (1);
}