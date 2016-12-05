##
## Makefile for tp in /home/baron_l//local/rendu/piscine/projets/my_ls/tp
## 
## Made by louis-philippe baron
## Login   <baron_l@epitech.net>
## 
## Started on  Wed Nov 28 14:08:23 2012 louis-philippe baron
## Last update Sun Dec  2 23:19:30 2012 louis-philippe baron
##

SRC=		main.c \
		basics.c \
		myls.c \
		get_mode.c \
		time.c \
		path.c \
		l_option.c \
		freeall.c \
		printf.c \
		funcs_for_pf.c \
		funcs_for_pf2.c \
		types.c \
		sort_params.c \
		wordtabs.c \
		r_option.c

OBJ=		$(SRC:.c=.o)

NAME=		my_ls

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
