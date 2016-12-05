/*
** cross_tree.c for 42sh in /home/lefebv_z//projet/unix/42sh/test_arbres
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Wed May 15 19:12:31 2013 marie lefebvre
** Last update Sun May 26 13:42:24 2013 marie lefebvre
*/

#include	"h42.h"

static int	condition_branch(t_tree *tree, t_glob *glob)
{
  int		ret;

  ret = 0;
  if (my_strcmp(tree->token, "&&") == 0)
    {
      ret = cross_tree(tree->left, glob);
      if (glob->retval == SUCCESS && ret == SUCCESS)
	ret = cross_tree(tree->right, glob);
    }
  else if (my_strcmp(tree->token, "||") == 0)
    {
      ret = cross_tree(tree->left, glob);
      if (glob->retval == SUCCESS && ret != SUCCESS)
	ret = cross_tree(tree->right, glob);
    }
  return (ret);
}

static int	to_the_next_branch(t_tree *tree, t_glob *glob)
{
  int		ret;

  ret = 0;
  if (my_strcmp(tree->token, "|") == 0)
    ret = pipe_branch(tree, glob);
  else if (my_strcmp(tree->token, "&&") == 0
	   || my_strcmp(tree->token, "||") == 0)
    ret = condition_branch(tree, glob);
  else if (tree->token[0] == '<' || tree->token[0] == '>')
    ret = tree_redir(tree, glob);
  else
    ret = ERROR;
  return (ret);
}

int		cross_tree(t_tree *tree, t_glob *glob)
{
  char		**command;

  if (!tree)
    return (ERROR);
  if (tree->type == COMMAND)
    {
      if (!(command = my_str_to_wordtab(tree->token, " ")))
	return (error_int_set_glob(glob, MALLOC_ERROR));
      if (is_builtins(command))
	return (tree_exec_builtins(command, glob));
      return (tree_exec_command(tree->token, glob));
    }
  return (to_the_next_branch(tree, glob));
}
