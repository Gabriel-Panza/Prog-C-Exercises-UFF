#include <stdio.h>

float *acima_da_media(int n, float *vet, int *tam)
{
    int i,soma=0,cont=0,contVet=0;
    float *tempVet;
    float media;

    for (i=0;i<n;i++)
    {
        soma += vet[i];
    }
    media = soma/n;

    for (i=0;i<n;i++)
    {
        if(vet[i]>media)
        {
            cont++;
        }
    }

    *tam=cont;
    tempVet = (float *)malloc((*tam)*sizeof(float));
    if (tempVet==NULL)
        exit(1);

    for (i=0;i<n;i++)
    {
        if(vet[i]>media)
        {
            tempVet[contVet] = vet[i];
            contVet++;
        }
    }
    return tempVet;
}

void main()
{
    int i, n;
    float *v;
    int pInt;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    v = (float *) malloc(n*sizeof(float));
    if (v==NULL)
        exit(1);

    for (i=0;i<n;i++)
    {
        printf("Digite o valor %d do vetor: ", i);
        scanf("%f", &v[i]);
    }

    float *acimDaMedia = acima_da_media(n,v,&pInt);

    printf("O vetor final eh: ");
    for (i=0;i<pInt;i++)
        printf("%d ", acimDaMedia[i]);

    free(v);
    free(acimDaMedia);
}
