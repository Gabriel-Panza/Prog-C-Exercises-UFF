#include<stdio.h>

void main()
{
    int H1, M1, H2, M2, HF, MF;
    do
    {
        printf("\nType what time is it now and what time the alarm will ring, in hours and minutes (separated by blank spaces): ");
        scanf("%d %d %d %d", &H1, &M1, &H2, &M2);
        if ((H1<0 && H1>23) && (M1<0 && M1>59) && (H2<0 && H2>23) && (M2<0 && M2>59))
        {
            break;
        }
        HF= (H2-H1);
        if (M1>M2)
        {
            M2 += 60;
            HF-= 1;
            MF= (M2-M1);
        }
        else
            MF= (M2-M1);
        HF *= 60;
        printf("%d", HF+MF);
    } while (1);
}