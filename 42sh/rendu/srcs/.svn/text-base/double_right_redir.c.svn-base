/*
** double_right_redir.c for 42sh in /home/lefebv_z//projet/unix/42sh/42sh-2017-baron_l
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Fri May 24 18:44:22 2013 marie lefebvre
** Last update Sun May 26 16:12:55 2013 marie lefebvre
*/

#include	<unistd.h>
#include	"h42.h"

int	is_double_right(t_tree *tree, int files[], int *pfd, t_glob *glob)
{
  if (my_strcmp(tree->token, "<<") != 0
      && (!tree->right || my_strcmp(tree->right->token, "<<") != 0))
    {
      pfd = NULL;
      return (SUCCESS);
    }
  if (pipe(pfd) == -1)
    return (error_int_set_glob(glob, "Error on pipe\n"));
  if (my_strcmp(tree->token, "<<") == 0)
    files[0] = pfd[0];
  else if (my_strcmp(tree->right->token, "<<") == 0)
    files[1] = pfd[0];
  return (SUCCESS);
}

static void	recup_entry(int fd, char *name)
{
  char		*str;
  t_list	*tmp;

  tmp = NULL;
  while (my_strcmp((str = get_next_line(0)), name))
    my_put_in_list(&tmp, str);
  while (tmp->prev)
    tmp = tmp->prev;
  while (tmp)
    {
      putstr_fd(fd, tmp->comp);
      putstr_fd(fd, "\n");
      tmp = tmp->next;
    }
}

void	double_right_redir(t_tree *tree, int pfd[])
{
  close(pfd[0]);
  if (my_strcmp(tree->token, "<<") == 0)
    {
      if (tree->right->type == FILE)
	recup_entry(pfd[1], tree->right->token);
      else
	recup_entry(pfd[1], tree->right->left->token);
    }
  else if (my_strcmp(tree->right->token, "<<") == 0)
    recup_entry(pfd[1], tree->right->right->token);
  close(pfd[1]);
}
