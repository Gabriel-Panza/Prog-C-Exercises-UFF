#include <stdio.h>
#define PI 3.14159265

void calc_circle (float r, float *p, float *a)
{
     *p = 2 * PI * r;
     *a = PI * r * r;
}
int main() {
 float r, p, a;
 scanf ("%f", &r);
 calc_circle (r, &p, &a);
 printf ("radius = %f, perimeter = %f, area = %f\n", r, p, a);
 return 0;
} 

