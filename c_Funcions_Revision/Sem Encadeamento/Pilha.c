#define MAX 100;

typedef struct PILHA {
 int dado[MAX];
 int indiceTopo;
}pilha; 

void push(pilha *P, int num)
{
    if (P->indiceTopo < MAX-1) 
    {
        P->indiceTopo++'''''''''''''';
        P->dado[P->indiceTopo] = num;
    }
    else
    {
        printf("Pilha cheia!");
    }
}

int pop(pilha *P)
{
    int num;
    if(P->indiceTopo>=0)
    {
        num = P->dado[P->indiceTopo];
        P->indiceTopo--;
    }
    return num;
}

void libera(pilha *p)
{
    if (p->indiceTopo>=0)
    {
        free(p->dado);
        p->indiceTopo=-1;
    }
}

int main()
{
    pilha p;
    p->indiceTopo = -1;

    push(&p,17);
    pop(&p);
    libera(&p);
    
    return 0;
}