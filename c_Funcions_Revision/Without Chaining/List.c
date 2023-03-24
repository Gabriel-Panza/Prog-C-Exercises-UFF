#include<stdio.h>

typedef struct LIST 
{
    int *data;
    int total;
}List;

List initialize(List *l, int size)
{
    int* dadoAux = (int*) malloc(size * sizeof(int));
    l->data = dadoAux;
    return l;
}

void push (List *L, int elem, int size)
{
    if (L->total<size)
    {
        L->data[L->total] = elem;
        L->total++;
    }
    else
    {
        printf("Error! List is full!");
    }
}

int search (List *L, int elem, int *pos)
{
    if (L->total>0)
    {
        while (*pos<L->total && L->data[*pos] != elem)
        {
            *pos+=1;
        }
        
        if (*pos<L->total)
        {
            printf("\nFound element!!\n")
            return L->data[*pos];
        }
        printf("\nElement not found for search\n");
        return -1;
    }
    printf("\nElement not found for search, bcs list is empty\n");
    return -1;
}

int binary_search(List *L, int elem, int start, int end)
{
    int middle = (start+end)/2;
    if (L->data[start] == elem) 
    {
        printf("Found element!");
        return start;
    }
    if (L->data[end] == elem)
    {            
        printf("Found element!");
        return end;
    }

    if (start != middle && end != middle)
    {
        if (L->data[middle] == elem)
            printf("Found element!");
            return middle;
        if (L->data[middle] < elem)
        {
            start = middle;
            binary_search(L, elem, start, end);
        }
        if (L->data[middle] > elem)
        {
            end = middle;
            binary_search(L, elem, start, end);
        }
    }
    printf("Element not found!!!");
    return -1;
}

void pop (List *L, int elem)
{
    int pos=0;
    if (search(L,elem,&pos) != -1)
    {
        for (int i=pos;i<(L->total-1);i++)
        {
            L->data[i] = L->data[i+1];
        }
        L->total -= 1;
    }
}

void print(List *L)
{
    for (int i = 0; i<L->total; i++)
    {
        printf("%d,", L->data[i]);
    }
    printf("\n");
}

void order(List *L)
{
    for(int i = 0; i<L->total; i++)
    {
        for(int j = 0; j<(L->total-1); j++)
        {
            if (L->data[j] > L->data[j+1])  
            {  
                int aux = L->data[j];
                L->data[j] = L->data[j+1];
                L->data[j+1] = aux;
            }
        }
    }
}

int main()
{
    List L = initialize(L,size);
    int size;
    scanf("%d", &size);
    
    L.total=0;
    int elem, pos = 0;

    for (int i=0;i<size;i++)
    {
        scanf("%d", &elem)
        push (&L, elem, size);
    }

    pos = search (&L, elem, &pos);
    print(&L);

    pos = binary_search (&L, elem, 0, L.total-1);
    print(&L);

    return 0;
}