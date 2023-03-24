#include <stdio.h>

void f1 ( int v)
{
    v = v + 1;
    printf (" f1 = %d\n " , v );
}
void f2 ( int *v)
{
    *v = *v + 1;
    printf (" f2 = %d\n " , *v );
}
int f3 ( int v)
{
    v = v + 1;
    printf (" f3 = %d\n " , v );
    return v;
}
int main (void)
{
    int v = 1;
    f1 ( v ); 
    f2 (&v );
    v = f3 ( v );
    printf (" main = %d \n" , v );
    return 0;
}
