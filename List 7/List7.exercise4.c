#include <stdio.h>
#include <stdlib.h>

int fill(char *vect, int n)
{
    int i;
    char ini = 'a';
    for (i=0;i<=n;i++)
    {
        vect[i]= ini;
        ini++;
    }
}
void print (char *vect, int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%c ", vect[i]);
}
void main()
{
    int size = 26;
    char *alphabet = (char *) malloc (size*sizeof(char));
    if (alphabet==NULL)
    {
        exit(1);
    }
    fill(alphabet,size);
    print(alphabet,size);
}
