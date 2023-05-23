#include <stdio.h>
#include "TAB/TAB.c"

TAB* copia (TAB *a)
{
  if (!a)
    return a;
  return TAB_cria(a->info,copia(a->esq),copia(a->dir));
}

int main()
{
  TAB *a, *cop;

  int x1 = 10, x2=4, x3=16;
  a = TAB_cria(x1,TAB_cria(x2,NULL,NULL),TAB_cria(x3,NULL,NULL));

  cop = copia(a);
  TAB_imp_ident(cop);

  TAB_libera(a);
  TAB_libera(cop);

  return 0;
}