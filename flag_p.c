/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:31:57 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/15 18:58:46 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_digit(int n)
{
	return (0 <= n && n <= 9) ? ('0' + n) : ('a' + n - 10);
}

int		ft_pwidth(t_flags x, int a)
{
	int     dif;
	int sum;
	int	i;

	i = 0;
	while (a -= 4 >= 0)
		i++;
	dif = x.width - (i + x.precision);
	sum = dif;
	while (dif-- > 0)
		ft_putchar((x.zero && !x.minus && !x.precision) ? '0' : ' ');
	return ((sum > 0) ? sum : 0);
}

int		ft_pprecision(t_flags x, int a)
{
	int dif;
	int sum;
	int i;

	i = 0;
	while (a -= 4 >= 0)
		i++;
	dif = x.precision - i;
	sum = dif;
	while (dif-- > 0)
		ft_putchar('0');
	return ((sum > 0) ? sum : 0);
}

int		print_address(t_flags x, void *p0)
{
	int				i;
	int				nb;
	int				a;
	unsigned long	p;

	p = (unsigned long)p0;
	nb = write(1, "0x", 2);
	i = (sizeof(p) << 3) - 20;
	a = i;
	if (!x.minus)
		nb += ft_pwidth(x, a);
	if (x.precision)
		nb += ft_pprecision(x, a);
	while(i >= 0)
	{
		nb++;
		ft_putchar(hex_digit((p >> i) & 0xf));
		i -= 4;
	}
	if (x.minus)
		nb += ft_pwidth(x, a);
	return (nb);
}
/*
int main()
{
	//char *p = "hello";
	int p = 3333;
	int *pp = &p;
	int **ppp = &pp;
	print_address_hex((void*)*ppp);
	printf("\n%p\n", (void*)*ppp);
}
*/
