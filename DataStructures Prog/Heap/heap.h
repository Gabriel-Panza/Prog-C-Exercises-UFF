#include <stdio.h>
#include <stdlib.h>

int esq(int ind);
int dir(int ind);
int pai(int ind);

void min_heapfy(int *vet, int n, int ind);
void max_heapfy(int *vet, int n, int ind);
void build_min_heap(int *v, int n);
void build_max_heap(int *v, int n);
void heapsort(int *v, int n);