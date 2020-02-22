/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia </var/spool/mail/jiglesia>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:39:12 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/22 22:39:51 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ignore 0 if - or precision in number
** - == left justification
*/

char	*str_hex(t_flags x, unsigned int a)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup("0");
	while (a)
	{
		if (x.convertion == 'x')
			str[i++] = hex_digit((int)(a % 16));
		else
			str[i++] = (hex_digit((int)(a % 16)) >= 'a') ?
				hex_digit((int)(a % 16)) - 32 : hex_digit((int)(a % 16));
		str = ft_realloc(str, 1);
		a /= 16;
	}
	str = ft_strrev(str);
	return (str);
}

int	ft_uxX(t_flags x, va_list ap)
{
	if (x.convertion == 'x')
		return (ft_xX(x, str_hex(x, (unsigned int)va_arg(ap, int))));
	else if (x.convertion == 'X')
		return (ft_xX(x, str_hex(x, (unsigned int)va_arg(ap, int))));
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
	if (x.point && !x.precision && !a && !x.width)
		return (0);
	sum = 0;
	if (x.zero && !x.precision && a < 0)
		sum += write(1, "-", 1);
	if (!x.minus)
		sum += ft_intwidth(x, a);
	if ((!x.zero && a < 0) || (x.zero && x.precision && a < 0))
		sum += write(1, "-", 1);
	if (x.precision)
		sum += ft_intprecision(x, a);
	if (x.point && !x.precision && !a)
		sum += write(1, " ", 1);
	else
		sum += flag_di(a);
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
