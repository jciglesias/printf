/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:55:45 by jiglesia          #+#    #+#             */
/*   Updated: 2020/05/11 19:18:15 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_flags
{
	int					zero;
	int					minus;
	int					width;
	int					wstar;
	int					precision;
	int					point;
	int					pstar;
	char				convertion;
	int					i;
}						t_flags;

int						ft_intwidth(t_flags x, int a);
int						ft_intprecision(t_flags x, int a);
char					hex_digit(int n);
void					checkflag(char *flags, int *i);
void					checkwidth(char *flags, int *i);
void					checkprecision(char *flags, int *i);
int						checkconvertion(char *flags, int *i);
t_flags					saveflags(char *flags, int **i, va_list ap);
int						ft_ux(t_flags x, va_list ap);
int						ft_u(t_flags x, unsigned int a);
int						ft_x(t_flags x, char *str);
int						ft_ulength(unsigned int a);
int						ft_uprecision(t_flags x, unsigned int a);
int						ft_di(t_flags x, va_list ap);
int						ft_cs(t_flags x, va_list ap);
int						ft_p(t_flags x, va_list ap);
int						flag_di(int d);
int						flag_c(t_flags x, char c);
int						flag_s(t_flags x, char *s);
int						ft_p(t_flags x, va_list ap);
int						print_address(t_flags x, void *p0);
int						ft_printf(char *flags, ...);
int						flag_u(unsigned int u);
void					ft_putchar(char c);
void					ft_putnbr(int n);
int						ft_strlen(const char *s);
int						ft_countchr(char c, char *str);
int						ft_atoi(const char *nptr);
char					*ft_strdup(const char *s);
char					*ft_strrev(char *str);
char					*ft_realloc(char *str, int n);
void					ft_putint(unsigned int n);
int						ft_printf(char *format, ...);
int						ft_void0(t_flags x);
int						ft_p0(t_flags x);
int						ft_snull(t_flags x);
int						ft_percent(t_flags x);
#endif
