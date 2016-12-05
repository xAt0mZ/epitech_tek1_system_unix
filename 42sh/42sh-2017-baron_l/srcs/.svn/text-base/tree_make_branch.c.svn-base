/*
** tree_make_branch.c for 42sh in /home/lefebv_z//projet/unix/42sh/test_arbres
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Fri May 17 14:03:43 2013 marie lefebvre
** Last update Sun May 26 16:23:36 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

static int	strong_sep_after(char *next_sep, char *sep)
{
  char		*separators;
  int		i;

  if (!next_sep || !sep)
    return (1);
  if (my_strcmp(next_sep, "||") == 0)
    next_sep = "&&";
  else if (my_strcmp(next_sep, ">") == 0)
    next_sep = "<";
  separators = "<|&";
  i = 0;
  while (separators[i] && separators[i] != sep[0])
    i++;
  while (separators[i] && separators[i] != next_sep[0])
    i++;
  if (separators[i])
    return (1);
  return (0);
}

static void	assign_new_sep(char **sep, char *s1, char *s2)
{
  sep[0] = s1;
  sep[1] = s2;
}

static int	change_sep(char **sep, int flag)
{
  if (sep[0] == NULL)
    return (ERROR);
  else if ((sep[0][0] == '&' && flag == RIGHT)
	   || (sep[0][0] == '<' && flag == LEFT))
    assign_new_sep(sep, "|", NULL);
  else if ((sep[0][0] == '|' && flag == RIGHT)
	   || (sep[0] == NULL && flag == LEFT))
    assign_new_sep(sep, "<", ">");
  else if (sep[0][0] == '<' && flag == RIGHT)
    assign_new_sep(sep, NULL, NULL);
  else if (sep[0][0] == '|' && flag == LEFT)
    assign_new_sep(sep, "&&", "||");
  return (SUCCESS);
}

int	child_tree(t_tree **tree, char **tab, int side, char **sep)
{
  int	ret;

  if (strong_sep_after(tab[1], sep[0]))
    return (my_put_in_tree(tree, tab[0], COMMAND, side));
  if (change_sep(sep, RIGHT) == ERROR)
    return (USER_ERROR);
  if ((ret = make_tree(tree, tab, side, sep)) != SUCCESS)
    return (ret);
  if (change_sep(sep, LEFT) == ERROR)
    return (USER_ERROR);
  return (0);
}
