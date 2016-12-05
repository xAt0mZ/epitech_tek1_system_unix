##
## Makefile for printf in /home/baron_l//local/rendu/piscine/projets/printf
## 
## Made by louis-philippe baron
## Login   <baron_l@epitech.net>
## 
## Started on  Wed Nov 14 12:36:18 2012 louis-philippe baron
## Last update Fri Nov 23 12:04:23 2012 louis-philippe baron
##

SRC=		printf.c \
		basics.c \
		basics2.c \
		types.c

OBJ=		$(SRC:.c=.o)

NAME=		libmy.a

CFLAGS=		-Wall -g -ansi -pedantic

all:		compile

compile:	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
