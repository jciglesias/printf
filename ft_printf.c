/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:39:26 by jiglesia          #+#    #+#             */
/*   Updated: 2020/01/20 15:21:55 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print(va_list ap, char *flags)
{

}

int		ft_printf(const *flags, ...)
{
	va_list		ap;
	int			numchar;

	va_start(ap, flags);
	numchar = ft_print(ap, flags);
	va_end(ap);
	return (numchar);
}
