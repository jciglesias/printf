/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia </var/spool/mail/jiglesia>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:53:49 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/16 23:29:05 by jiglesia         ###   ########.fr       */
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

void    checkwidth(char *flags, int *i)
{
	if (flags[(*i)] == '*')
	{
		(*i)++;
		return ;
	}
	while (flags[*i] && ft_countchr(flags[*i], "0123456789"))
		(*i)++;
}

void    checkprecision(char *flags, int *i)
{
	if (flags[*i] == '.')
	{
		if (flags[++(*i)] == '*')
			return ;
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
	if (flags[*i] && ft_countchr(flags[*i], "cspdiuxX"))
		return (1);
	return (0);
}
