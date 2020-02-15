/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia </var/spool/mail/jiglesia>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:35:46 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/15 20:07:37 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countchr(char c, char *str)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (str[i])
		if (str[i++] == c)
			a++;
	return (a);
}
