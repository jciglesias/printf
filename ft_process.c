/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia </var/spool/mail/jiglesia>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:39:12 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/15 20:11:26 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ignore 0 if - or precision in number
** - == left justification
*/

char	*str_hex(unsigned int a)
{
	char	*str;
	int		i;

	i = 0;
	str = "";
	while (a)
	{
		str = ft_realloc(str, 1);
		str[i++] = hex_digit((int)(a % 16));
		a /= 16;
	}
	str = ft_strrev(str);
	return (str);
}

int	ft_uxX(t_flags x, va_list ap)
{
	if (x.convertion == 'x')
		return (ft_xX(x, str_hex((unsigned int)va_arg(ap, int))));
	else if (x.convertion == 'X')
		return (ft_xX(x, str_hex((unsigned int)va_arg(ap, int))));
	else
		return (ft_u(x, (unsigned int)va_arg(ap, int)));
}

/*
** width counts '-'
** printing '-' before everything then positive number
*/

int	ft_di(t_flags x, va_list ap)
{
	int	a;
	int sum;

	a = (int)va_arg(ap, int);
	sum = write(1, "-", a < 0);
	if (!x.minus)
		sum += ft_intwidth(x, a);
	if (x.precision)
		sum += ft_intprecision(x, a);
	sum += flag_di((a < 0) ? -a : a);
	if (x.minus)
		sum += ft_intwidth(x, a);
	return (sum);
}

int	ft_cs(t_flags x, va_list ap)
{
	if (x.convertion == 'c')
		return (flag_c(x, (char)va_arg(ap, int)));
	else
		return (flag_s(x, va_arg(ap, char *)));
}

int	ft_p(t_flags x,va_list ap)
{
	return (print_address(x, va_arg(ap, void *)));;
}
