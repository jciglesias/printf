/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia </var/spool/mail/jiglesia>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:31:12 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/19 14:52:10 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	j = ft_strlen(str);
	dup = ft_strdup(str);
	while (j)
		str[i++] = dup[--j];
	str[i] = 0;
	free(dup);
	return (str);
}
