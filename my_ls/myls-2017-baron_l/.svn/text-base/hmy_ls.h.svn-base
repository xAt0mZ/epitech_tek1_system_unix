/*
** hmy_ls.h for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sun Nov 25 15:00:00 2012 louis-philippe baron
** Last update Sun Dec  2 23:16:00 2012 louis-philippe baron
*/

#ifndef	HMY_LS_H_
#define	HMY_LS_H_

#include	<dirent.h>

#define	ERROR		(1)
#define	ISMAJ(x)	(((x) > 64 && (x) < 91) ? ((x) + 32) : (x))


typedef struct s_file
{
  char		*time;
  char		*res_time;
  char		*path;
  char		*mode;
  char		*rights;
} t_file;

typedef struct s_data
{
  char		**files;
  char		*options;
  char		*directory;
} t_data;

void		my_putchar(char);
void		my_putstr(char *);
int		my_ls(t_data *);
int		my_strlen(char *);
char		**myls(char *);
int		my_printf(char *, ...);

char		*get_mode(int, char *);
char		*fill_mode_res(char *, char *, int, int);
char		*get_rights(char *);
char		*my_malloc(int);
char		*copy_time(char *);
char		*get_path(char *, char *);

int		l_option(char *, char *);
int		fill_files(char **, char *, int);
char		**sort_files(int, char **);
int		fill_options(char *, char *);
char		*sort_options(int, char **);
int		r_option(char **);

int		free_params(t_data *);
int		freeall_l_option(t_file *);
int		free_wordtab(char **);

int		sort_wordtab(char **);
int		swap_alpha(char **);
char		**put_to_wordtab(char *, char **);

#endif
