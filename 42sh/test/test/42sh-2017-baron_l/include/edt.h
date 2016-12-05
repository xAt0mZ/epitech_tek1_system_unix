/*
** edt.h for 42sh in /home/sauval_d//42sh-2017-baron_l
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Sun May 26 20:31:01 2013 damien sauvalle
** Last update Sun May 26 23:04:24 2013 damien sauvalle
*/

#ifndef		EDT_H_
# define	EDT_H_

#include	<unistd.h>
#include	<term.h>
#include	<termios.h>
#include	"hglob.h"

typedef struct termios t_term;

typedef struct	s_coo
{
  int		x;
  int		y;
}		t_coo;

typedef struct	s_caps
{
  char		*clearsc;
  char		*lclean;
  char		*restc;
  char		*sauvc;
  char		*cm;
  int		col;
  int		line;
}		t_caps;

typedef struct	s_char
{
  char		str;
  int		cur;
  int		num;
}		t_char;

typedef struct	s_item
{
  t_char	*data;
  struct s_item	*next;
  struct s_item *prev;
}		t_item;

typedef struct	s_charl
{
  t_item	*top;
  t_item	*bot;
  int		len;
  t_coo		cur;
  t_coo		end;
  t_coo		beg;
  int		idh;
}		t_charl;

typedef struct	s_auto
{
  char		*str;
  struct s_auto	*next;
}		t_auto;

int		edition_line(t_glob *glob, t_caps *caps);
int		key_cmd(char *line, t_charl *list, t_caps *caps);
void		init_cur(t_charl *list);
void		clean_buf(char *buf);
void		give_num(t_item *list);
int		delete(t_charl *list, t_caps *caps);
void		go_to_list(t_charl *list, char *line);
void		list_show(t_charl *list);
int		put_in_list(t_charl *list, char line);
int		first_insert(t_charl *list, char *line);
t_charl		*init_list();
void		free_list(t_charl *list);
int		supress(t_charl *list, t_caps *caps);
void		thats_bin(char *str);
int		my_putchar_int(int c);
void		my_putnbr(int nb);
int		xread(int fd, char *buf, int len);
char		*str_to_compl(char *str, int len);
int		add_cursor(t_charl *list, t_caps *caps);
int		my_getpos();
int		pre_tab(t_charl *list, t_caps *caps);
int		swap_char(t_charl *list, t_caps *caps);
int		cursor_beg(t_charl *list);
int		cursor_end(t_charl *list);
int		refresh(t_charl *list, t_caps *caps);
int		clear_sc(t_charl *list, t_caps *caps);
int		move_right(t_charl *list, t_caps *caps);
int		move_left(t_charl *list, t_caps *caps);
void		free_caps(t_caps *caps);
t_caps		*init_caps(char **env);
int		activ_can_echo(t_term *t);
int		dis_can_echo(t_term *t);
int		my_tgoto(t_charl *list, t_caps *caps);

#endif		/* !EDT_H_ */
