#include <stdio.h>

void main()
{
    int table[8][8]={{1,3,0,5,4,0,2,1},{1,0,1,0,0,1,0,0},{0,0,0,0,1,0,6,0},{1,0,0,1,1,0,0,1},{0,1,0,4,0,0,1,0},{0,0,3,1,0,0,1,1},{1,0,6,6,0,0,1,0},{1,0,5,0,1,1,0,6}};
    int i,j,contPawns=0,contBishops=0,contNoPieces=0,contHorses=0,contTowers=0,contKings=0,contQueens=0;

    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            if (table[i][j]==0)
            {
                contNoPieces++;
                continue;
            }
            if (table[i][j]==1)
            {
                contPawns++;
                continue;
            }
            if (table[i][j]==2)
            {
                contHorses++;
                continue;
            }
            if (table[i][j]==3)
            {
                contBishops++;
                continue;
            }
            if (table[i][j]==4)
            {
                contTowers++;
                continue;
            }
            if (table[i][j]==5)
            {
                contKings++;
                continue;
            }
            if (table[i][j]==6)
            {
                contQueens++;
                continue;
            }
        }
    }

    printf("There are %d pawns in the table\n", contPawns);
    printf("There are %d horses in the table\n", contHorses);
    printf("There are %d bishops in the table\n", contBishops);
    printf("There are %d towers in the table\n", contTowers);
    printf("There are %d kings in the table\n", contKings);
    printf("There are %d queens in the table\n", contQueens);
    printf("There are %d spaces without pieces in the table\n", contNoPieces);
}

