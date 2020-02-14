/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia </var/spool/mail/jiglesia>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:56:30 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/13 16:58:24 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_printf(const char *format, ...);
#include <unistd.h>
#define N 123
#define T "d"

int	main()
{
	unsigned int xxx;
	char *p = "arsta";
	//printf("'%#6.5o' [%#8.5x] '%10.5d' '%015.5f' '%.5s' [%-15.15s] [%5c] %#333\n", 123, 13, 123, 123.34, "4223544", "holaquetal", 't');
	printf("|%-015.17"T"| %%0-15.7\n", N);
	printf("|%015.17"T"| %%015.7\n", N);
	printf("|%-15.17"T"| %%-15.7\n", N);
	printf("|%15.17"T"| %%15.7\n", N);
	printf("|%-015"T"| %%0-15\n", N);
	printf("|%015"T"| %%015\n", N);
	printf("|%-15"T"| %%-15\n", N);
	printf("|%.7"T"| %%.7\n", N);

	write(1,  "\e[38;2;255;0;0m", 16);
	//ft_printf("'%#6.5o' [%#8.5x] '%1N5d' '%015.5f' '%.5s' [%-15.15s] [%5c] %#333\n", 123, 13, 123, 123.34, "4223544", "holaquetal", 't');
/*	ft_printf("|%-015.17"T"| %%#0- 15.7\n", N);
	ft_printf("|%015.17"T"| %%#0 15.7\n", N);
	ft_printf("|%-15.17"T"| %%#- 15.7\n", N);
	ft_printf("|%15.17"T"| %%# 15.7\n", N);
	ft_printf("|%-015"T"| %%#0- 15\n", N);
	ft_printf("|%015"T"| %%#0 15\n", N);
	ft_printf("|%-15"T"| %%#- 15\n", N);
	ft_printf("|%15"T"| %%# 15\n", N);
*/
	printf("<%u>", -1000000000);

//ft_printf("@moulitest: %s", NULL);

	write(1, "\e[0m", 4);

	//write(1, "HH", 2);
	return (0);
}
