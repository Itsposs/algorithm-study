
#include <stdio.h>


int main(int argc, char *argv[])
{
	int n, m;
	scanf("%d", &n);
	m = (n % 10) * 100 + (n / 10 % 10) * 10 + (n / 100);
	printf("%03d\n", m);
	//printf("%d%d%d\n", n % 10, n / 10 % 10, n / 100);

	return 0;
}
