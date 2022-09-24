#include <stdio.h>
#define PI 3.14159265

void calc_circulo (float r, float *p, float *a)
{
     *p = 2 * PI * r;
     *a = PI * r * r;
}
int main() {
 float r, p, a;
 scanf ("%f", &r);
 calc_circulo (r, &p, &a);
 printf ("raio = %f, perimetro = %f, area = %f\n", r, p, a);
 return 0;
} 

