/*
** hprototypes.h for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Jan 16 19:20:06 2013 louis-philippe baron
** Last update Sat Jan 19 21:45:08 2013 louis-philippe baron
*/

#ifndef	PROTOTYPES_H_
#define	PROTOTYPES_H_

/*
** File: basics.c
*/

int		my_strlen(char *);
char		*my_strdup(char *);
int		my_strcmp(char *, char *);
void		clean_buffer(char *);
void		init_ptr(t_ptr *, t_list *);

/*
** File: basics2.c
*/

void		my_putchar(char, int);
void		my_putstr(char *, int);
int		tputschar(int);

/*
** File: exec_command.c
*/

int		exec_command(char *, t_ptr *, int *);

/*
** File: find_term.c
*/

char		*find_term(char **);

/*
** File: free_list.c
*/

void		free_list(t_list **);

/*
** File: ioctl.c
*/

int		do_ioctl(t_winsize *, t_list *);

/*
** File: key_functions.c
*/

void		up(t_ptr *);
void		down(t_ptr *);
void		del_backspace(t_ptr *, int *);

/*
** File: key_functions2.c
*/

void		space(t_ptr *);
void		echap(t_ptr *, int *);

/*
** File: linked_list.c
*/

t_list		*init_list(int, char **);

/*
** File: modes.c
*/

int		normal_mode();
int		raw_mode();

/*
** File: puts.c
*/

int		put_goto(int, int);
int		put(char *);

/*
** File: rev_list.c
*/

int		rev_list(t_list **);

/*
** File: show_final_list.c
*/

void		show_final_list(t_ptr *);

/*
** File: show_list.c
*/

void		show_list(t_list **);
void		show_final_list(t_ptr *);

#endif
