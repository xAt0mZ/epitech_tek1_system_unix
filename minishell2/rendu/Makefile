##
## Makefile for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
## 
## Made by louis-philippe baron
## Login   <baron_l@epitech.net>
## 
## Started on  Mon Dec 17 14:58:56 2012 louis-philippe baron
## Last update Tue Mar  5 10:21:08 2013 louis-philippe baron
##

SRC=		main.c \
		mysh.c \
		basics.c \
		basics2.c \
		printf.c \
		get_next_line.c \
		my_str_to_wordtab.c \
		my_command_to_wordtab.c \
		exec.c \
		forkloop.c \
		builtins.c \
		built_cd.c \
		built_setenv.c \
		built_unsetenv.c \
		built_env.c \
		built_exit.c \
		freeall.c \
		env.c \
		show_wdtb.c \
		epur_str.c \
		check_validity.c \
		pipe.c \
		right_redir.c \
		left_redir.c \
		double_right_redir.c \
		double_left_redir.c \
		redir.c

OBJ=		$(SRC:.c=.o)

CFLAGS=		-g -Wall -Wextra -ansi -pedantic

NAME=		mysh

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
