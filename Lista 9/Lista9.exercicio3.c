#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * estado[27] = {"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA","PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};

typedef struct assalariados
{
    char nome[51];
    char sexo;
    int idade;
    float salario;
    char estado[3];
} Assalariados;

Assalariados * cadastra(char *nome, char sexo, int idade, float salario, char *estado)
{
    // Letra a
    Assalariados *ficha = (Assalariados *) malloc(sizeof(Assalariados));
    if (ficha==NULL)
    {
        exit(1);
    }

    strcpy(ficha->nome, nome);
    ficha->sexo = sexo;
    ficha->idade = idade;
    ficha->salario = salario;
    strcpy(ficha->estado, estado);

    return ficha;
}
void relatorio(Assalariados ** ptr, int numAssalariados)
{
    // Letra c
    int i,j;
    int homens[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (i=0;i<numAssalariados;i++)
    {
        for (j=0;j<27;j++)
        {
            if ((ptr[i]->sexo == 'H') && (ptr[i]->salario > 1000.00))
            {
                if (ptr[i]->estado == estado[j])
                {
                    homens[j]+= 1;
                }
            }
        }
    }
    for (i=0;i<27;i++)
    {
        printf("Estado=%s com %d homens maiores de 40 anos e salario maior que R$ 1000,00\n", estado[i], homens[i]);
    }
}

void imprime(Assalariados ** ptr, int numAssalariados)
{
    // Letra b
    int i;
    for (i=0;i<numAssalariados;i++)
    {
        printf("A ficha do funcionario %d eh: ", i);
        printf("%s / ", ptr[i]->nome);
        printf("%c / ", ptr[i]->sexo);
        printf("%d / ", ptr[i]->idade);
        printf("%.2f / ", ptr[i]->salario);
        printf("%s \n", ptr[i]->estado);
    }
}

void main()
{
    Assalariados **pessoas;
    int numAssalariados=3;

    pessoas = (Assalariados **) malloc (numAssalariados *sizeof(Assalariados *));

    pessoas[0] = cadastra("Fulano de tal", 'M',45,1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M',50,2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M',42,500.00, "RS");

    imprime(pessoas, numAssalariados);
    relatorio(pessoas,numAssalariados);
}
