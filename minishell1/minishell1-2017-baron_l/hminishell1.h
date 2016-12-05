/*
** hminishell1.h for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Dec 17 15:45:48 2012 louis-philippe baron
** Last update Thu Feb 28 11:23:03 2013 louis-philippe baron
*/

#ifndef	MINISHELL_H_
#define	MINISHELL_H_

#include	<unistd.h>
#include	<stdarg.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<sys/stat.h>

#define	ERROR	(1)

void		my_putchar(char);
void		my_putstr(char *);
int		my_putnbr(int);
int		my_strlen(char *);
int		my_strcmp(char *, char *);

char		*my_strcpy(char *);
char		*create_inex_path();

int		command_size(char **);
int		is_a_builtin(char **);
int		exec_builtin(char **, char **);

int		built_cd(char **, char **);
int		built_setenv(char **, char **);
int		built_unsetenv(char **, char **);
int		built_env(char **, char **);
int		built_exit(char **, char **);

int		my_printf(char *, ...);
char		*get_next_line(int);
char		**my_str_to_wordtab(char *, char *);

int		free_wordtab(char **);

char		**clone_env(char **, int, int);
int		mysh(char *, char **);

int		exec(char **, char **, char **);
int		exec_command(char *, char **, char **);

#endif
