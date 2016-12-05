/*
** hminishell1.h for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Dec 17 15:45:48 2012 louis-philippe baron
** Last update Tue Mar  5 10:38:30 2013 louis-philippe baron
*/

#ifndef	MINISHELL_H_
#define	MINISHELL_H_

#include	<unistd.h>
#include	<stdarg.h>
#include	<stdlib.h>

/*
** Includes for stat(in check_access) && wait(for forks)
** && open (right / left redir)
*/
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<sys/stat.h>
#include	<fcntl.h>

#define	ERROR	(1)

typedef struct	stat t_stat;

typedef	struct	s_list
{
  char		**env;
  char		*input;
  char		**redir;
  char		**coma;
  char		**path;
  int		envlen;
  int		k;
}		t_list;

#include	"hprototypes.h"

#endif
