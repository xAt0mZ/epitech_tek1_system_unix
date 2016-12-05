/*
** hglob.h for 42sh in /home/sauval_d//42sh-2017-baron_l/include
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Sun May 26 23:01:58 2013 damien sauvalle
** Last update Sun May 26 23:03:58 2013 damien sauvalle
*/

#ifndef		HGLOB_H_
# define	HGLOB_H_

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

#endif	/* !HGLOB_H_ */
