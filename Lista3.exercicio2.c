#include <stdio.h>

int main() {
     int i=3, j=5;
     int p,q;
     p = &i;
     q = &j;
     printf ("%d %d %d % d\n", p,p - q , **&p, 3 - p/(q) + 7);
   }