/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:40:12 by jiglesia          #+#    #+#             */
/*   Updated: 2020/01/21 16:45:05 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (!(bowl = (char *)malloc(sizeof(char) * (ft_strlen(dup) + n + 1))))
		return (NULL);
	while (dup[++i])
		bowl[i] = dup[i];
	bowl[i] = 0;
	if (dup)
		free(dup);
	return (bowl);
}
