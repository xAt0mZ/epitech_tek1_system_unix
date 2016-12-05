/*
** mysh.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Dec 17 15:45:17 2012 louis-philippe baron
** Last update Mon Mar  4 18:14:03 2013 louis-philippe baron
*/

#include	"hminishell1.h"

static char	**get_path(char **env)
{
  char		**res;
  int		j;

  j = 0;
  while (env[j] && my_strcmp(env[j], "PATH") == ERROR)
    j++;
  if (env[j])
    res = my_str_to_wordtab(env[j], "=:");
  else
    res = my_str_to_wordtab("", ":");
  if (res == NULL)
    my_printf("Problem in memory allocation during PATH finding\n");
  return (res);
}

static int	in_command(char *command, t_list *list, char **path)
{
  char		**tmp;

  if ((tmp = my_command_to_wordtab(command, "><|")) == NULL)
    {
      my_printf("Problem in memory allocation during command parsing\n");
      return (ERROR);
    }
  if (is_valid(tmp) == ERROR)
    {
      free_wordtab(tmp);
      return (0);
    }
  list->redir = tmp;
  if (red(tmp, list, path) == ERROR)
    return (ERROR);
  free_wordtab(tmp);
  return (0);
}

static int	exec_separated_command(char **command, t_list *list)
{
  int		k;
  char		**path;

  k = 0;
  while (command[k])
    {
      if (get_len_env(list->env) >= list->envlen)
	{
	  if ((list->env = clone_env(list->env,
				     list->envlen + 42, list->k++)) == NULL)
	    return (ERROR);
	  list->envlen += 42;
	}
      if ((path = get_path(list->env)) == NULL)
	return (ERROR);
      list->path = path;
      if (in_command(command[k], list, path) == ERROR)
	return (ERROR);
      free_wordtab(path);
      k++;
    }
  return (0);
}

int		mysh(t_list *list)
{
  char		**command;

  if ((list->input = epur_str(list->input, "><|;")) == NULL)
    return (ERROR);
  if ((command = my_str_to_wordtab(list->input, ";")) == NULL)
    {
      my_printf("Problem in memory allocation during command parsing\n");
      return (ERROR);
    }
  free(list->input);
  list->coma = command;
  if (exec_separated_command(command, list) == ERROR)
    return (ERROR);
  free_wordtab(command);
  return (0);
}
