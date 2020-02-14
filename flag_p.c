//#include "ft_printf.h"
#include <stdio.h>

char hex_digit(int n)
{
	return (0 <= n && n <= 9) ? ('0' + n) : ('a' + n - 10);
}

int	print_address(void *p0)
{
	int i;
	int nb;
	unsigned long p;

	p = (unsigned long)p0;
	nb = write(1, "0x", 2);
	i = (sizeof(p) << 3) - 20;
	while(i >= 0)
	{
		nb += ft_putchar(hex_digit((p >> i) & 0xf));
		i -= 4;
	}
	return (nb);
}

int main()
{
	//char *p = "hello";
	int p = 3333;
	int *pp = &p;
	int **ppp = &pp;
	print_address_hex((void*)*ppp);
	printf("\n%p\n", (void*)*ppp);
}
