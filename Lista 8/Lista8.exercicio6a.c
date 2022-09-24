#include <stdio.h>

void main()
{
    int tabuleiro[8][8]={{1,3,0,5,4,0,2,1},{1,0,1,0,0,1,0,0},{0,0,0,0,1,0,6,0},{1,0,0,1,1,0,0,1},{0,1,0,4,0,0,1,0},{0,0,3,1,0,0,1,1},{1,0,6,6,0,0,1,0},{1,0,5,0,1,1,0,6}};
    int i,j,contPeoes=0,contBispos=0,contAusencia=0;

    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            if (tabuleiro[i][j]==0)
            {
                contAusencia++;
                continue;
            }
            if (tabuleiro[i][j]==1)
            {
                contPeoes++;
                continue;
            }
            if (tabuleiro[i][j]==3)
            {
                contBispos++;
                continue;
            }
        }
    }

    printf("Tem %d peoes no tabuleiro\n", contPeoes);
    printf("Tem %d bispos no tabuleiro\n", contBispos);
    printf("Tem %d espacos sem peca no tabuleiro\n", contAusencia);
}
