/*
** redir.c for minishell2 in /home/baron_l//local/rendu/projets/system_unix/minishell2/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Mar  1 09:55:28 2013 louis-philippe baron
** Last update Tue Mar  5 16:53:49 2013 louis-philippe baron
*/

#include	"hminishell1.h"

static int	find_redir(char *command)
{
  int		i;

  if (my_strcmp(command, "|") == 0)
    i = 0;
  else if (my_strcmp(command, ">>") == 0)
    i = 1;
  else if (my_strcmp(command, "<<") == 0)
    i = 2;
  else if (my_strcmp(command, ">") == 0)
    i = 3;
  else if (my_strcmp(command, "<") == 0)
    i = 4;
  return (i);
}

int		no_redir(char *tmp, t_list *list, char **path)
{
  int		retvalue;
  char		**command;

  if ((command = my_str_to_wordtab(tmp, " ")) == NULL)
    {
      my_printf("Problem in memory allocation during command parsing\n");
      return (ERROR);
    }
  if (is_a_builtin(command) == 0)
    retvalue = exec_builtin(command, list);
  else
    retvalue = exec(command, path, list->env);
  if (retvalue == ERROR)
    my_printf("%s: Command not found\n", command[0]);
  free_wordtab(command);
  return (retvalue);
}

static int	choose_redir(char **tmp, t_list *list, char **path)
{
  int		(*redir[5])(char **, t_list *, char **);
  int		k;

  k = 0;
  while (tmp[k])
    k++;
  if (k >= 3)
    {
      redir[0] = my_pipe;
      redir[1] = double_right_redir;
      redir[2] = double_left_redir;
      redir[3] = right_redir;
      redir[4] = left_redir;
      if (redir[find_redir(tmp[1])](tmp, list, path) == ERROR)
	return (ERROR);
    }
  else
    if (no_redir(tmp[0], list, path) == ERROR)
      return (ERROR);
  return (0);
}

int		red(char **tmp, t_list *list, char **path)
{
  int		forkval;
  int		status;

  if (is_a_builtin(tmp) == ERROR)
    {
      if ((forkval = fork()) == -1)
	{
	  my_printf("Fork couldn't be done\n");
	  return (ERROR);
	}
      if (forkval == 0)
	{
	  if (choose_redir(tmp, list, path) == ERROR)
	    return (ERROR);
	}
      else
	wait(&status);
    }
  else if (choose_redir(tmp, list, path) == ERROR)
    return (ERROR);
  return (0);
}
