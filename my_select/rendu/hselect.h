/*
** hprojet.h for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Jan 16 11:46:59 2013 louis-philippe baron
** Last update Sat Jan 19 16:13:30 2013 louis-philippe baron
*/

#ifndef	SELECT_H_
#define	SELECT_H_

#include	<unistd.h>
#include	<stdlib.h>
#include	<termios.h>
#include	<curses.h>
#include	<term.h>
#include	<sys/ioctl.h>

#define	ERROR	(1)

typedef struct	s_list
{
  char		*data;
  int		video;
  int		under;
  int		print;
  int		top;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef	struct	s_ptr
{
  t_list	*first;
  t_list	*last;
  t_list	*list;
}		t_ptr;

typedef	struct	winsize t_winsize;
typedef	struct	termios	t_termios;

#include	"hprototypes.h"

#endif
