#include <stdio.h>

void hanoiTower(int n, char from, char by, char to)
{
	if (n == 1)
	{
		printf("%d��° ������ %c���� %c�� �ű⼼��\n", n, from, to);
	}
	else
	{
		hanoiTower(n - 1, from, to, by);
		printf("%d��° ������ %c���� %c�� �ű⼼��\n", n, from, to);
		hanoiTower(n - 1, by, from, to);
	}
}


int main()
{
	hanoiTower(4, 'A', 'B', 'C'	);

	return 0;
}