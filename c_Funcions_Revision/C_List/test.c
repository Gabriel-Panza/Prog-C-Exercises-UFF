#include <stdio.h>
#include <stdlib.h>

// defining the type of the list
typedef struct LIST {
    int info;
    struct LIST *next;
};tList

// menu function
void menu(){
    printf("MENU: \n");
    printf("=================================\n");
    printf("1. unite between lists; \n");
    printf("2. differ between lists; \n");
    printf("3. pertinence between lists; \n");
    printf("4. intersection between lists; \n");
    printf("5. print lists; \n");
    printf("6. exit. \n");
    printf("=================================\n");
    return;
}

// create a empty list function
tList* createList(){
    return NULL; 
}

// add an element at the begginning function
tList* addElement(tList *list, int elem){
    tList *novo = (tList*)malloc(sizeof(tList));
    novo->info = elem;
    novo->next = list; 
    return novo;
}

// add an element at the end function
tList* addElementFinal(tList *list, int elem){
    if(list == NULL)
        return addElement(list, elem); 

    tList *aux = list; 
    while(aux->next != NULL){
        aux = aux->next; 
    }
    tList *novo = (tList*)malloc(sizeof(tList));
    novo->info = elem; 
    novo->next = NULL; 
    aux->next = novo; 
    return list;
}

// remove an element function
tList *remove_rec(tList *l, int elem)
{
    // CASE 1
    if(!l)  // l == NULL
        return l;
    // CASE 2
    if(l->info == elem)
        l = l->next;
    // CASE 3
    else 
        l->next = remove_rec(l->next, elem);
    return l;
}

// search for an element function
int searchElement(tList *list, int elem){
    if(list == NULL)
        return -1;

    tList* aux = list;
    while(aux != NULL){
        if(aux->info == elem)
            return 1;
        aux = aux->next;
    }
    return -1; 
}

// unite lists function
tList *unite(tList *list1, tList *list2, tList *list3){
    if(list1 == NULL) 
        return list2;
    if(list2 == NULL) 
        return list1;

    list3 = list1;
    tList *aux2;
    for(aux2 = list2; aux2 != NULL; aux2 = aux2->next){ 
        if (searchElement(list1,aux2->info) == -1)
            list3 = addElementFinal(list1, aux2->info);
    }
    return list3;
}

// differ lists function
tList *differ(tList *list1, tList *list2, tList *list3){
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;

    list3 = list1;
    tList *aux2;
    for(aux2 = list2; aux2 != NULL; aux2 = aux2->next){
        if (searchElement(list1,aux2->info) == 1)
            list3 = remove_rec(list1,aux2->info);
        else
            list3 = addElementFinal(list1, aux2->info);
    }
    return list1;
}

// pertinence of lists function
int pertinence(tList *list1, int size1, tList *list2, int size2){
    if(list1 == NULL || list2 == NULL)
        return 1; 
    
    if (size1<size2)
    { 
        for(tList *aux1 = list1; aux1 != NULL; aux1 = aux1->next){ 
            if(searchElement(list2,aux1->info) == -1) 
                return -1;
        }
    }
    else
    {
        for(tList *aux2 = list2; aux2 != NULL; aux2 = aux2->next){ 
            if(searchElement(list1,aux2->info) == -1) 
                return -1;
        }
    }
    return 1;
}

// intersection of lists function
tList *intersection(tList *list1, tList *list2, tList *list3){
    if(list1 == NULL || list2 == NULL)
        return NULL; 

    list3 = list1;
    tList *aux3; 
    for(aux3=list3; aux3 != NULL; aux3 = aux3->next){ 
        if(searchElement(list2, aux3->info) != 1)
            list3 = remove_rec(list3,aux3->info);
    }
    return list3;
}

// print function
void printList(tList *list){
    tList *aux;

    for(aux=list; aux != NULL; aux = aux->next){
        printf("%d -> ", aux->info);
    }
    printf("NULL \n");
}

// main function
int main(){
    tList *L1, *L2, *L3;
    int op, x, y, i, el;

    L1 = createList();
    L2 = createList();
    L3 = createList();

    printf("Type the quantity of elements you want to add inside L1 and L2: \n");
    scanf("%d %d", &x, &y);

    printf("Type the elements of L1: \n"); 
    for(i = 0; i < x; i++){
        scanf("%d", &el);
        fflush(stdin);
        L1 = addElementFinal(L1, el);
    }
    printf("Type the elements of L2: \n"); 
    for(i = 0; i < y; i++){
        scanf("%d", &el);
        fflush(stdin);
        L2 = addElementFinal(L2, el);
    }

    do{
        menu();
        printf("Type the operation wanted: \n");
        scanf("%d", &op);
        fflush(stdin);

        switch(op){
            case 1:
                L3 = unite(L1, L2, L3);
                printList(L3);
                break;
            case 2:
                L3 = differ(L1, L2, L3);
                printList(L3);
                break;
            case 3:
                if(pertinence(L1,x,L2,y) == 1){
                    printf("the list is contained in the other list\n");
                } else{
                    printf("the list is not contained in the other list\n");
                }
                break;
            case 4:
                L3 = intersection(L1, L2, L3);
                printList(L3);
                break;
            case 5:
                printf("List 1: \n");
                printList(L1);
                printf("=================================\n");
                printf("List 2: \n");
                printList(L2);
                printf("=================================\n");
                printf("List 3: \n");
                printList(L3);
                printf("=================================\n");
                break;
            case 6:
                break;
            default:
                printf("Invalid Operation! \n");
                break;
        }
    } while(op!=6);

    return 0;
}
