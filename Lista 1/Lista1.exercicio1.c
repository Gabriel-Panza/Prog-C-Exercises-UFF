#include <stdio.h>

int main()
{
	int s;
    int m, h;

	printf("Digite quantos segundos: \n");
	scanf_s("%d", &s);

    //Pegando os minutos e as horas//
	m = s / 60;
	h = m / 60;

    //Subatraindo os segundos e os minutos ao completar 60//
	while (s >= 60)
	{
		s -= 60;
	}
	while (m >= 60)
	{
		m -= 60;
	}

	printf("%d horas ", h);
	printf("%d minutos ", m);
	printf("%d segundos ", s);

	return 0;
}
