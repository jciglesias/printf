/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:22:04 by jiglesia          #+#    #+#             */
/*   Updated: 2020/05/11 18:27:20 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_digit(int n)
{
	return (0 <= n && n <= 9) ? ('0' + n) : ('a' + n - 10);
}

int		ft_pwidth(t_flags x, int a)
{
	int dif;
	int sum;
	int	i;

	i = 2;
	while (a >= 0)
	{
		a -= 4;
		i++;
	}
	dif = x.width;
	dif -= (i > x.precision) ? i : x.precision + 2;
	sum = dif;
	while (dif-- > 0)
		ft_putchar((x.zero && !x.minus && !x.precision) ? 0 : ' ');
	return ((sum > 0) ? sum : 0);
}

int		ft_pprecision(t_flags x, int a)
{
	int dif;
	int sum;
	int i;

	i = 0;
	while (a >= 0)
	{
		a -= 4;
		i++;
	}
	dif = (x.precision) ? x.precision - i : x.width - i - 2;
	sum = dif;
	while (dif-- > 0)
		ft_putchar('0');
	return ((sum > 0) ? sum : 0);
}

int		ft_hexsize(int a, unsigned long p)
{
	while (hex_digit((p >> a) & 0xf) == '0')
		a -= 4;
	return ((a < 0) ? 0 : a);
}

int		print_address(t_flags x, void *p0)
{
	int				i;
	int				nb;
	int				a;
	unsigned long	p;

	p = (unsigned long)p0;
	if (!p)
		return (ft_p0(x));
	i = (p) ? ft_hexsize((sizeof(p) << 3) - 20, p) : 0;
	a = i;
	nb = (!x.minus) ? ft_pwidth(x, a) : 0;
	nb += write(1, "0x", 2);
	if (x.precision || (x.zero && !x.minus && !x.precision))
		nb += ft_pprecision(x, a);
	else
	{
		while (i >= 0)
		{
			nb++;
			ft_putchar(hex_digit((p >> i) & 0xf));
			i -= 4;
		}
	}
	nb += (x.minus) ? ft_pwidth(x, a) : 0;
	return (nb);
}
