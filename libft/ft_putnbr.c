/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:44:43 by jiglesia          #+#    #+#             */
/*   Updated: 2020/01/21 16:26:52 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putint(unsigned int n)
{
    if (n > 9)
        ft_putnint(n / 10);
    ft_putchar(n % 10 + '0');
}
 
void			ft_putnbr(int nb)
{
    unsigned int n;
 
    if (nb < 0)
        ft_putchar('-');
	n = (nb < 0 ? -nb : nb);
	ft_putint(nb);
}
