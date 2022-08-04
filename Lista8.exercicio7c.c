#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i,nCidades,cont=0,soma=0,percurso,percursoAntigo;
    int distancias[5][5]={{00,15,30,05,12},{15,00,10,17,28},{30,10,00,03,11},{05,17,03,00,80},{12,28,11,80,00}};

    printf("Digite por quantas cidades quieres passar: ");
    scanf("%d", &nCidades);
    printf("\nDigite qual o percurso de cidades quieres fazer: ");
    printf("\n(Suas opcoes sao: 1,2,3,4,5) \n");

    while (nCidades>cont)
    {
        scanf("%d", &percurso);
        if (cont>0)
        {
            soma+=distancias[percursoAntigo-1][percurso-1];
        }
        percursoAntigo=percurso;
        cont++;
        if (((1<=percurso) && (percurso<=5))
        {
            continue;
        }
        else
        {
            break;
        }
    }

    if ((1<=percurso) && (percurso<=5))
        printf("A distancia do percurso eh: %d", soma);
    else
        printf("Erro! Percurso nao encontrado!\n");


}
