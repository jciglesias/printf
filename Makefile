#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiglesia </var/spool/mail/jiglesia>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 23:03:24 by jiglesia          #+#    #+#              #
#    Updated: 2020/02/15 20:11:08 by jiglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libftprintf.a
INCLUDE		=	./
SRC			=	checkflags.c  flags_cspdu.c  ft_intwidth.c  ft_printf.c ft_process.c  ft_u.c  ft_uxX.c saveflags.c flag_p.c ft_putnbr.c ft_strlen.c ft_countchr.c ft_atoi.c ft_strdup.c ft_strrev.c ft_realloc.c ft_putchar.c

OBJS		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f

%.o: %.c
				$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME)	: 		$(OBJS)
				-@ar rc $(NAME) $(OBJS)
				ranlib $(NAME)

clean	:
				$(RM) $(OBJS)

all		:		$(NAME)

fclean	:		clean
				$(RM) $(NAME)

re		:		fclean all
