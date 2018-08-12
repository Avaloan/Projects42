#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i = 0;
	char *str = malloc(500);
	while (i < 100000000)
	{
		str += i;
		i++;
	}
}
