##
## Makefile for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
## 
## Made by louis-philippe baron
## Login   <baron_l@epitech.net>
## 
## Started on  Wed Jan 16 11:47:26 2013 louis-philippe baron
## Last update Sat Jan 19 21:45:23 2013 louis-philippe baron
##

SRC=		main.c \
		basics.c \
		basics2.c \
		linked_list.c \
		rev_list.c \
		show_list.c \
		free_list.c \
		find_term.c \
		exec_command.c \
		modes.c \
		puts.c \
		key_functions.c \
		key_functions2.c \
		ioctl.c \
		show_final_list.c

OBJ=		$(SRC:.c=.o)

NAME=		my_select

CFLAGS=		-g -Wall -Wextra -ansi -pedantic
CFLAGS+=	-ltermcap

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
