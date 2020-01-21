/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_cspdu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:52:20 by jiglesia          #+#    #+#             */
/*   Updated: 2020/01/21 16:52:58 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		flag_c(int c)
{
	unsigned char a;

	a = (unsigned char)c;
	write(1, &c, 1);
	return (1);
}

int		flag_s(char *s)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int		flag_p(void *s)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar((char)s[i++]);
	return (i);
}

int		flag_d(int d)
{
	int i;

	i = 0;
	ft_putnbr(d);
	if (d < 0)
		i++;
	while (d /= 10)
		i++;
	return (i);
}

int		flag_u(unsigned int u)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (u)
	{
		str = ft_realloc(str, 1);
		str[i++] = u % 10;
		u /= 10;	
	}
	str[i] = 0;
	j = i;
	while (--i >= 0)
		ft_putchar(str[i]);
	return (j);
}
