

#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 0, b = 0, c = 0, i = 0;
	for(i = 100; i <= 999; i++)
	{
		a = i / 100;
		b = i % 10;
		c = i / 10 % 10;

		if(i == pow(a, 3) + pow(b, 3) + pow(c, 3))
			printf("%d = %d^3 + %d^3 + %d^3\n", i, a, b, c);

	}
	return 0;
}
