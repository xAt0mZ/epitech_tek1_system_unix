/*
** tree_make.c for 42sh in /home/lefebv_z//projet/unix/42sh/test_arbres
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Thu May 16 17:41:22 2013 marie lefebvre
** Last update Sun May 26 16:23:19 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

int		my_put_in_tree(t_tree **list, char *token, int type, int side)
{
  t_tree	*elem;

  if (!(elem = malloc(sizeof(t_tree))))
    return (ERROR);
  elem->token = token;
  elem->type = type;
  elem->prev = *list;
  elem->left = NULL;
  elem->right = NULL;
  if (*list && side == LEFT)
    (*list)->left = elem;
  else if (*list && side == RIGHT)
    (*list)->right = elem;
  *list = elem;
  return (SUCCESS);
}

static int	to_the_next_separator(char **tab, char **sep)
{
  int		i;

  i = 0;
  if (my_strcmp(sep[0], "<") == 0)
    while (tab[i] && my_strcmp(tab[i], sep[0]) != 0
	   && my_strcmp(tab[i], sep[1]) != 0
	   && my_strcmp(tab[i], "<<") != 0
	   && my_strcmp(tab[i], ">>") != 0)
      i++;
  else
    while (tab[i] && my_strcmp(tab[i], sep[0]) != 0
	   && my_strcmp(tab[i], sep[1]) != 0)
      i++;
  return (i);
}

static char	**left_tab(char **tab, int i)
{
  char		**new;
  int		j;

  if (!(new = malloc(sizeof(char *) * (i + 1))))
    return (NULL);
  j = 0;
  while (j < i)
    {
      new[j] = tab[j];
      j++;
    }
  new[j] = NULL;
  return (new);
}

int	make_tree(t_tree **tree, char **tab, int side, char **sep)
{
  int	i;
  char	**tmp;
  int	ret;

  i = to_the_next_separator(tab, sep);
  if (i == 0)
    return (error_v_int("Invalid null command.\n", USER_ERROR));
  if (tab[i])
    {
      if (my_put_in_tree(tree, tab[i], SEPARATOR, side) == ERROR)
	return (ERROR);
      if ((ret = make_tree(tree, tab + i + 1, RIGHT, sep)) != SUCCESS)
	return (ret);
      *tree = (*tree)->prev;
      if (!(tmp = left_tab(tab, i)))
	return (ERROR);
      if ((ret = child_tree(tree, tmp, LEFT, sep)) != SUCCESS)
	return (ret);
      free(tmp);
      *tree = (*tree)->prev;
      return (SUCCESS);
    }
  return (child_tree(tree, tab, side, sep));
}
