/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:39:26 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/16 22:55:39 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** checkflags.c: * (every function in ft_checkflags)
** return: 1 if it's well formated else 0
*/

int		ft_checkflags(char *flags, int i)
{
	i++;
	checkflag(flags, &i);
	checkwidth(flags, &i);
	checkprecision(flags, &i);
	return (checkconvertion(flags, &i));
}

int		ft_flagprocess(t_flags x, va_list ap)
{
	if (ft_countchr(x.convertion, "uxX"))
		return (ft_uxX(x, ap));
	else if (ft_countchr(x.convertion, "di"))
		return (ft_di(x, ap));
	else if (ft_countchr(x.convertion, "cs"))
		return (ft_cs(x, ap));
	else
		return (ft_p(x, ap));
}

int		ft_printflag(int *i, char *flags, va_list ap)
{
	if (ft_checkflags(flags, *i))
		return (ft_flagprocess(saveflags(flags, &i, ap), ap));
	else if (flags[*i + 1] && flags[*i + 1] == '%')
	{
		(*i) += 2;
		return (write(1, "%", 1));
	}
	else
		return (write(1, &flags[(*i)++], 1));
}

int		ft_print(va_list ap, char *flags, int sum)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '%')
			sum += ft_printflag(&i, flags, ap);
		else if (flags[i] == '\\' && flags[i + 1])
			sum += write(1, &flags[i += 2], 2);
		else
		{
			ft_putchar(flags[i++]);
			sum++;
		}
	}
	return (sum);
}

int		ft_printf(char *flags, ...)
{
	va_list		ap;
	int			sum;

	sum = 0;
	va_start(ap, flags);
	sum = ft_print(ap, flags, sum);
	va_end(ap);
	return (sum);
}
