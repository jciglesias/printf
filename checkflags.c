/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:18:42 by jiglesia          #+#    #+#             */
/*   Updated: 2020/05/11 18:20:48 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** libft: ft_countchr
** input: flags (format string) i (string position)
*/

void	checkflag(char *flags, int *i)
{
	while (flags[*i] && ft_countchr(flags[*i], "0-"))
		(*i)++;
}

void	checkwidth(char *flags, int *i)
{
	if (flags[(*i)] == '*')
	{
		(*i)++;
		return ;
	}
	while (flags[*i] && ft_countchr(flags[*i], "0123456789"))
		(*i)++;
}

void	checkprecision(char *flags, int *i)
{
	if (flags[*i] == '.')
	{
		if (flags[++(*i)] == '*')
		{
			(*i)++;
			return ;
		}
		while (flags[*i] && ft_countchr(flags[*i], "0123456789"))
			(*i)++;
	}
}

/*
** libft: ft_countchr
** input: flags (format string) i (string position)
** return: it worked! or nah
*/

int		checkconvertion(char *flags, int *i)
{
	if (flags[*i] && ft_countchr(flags[*i], "cspdiuxX%"))
		return (1);
	return (0);
}
