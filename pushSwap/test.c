#include <stdio.h>

int main()
{
	int a = 5;
	int *ptr_a = &a;
	int b = 8;
	int *ptr_b = ptr_a;

	printf("&a = %p | ptr_a = %p | ptr_b = %p\n", &a, ptr_a, ptr_b);
	ptr_a = &b;
	printf("&a = %p | ptr_a = %p | ptr_b = %p\n", &a, ptr_a, ptr_b);
}
