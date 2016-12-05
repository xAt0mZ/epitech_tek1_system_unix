/*
** hprototypes.h for minishell2 in /home/baron_l//local/rendu/projets/system_unix/minishell2/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Feb 28 11:56:44 2013 louis-philippe baron
** Last update Mon Mar  4 18:13:27 2013 louis-philippe baron
*/

#ifndef	PROTOTYPES_H_
#define	PROTOTYPES_H_

/*
** basics
*/
void		my_putchar(char);
void		my_putstr(char *);
int		my_putnbr(int);
int		my_strlen(char *);
int		my_strcmp(char *, char *);
int		my_getnbr(char *);
char		*my_strcpy(char *);

/*
** buitins
*/
int		built_cd(char **, t_list *);
int		built_setenv(char **, t_list *);
int		built_unsetenv(char **, t_list *);
int		built_env(char **, t_list *);
int		built_exit(char **, t_list *);

/*
** env managing
*/
char		**clone_env(char **, int, int);
char		*create_inex_path();
int		get_len_env(char **);

/*
** parsing
*/
char		**my_str_to_wordtab(char *, char *);
char		**my_command_to_wordtab(char *, char *);
int		is_in(char, char *);
int		command_size(char **);
int		is_valid(char **);
char		*epur_str(char *, char *);

/*
** builtins
*/
int		is_a_builtin(char **);
int		exec_builtin(char **, t_list *);

/*
** execution
*/
int		exec(char **, char **, char **);
int		exec_command(char *, char **, char **);
int		mysh(t_list *);

/*
** redirections
*/
int		my_pipe(char **, t_list *, char **);
int		right_redir(char **, t_list *, char **);
int		left_redir(char **, t_list *, char **);
int		double_right_redir(char **, t_list *, char **);
int		double_left_redir(char **, t_list *, char **);
int		no_redir(char *, t_list *, char **);
int		red(char **, t_list *, char **);

/*
** other functions
*/
int		my_printf(char *, ...);
char		*get_next_line(int);
int		free_wordtab(char **);

#endif
