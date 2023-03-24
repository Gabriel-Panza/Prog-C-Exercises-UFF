#include <stdio.h>

int main()
{
	int s;
    int m, h;

	printf("Type how many seconds: \n");
	scanf_s("%d", &s);

	m = s / 60;
	h = m / 60;

	while (s >= 60)
	{
		s -= 60;
	}
	while (m >= 60)
	{
		m -= 60;
	}

	printf("%d hours ", h);
	printf("%d minutes ", m);
	printf("%d seconds ", s);

	return 0;
}
