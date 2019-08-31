

#include <stdio.h>


int main(int argc, char *argv[])
{
	int a, b, c, i;
	int flag = 0;
	while(scanf("%d%d%d", &a, &b, &c) == 3)
	{
		if(!(a < 3 && b < 5 && c < 7))
			return;
		for(i = 10; i <= 100; i++)
		{
			if(i % 3 == a && i % 5 == b && i % 7 == c)
			{
				flag = 1;
				printf("%d\n", i);
			}
		}
		if(!flag)
			printf("No answer\n");
	}
	return 0;
}
