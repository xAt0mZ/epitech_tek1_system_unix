##
## Makefile for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
## 
## Made by louis-philippe baron
## Login   <baron_l@epitech.net>
## 
## Started on  Mon Dec 17 14:58:56 2012 louis-philippe baron
## Last update Sun May 26 16:19:18 2013 damien sauvalle
##

SRC=		srcs/access.c \
		srcs/basics.c \
		srcs/bool_condition.c \
		srcs/builtins.c \
		srcs/char_siders.c \
		srcs/check_quotes.c \
		srcs/check_command.c \
		srcs/check_conflict_redir.c \
		srcs/cross_tree.c \
		srcs/cut_redir.c \
		srcs/cut_redir_line.c \
		srcs/double_right_redir.c \
		srcs/echo.c \
		srcs/epur_str.c \
		srcs/error.c \
		srcs/exec.c \
		srcs/finder.c \
		srcs/get_next_line.c \
		srcs/get_next_line_list.c \
		srcs/globbing.c \
		srcs/glob_it.c \
		srcs/glob_it_cuts.c \
		srcs/glob_it_clean.c \
		srcs/glob_it_cat.c \
		srcs/glob_it_loop.c \
		srcs/history.c \
		srcs/int_siders.c \
		srcs/list_siders.c \
		srcs/main.c \
		srcs/mysh.c \
		srcs/my_str_to_wordtab.c \
		srcs/my_command_to_wordtab.c \
		srcs/old_pwd.c \
		srcs/path.c \
		srcs/pwd.c \
		srcs/stick_back_arg.c \
		srcs/tab.c \
		srcs/tree.c \
		srcs/tree_files.c \
		srcs/tree_make.c \
		srcs/tree_make_branch.c \
		srcs/tree_pipes.c \
		srcs/tree_redir.c \
		srcs/tree_redir_files.c \
		srcs/tree_exec.c \
		srcs/edt/aply_caps.c \
		srcs/edt/auto_cmp.c \
		srcs/edt/can_echo.c \
		srcs/edt/basic3.c\
		srcs/edt/completion.c \
		srcs/edt/cursor.c \
		srcs/edt/display.c \
		srcs/edt/init_caps.c \
		srcs/edt/key_cmd.c \
		srcs/edt/list_edt.c \
		srcs/edt/list_edt2.c \
		srcs/edt/edition.c \
		srcs/edt/return_cmp.c \
		srcs/edt/swap_char.c


OBJ=		$(SRC:.c=.o)

CFLAGS=		-g -Wall -Wextra -I ./include

NAME=		mysh

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) -lncurses

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
