#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int dia, mes, ano;               /* dia, mes e ano do nascimento */
} Data;

typedef struct local {
    char ender[81];              /* endereco do local de provas */
    int sala;                   /* numero da sala */
} Local;

typedef struct notas {
    float geral;             /* prova de conhecimentos gerais */
    float especifica;       /* prova de conhecimentos especificos */
} Notas;

typedef struct candidato {
    int inscr;                      /* numero de inscricao */
    char nome[81];                 /* nome do candidato */
    Data nasc;                    /* data de nascimento */
    Local *loc;                   /* local de prova */
    Notas nt;                   /* notas de prova */
} Candidato;

void main()
{
    int i,n,cand,opcao;

    printf("Quantos candidatos estao presentes? \n");
    scanf("%d", &n);

    Candidato *curriculo = (Candidato *) malloc(n*sizeof(Candidato));
    if (curriculo==NULL)
    {
        exit(1);
    }
    for (i=0;i<n;i++)
    {
        curriculo->nome[i]=NULL;
    }

    Local *loc = (Local *) malloc(n*sizeof(Local));
    if (loc==NULL)
    {
        exit(1);
    }

    fflush(stdin);
    do
    {
        //Letra b
        printf("Digite qual opcao voce quer: (0)-Finaliza o programa, (1)-Leitura de dados, (2)-Impressao dos dados, (3)-Alteracao do local da prova de um candidato especifico\n");
        scanf("%d", &opcao);
        fflush(stdin);
        if(opcao==1)
        {
            for (i=0;i<n;i++)
            {
                curriculo[i].inscr = i;
                printf("\nCandidato %d: ", curriculo[i].inscr);
                gets(curriculo[i].nome);

                Data nasc;
                printf("\nDigite a data de nascimento do candidato: ");
                scanf("%d %d %d", &nasc.dia,&nasc.mes,&nasc.ano);
                fflush(stdin);
                curriculo[i].nasc = nasc;

                printf("\nDigite o local: ");
                gets(loc[i].ender);
                printf("Digite a sala da prova: ");
                scanf("%d", &loc[i].sala);
                fflush(stdin);
                curriculo[i].loc = &loc[i];

                Notas nt;
                printf("\nDigite a nota geral e a nota especifica: ");
                scanf("%f %f", &nt.geral, &nt.especifica);
                fflush(stdin);
                curriculo[i].nt = nt;
            }
        }

        if (opcao==2)
        {
            if (curriculo->nome[0]==NULL)
            {
                printf("Nao possui nenhum cadastro!\n");
            }
            else
            {
                for (i=0;i<n;i++)
                {
                    //Letra a
                    printf("\nInscricao %d: %s", curriculo[i].inscr,curriculo[i].nome);
                    printf("\nNascimento: %d %d %d", curriculo[i].nasc.dia, curriculo[i].nasc.mes, curriculo[i].nasc.ano);
                    printf("\nLocal: %s %d", curriculo[i].loc->ender, curriculo[i].loc->sala);
                    printf("\nNotas: %f %f", curriculo[i].nt.geral,curriculo[i].nt.especifica);
                }
            }
        }

        // Letra c
        if(opcao==3)
        {
            printf("Digite qual candidato voce quer alterar o endereco e sala da prova: ");
            scanf("%d", &cand);
            fflush(stdin);
            gets(loc[cand].ender);
            scanf("%d", &loc[cand].sala);
            fflush(stdin);
            curriculo[i].loc = &loc[i];
        }
    }while (opcao!=0);

    free(curriculo);
    free(loc);
}
