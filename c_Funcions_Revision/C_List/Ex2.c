#include<stdio.h>
#include<stdlib.h>

void calc_integral(int* p, int* it, int tamPol)
{
    for (int i=0;i<tamPol;i++)
    {
        it[i] = p[i]/(i+1);
    }
}
void calc_derivative(int* p, int* dv, int tamPol)
{
    for (int i=0;i<tamPol;i++)
    {
        dv[i] = p[i]*i;
    }
}
void print_integral(int* it, int tamIt)
{
    printf("\nThe coefficient of the integral of the polynomial are: ");
    for (int i=0;i<tamIt;i++)
    {
        if (i==0)
            printf("%d ", 0);
        else
            printf("%d ", it[i-1]);
    }
}
void print_derivative(int* dv, int tamDv)
{
    printf("\nThe coefficient of the derivative of the polynomial are: ");
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
        printf("\nType the degree of the polynomial: ");
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
            printf("\nType the coefficient degree %d of the polynomial: ", i);
            scanf("%d", &p[i]);
        }

        /* Letra a */
        printf("The coefficient of higher degree of the polynomial is %d", p[grau]);

        /* Letra b */
        calc_integral(p, it, tamPol);
        calc_derivative(p, dv, tamPol);

        /* Letra c */
        print_integral(it, tamIt);
        print_derivative(dv, tamDv);
    } while (1);
}