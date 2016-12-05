##
## Makefile for minitalk in /home/baron_l//local/rendu/projets/system_unix/minitalk/rendu
## 
## Made by louis-philippe baron
## Login   <baron_l@epitech.net>
## 
## Started on  Mon Mar 18 11:10:04 2013 louis-philippe baron
## Last update Tue Mar 19 15:38:34 2013 louis-philippe baron
##

## server
SRC_S=		server/main.c \
		server/basics.c \
		server/init.c

OBJ_S=		$(SRC_S:.c=.o)

NAME_S=		server/server

## client
SRC_C=		client/main.c \
		client/basics.c \
		client/send_lenght.c

OBJ_C=		$(SRC_C:.c=.o)

NAME_C=		client/client

## rules
CFLAGS=		-g -Wall -Wextra -pedantic

all:		$(NAME_S) $(NAME_C)

$(NAME_S):	$(OBJ_S)
		cc -o $(NAME_S) $(OBJ_S)

$(NAME_C):	$(OBJ_C)
		cc -o $(NAME_C) $(OBJ_C)

clean:
		rm -f $(OBJ_S) $(OBJ_C)

fclean:		clean
		rm -f $(NAME_S) $(NAME_C)

re:		fclean all
