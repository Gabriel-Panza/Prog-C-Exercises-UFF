#include <stdio.h>
#include <stdlib.h>

// definindo o tipo da lista
struct LISTA {
    int info;
    struct LISTA *prox;
};
typedef struct LISTA tLista;

// funcao para o menu
void menu(){
    printf("MENU: \n");
    printf("=================================\n");
    printf("1. uniao entre conjuntos; \n");
    printf("2. diferenca entre conjuntos; \n");
    printf("3. pertinencia entre conjuntos; \n");
    printf("4. intersecao entre conjuntos; \n");
    printf("5. imprimir os conjuntos; \n");
    printf("6. sair. \n");
    printf("=================================\n");
    return;
}

// funcao para criar a lista
tLista* criaLista(){
    return NULL; // o primeiro elemento aponta para null 
}

// funcao para inserir elemento no inicio
tLista* insereElemento(tLista *lista, int elem){
    tLista *novo = (tLista*)malloc(sizeof(tLista));
    novo->info = elem;
    novo->prox = lista; // o no inserido passa a apontar para onde lista estava apontando
    return novo;
}

// funcao para inserir elemento no final
tLista* insereElementoFinal(tLista *lista, int elem){
    if(lista == NULL)
        return insereElemento(lista, elem); 

    tLista *aux = lista; // ponteiro aux para percorrer a lista
    while(aux->prox != NULL){
        aux = aux->prox; // procura o ultimo elem da lista
    }
    tLista *novo = (tLista*)malloc(sizeof(tLista));
    novo->info = elem; // lista recebe o elem 
    novo->prox = NULL; // novo passa a apontar para onde aux estava apontando (ou seja, null)
    aux->prox = novo; // aux passa a apontar para novo que esta apontando para null
    return lista;
}

// funcao que remove um elemento da lista
tLista *retira_rec(tLista *l, int elem)
{
    // CASO 1
    if(!l)  // l == NULL
        return l;
    // CASO 2
    if(l->info == elem)
        l = l->prox;
    // CASO 3
    else 
        l->prox = retira_rec(l->prox, elem);
    return l;
}

// funcao para buscar um elemento na lista
int buscaElemento(tLista *lista, int elem){
    if(lista == NULL)
        return -1;

    tLista* aux = lista;
    while(aux != NULL){
        if(aux->info == elem)
            return 1;
        aux = aux->prox;
    }
    return -1; 
}

// funcao para fazer a uniao dos conjuntos
tLista *uniao(tLista *lista1, tLista *lista2, tLista *lista3){
    if(lista1 == NULL) // se l1 tiver vazia, a uniao eh a l2
        return lista2;
    if(lista2 == NULL) // se l2 tiver vazia, a uniao eh a l1
        return lista1;

    lista3 = lista1;
    tLista *aux2;
    for(aux2 = lista2; aux2 != NULL; aux2 = aux2->prox){ // a cada iteracao adiciona o elemento de l2 em l1
        if (buscaElemento(lista1,aux2->info) == -1)
            lista3 = insereElementoFinal(lista1, aux2->info);
    }
    return lista3;
}

// funcao para fazer a diferenca das listas
tLista *diferenca(tLista *lista1, tLista *lista2, tLista *lista3){ // elementos q estao em l1 mas q nao estao em l2
    if(lista1 == NULL) // se l1 tiver vazia, a uniao eh a l2
        return lista2;
    if(lista2 == NULL) // se l2 tiver vazia, a uniao eh a l1
        return lista1;

    lista3 = lista1;
    tLista *aux2;
    for(aux2 = lista2; aux2 != NULL; aux2 = aux2->prox){ // a cada iteracao adiciona o elemento de l2 em l1
        if (buscaElemento(lista1,aux2->info) == 1)
            lista3 = retira_rec(lista1,aux2->info);
        else
            lista3 = insereElementoFinal(lista1, aux2->info);
    }
    return lista1;
}

