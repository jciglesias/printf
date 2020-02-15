/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:40:12 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/15 20:09:25 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_realloc(char *str, int n)
{
	char		*dup;
	int			i;

	i = -1;
	if (str)
	{
		dup = ft_strdup(str);
		free(str);
	}
	else
		dup = ft_strdup("");
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(dup) + n + 1))))
		return (NULL);
	while (dup[++i])
		str[i] = dup[i];
	str[i] = 0;
	if (dup)
		free(dup);
	return (str);
}
