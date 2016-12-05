/*
** h42.h for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/tree
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 16:48:27 2013 Garnero Philip
** Last update Sun May 26 16:42:28 2013 louis-philippe baron
*/

#ifndef		H_42_H_
# define	H_42_H_

/*
# include	<unistd.h>
# include	<stdarg.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/wait.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<string.h>
# include	<signal.h>
# include	<dirent.h>
# include	<glob.h>
*/
#define		USER_ERROR	(-2)
#define		ERROR		(-1)
#define		SUCCESS		(0)
#define		EXIT		(1)
#define		MALLOC_ERROR	("Couldn't alloc\n")

#define		LEFT		(0)
#define		RIGHT		(1)
#define		SEPARATOR	(0)
#define		COMMAND		(1)
#define		FILE		(2)
#define		REDIR_CHAR(c)	((c == '<' || c == '>') ? (1) : (0))

typedef struct	stat t_stat;

typedef struct	s_list
{
  char		*comp;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef struct	s_hist
{
  char		*command;
  int		id;
  struct s_hist	*next;
  struct s_hist	*prev;
}		t_hist;

typedef struct	s_tree
{
  char		*token;
  int		type;
  struct s_tree	*prev;
  struct s_tree	*left;
  struct s_tree	*right;
}		t_tree;

typedef	struct	s_glob
{
  char		*input;
  t_list	*env;
  t_hist	*hist;
  int		hist_fd;
  int		hist_id;
  int		retval;
  int		exit;
}		t_glob;

#include	"hprototypes.h"

#endif		/* H_42_H */
