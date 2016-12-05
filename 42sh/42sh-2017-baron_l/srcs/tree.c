/*
** tree.c for 42sh in /home/lefebv_z//projet/unix/42sh/test_arbres
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Wed May 15 11:10:38 2013 marie lefebvre
** Last update Sun May 26 16:23:03 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

static void	free_tree(t_tree *tree)
{
  if (tree)
    {
      if (tree->left)
	free_tree(tree->left);
      if (tree->right)
	free_tree(tree->right);
      free(tree);
    }
}

int		tree_call(char **tab, t_glob *glob)
{
  t_tree	*tree;
  char		**sep;
  int		ret;

  if (!(sep = malloc(sizeof(char *) * 3)))
    return (error_int_set_glob(glob, MALLOC_ERROR));
  sep[0] = "&&";
  sep[1] = "||";
  tree = NULL;
  if ((ret = make_tree(&tree, tab, RIGHT, sep)) == ERROR)
    return (error_int_set_glob(glob, MALLOC_ERROR));
  else if (ret == USER_ERROR)
    return (glob->retval);
  free(sep);
  if (tree == NULL)
    return (ERROR);
  while (tree->prev)
    tree = tree->prev;
  tree_files(tree);
  while (tree->prev)
    tree = tree->prev;
  cross_tree(tree, glob);
  free_tree(tree);
  return (glob->retval);
}
