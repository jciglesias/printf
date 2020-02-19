/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:44:43 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/19 21:53:05 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putint(unsigned int n)
{
    if (n > 9)
        ft_putint(n / 10);
    ft_putchar(n % 10 + '0');
}

void	ft_putnbr(int n)
{
    unsigned int a;

	a = (n < 0) ? -n : n;
    if (n < 0)
		ft_putchar('-');
	ft_putint(a);
}
