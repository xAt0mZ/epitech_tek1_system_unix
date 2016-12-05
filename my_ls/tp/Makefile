##
## Makefile for tp in /home/baron_l//local/rendu/piscine/projets/my_ls/tp
## 
## Made by louis-philippe baron
## Login   <baron_l@epitech.net>
## 
## Started on  Wed Nov 28 14:08:23 2012 louis-philippe baron
## Last update Wed Nov 28 14:24:19 2012 louis-philippe baron
##

SRC=		main.c \
		basics.c

OBJ=		$(SRC:.c=.o)

NAME=		my_ls

CFLAGS=		-g -Wall -Wextra -ansi -pedantic

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
