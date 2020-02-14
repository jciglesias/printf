#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiglesia </var/spool/mail/jiglesia>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 23:03:24 by jiglesia          #+#    #+#              #
#    Updated: 2020/02/14 00:28:24 by jiglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libftprintf.a
INCLUDE		=	./libft/
SRC			=	checkflags.c  flags_cspdu.c  ft_intwidth.c  ft_printf.c  ft_printf.h  ft_process.c  ft_u.c  ft_uxX.c saveflags.c
SUB_MAKE	=	./libft/
INC_LIB		=	-L./libft/ -lft

OBJS		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f

%.o: %.c
				$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME)	: 		$(OBJS)
				-@(cd $(SUB_MAKE) && $(MAKE))
				-@$(CC)  -I $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS) $(INC_LIB)

clean	:
				-@$(RM) $(OBJS)
				-@(cd $(SUB_MAKE) && $(MAKE) clean)

all		:		$(NAME)

fclean	:		clean
				-@$(RM) $(NAME)
				-@(cd $(SUB_MAKE) && $(MAKE) fclean)

re		:		fclean all
				-@(cd $(SUB_MAKE) && $(MAKE) re)
