#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void suspects(int n) {
    int x, array[n], array_copy[n];
    
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        array[i] = x;
        array_copy[i] = x;
    }
    qsort(array_copy, n, sizeof(int), cmpfunc);
    int pos = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        if(array_copy[i] != array_copy[n-1])
        {
            pos = i;
            break;
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        if(array[i] == array_copy[pos])
        {
            printf("%d\n", i+1);
            break;
        }
    }
}
int main()
{
    int n;
    while(scanf("%d", &n) && n != 0) {
        suspects(n);
    }
    return 0;
}