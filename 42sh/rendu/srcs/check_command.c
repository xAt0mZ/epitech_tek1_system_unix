/*
** check_command.c for 42sh in /home/lefebv_z//projet/unix/42sh/new_tree
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Sun May 26 13:40:14 2013 marie lefebvre
** Last update Sun May 26 16:30:03 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

char		**check_command(char *token, t_glob *glob)
{
  char		**command;
  char		*ret;
  t_list	*path;

  if (!(command = my_str_to_wordtab(token, " ")))
    {
      glob->retval = ERROR;
      return (error_ptr(MALLOC_ERROR));
    }
  if (!(path = finder("PATH", glob->env)))
    return (error_ptr("Can't find PATH variable in environment\n"));
  if (!(ret = see_access(command[0], path)))
    {
      putstr_fd(2, command[0]);
      free_tab(command);
      return (error_ptr(" : Command not found\n"));
    }
  if (command[0] != ret)
    {
      free(command[0]);
      command[0] = ret;
    }
  return (command);
}

int		tree_check_pipes(t_tree *tree, t_glob *glob)
{
  t_tree	*tmp;
  char		**command;

  tmp = tree;
  while (my_strcmp(tmp->token, "|") == 0)
    {
      if (tmp->left->token[0] == '<' || tmp->left->token[0] == '>')
	tmp = tmp->left;
      if ((!(command = check_command(tmp->left->token, glob))))
	return (ERROR);
      if (tmp->token[0] == '<' || tmp->token[0] == '>')
	tmp = tmp->prev;
      free_tab(command);
      tmp = tmp->right;
    }
  if (tmp->token[0] == '<' || tmp->token[0] == '>')
    tmp = tmp->left;
  if ((!(command = check_command(tmp->token, glob))))
    return (ERROR);
  free_tab(command);
  return (SUCCESS);
}
