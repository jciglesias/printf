/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:39:26 by jiglesia          #+#    #+#             */
/*   Updated: 2020/01/27 20:54:19 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_checkflags(int *i, char *flags, va_list ap, int sum)
{
	while (flags[i] && (flags[i] != '%' || flags[i] != ' '))
	{
		
	}
	return (sum);
}

int		ft_print(va_list ap, char *flags, int sum)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '%')
			sum = ft_checkflags(&i, flags, ap, sum);
		else
		{
			ft_putchar(flags[i++]);
			sum++;
		}
	}
	return (sum);
}

int		ft_printf(const *flags, ...)
{
	va_list		ap;
	int			sum;

	va_start(ap, flags);
	sum = ft_print(ap, flags, sum);
	va_end(ap);
	return (sum);
}