// funcao de pertinencia entre listas
int pertinencia(tLista *lista1, int tam1, tLista *lista2, int tam2){
    // se uma das listas estiver vazia a outra lista esta contida nela pois em todo conj existe o vazio
    if(lista1 == NULL || lista2 == NULL)
        return 1; // se l1 ou l2 estiverem vazias retorna true 
    
    if (tam1<tam2)
    { 
        for(tLista *aux1 = lista1; aux1 != NULL; aux1 = aux1->prox){ // enquanto esse percorre toda a l2
            if(buscaElemento(lista2,aux1->info) == -1) // se l1->info nao estiver dentro da l2, significa que o elemento nao pertence a l2, logo nao esta contido
                return -1;
        }
    }
    else
    {
        for(tLista *aux2 = lista2; aux2 != NULL; aux2 = aux2->prox){ // enquanto esse percorre toda a l2
            if(buscaElemento(lista1,aux2->info) == -1) // se l1->info nao estiver dentro da l2, significa que o elemento nao pertence a l2, logo nao esta contido
                return -1;
        }
    }
    return 1;
}

// funcao para fazer a intersecao das listas
tLista *intersecao(tLista *lista1, tLista *lista2, tLista *lista3){
    if(lista1 == NULL || lista2 == NULL)
        return NULL; // se uma das listas forem vazias retorna null pq nao tem intersecao

    lista3 = lista1;
    tLista *aux3; // crio 2 ponteiros auxiliares p percorrer as duas listas
    for(aux3=lista3; aux3 != NULL; aux3 = aux3->prox){ // enquanto percorrre toda a lista 2 para comparar
        if(buscaElemento(lista2, aux3->info) != 1)
            lista3 = retira_rec(lista3,aux3->info);
    }
    return lista3;
}

// funcao para imprimir a lista
void imprimeLista(tLista *lista){
    tLista *aux;

    for(aux=lista; aux != NULL; aux = aux->prox){
        printf("%d -> ", aux->info);
    }
    printf("NULL \n");
}

int main(){
    tLista *L1, *L2, *L3;
    int op, x, y, i, el;

    L1 = criaLista();
    L2 = criaLista();
    L3 = criaLista();

    printf("Digite a qtd de elementos a serem inseridos em L1 e L2: \n");
    scanf("%d %d", &x, &y);

    printf("Insira os elementos de L1: \n"); // inserindo os elementos em l1
    for(i = 0; i < x; i++){
        scanf("%d", &el);
        fflush(stdin);
        L1 = insereElementoFinal(L1, el);
    }
    printf("Insira os elementos de L2: \n"); // inserindo os elementos em l2
    for(i = 0; i < y; i++){
        scanf("%d", &el);
        fflush(stdin);
        L2 = insereElementoFinal(L2, el);
    }

    do{
        menu();
        printf("Digite a operacao desejada: \n");
        scanf("%d", &op);
        fflush(stdin);

        switch(op){
            case 1:
                L3 = uniao(L1, L2, L3);
                imprimeLista(L3);
                break;
            case 2:
                L3 = diferenca(L1, L2, L3);
                imprimeLista(L3);
                break;
            case 3:
                if(pertinencia(L1,x,L2,y) == 1){
                    printf("um conjunto esta contido no outro \n");
                } else{
                    printf("um conjunto nao esta contido no outro \n");
                }
                break;
            case 4:
                L3 = intersecao(L1, L2, L3);
                imprimeLista(L3);
                break;
            case 5:
                printf("Conjunto 1: \n");
                imprimeLista(L1);
                printf("=================================\n");
                printf("Conjunto 2: \n");
                imprimeLista(L2);
                printf("=================================\n");
                printf("Conjunto 3: \n");
                imprimeLista(L3);
                printf("=================================\n");
                break;
            case 6:
                break;
            default:
                printf("Operacao invalida! \n");
                break;
        }
    } while(op!=6);

    return 0;
}
