/*
** h42.h for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/tree
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 16:48:27 2013 Garnero Philip
** Last update Sun May 26 23:03:41 2013 damien sauvalle
*/

#ifndef		H_42_H_
# define	H_42_H_

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

typedef struct	s_tree
{
  char		*token;
  int		type;
  struct s_tree	*prev;
  struct s_tree	*left;
  struct s_tree	*right;
}		t_tree;

#include	"hglob.h"
#include	"hprototypes.h"

#endif		/* H_42_H */
