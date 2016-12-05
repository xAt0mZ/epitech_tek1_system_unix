/*
** mysh.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Dec 17 15:45:17 2012 louis-philippe baron
** Last update Sun May 26 22:46:45 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	"h42.h"

int	free_wordtab(char **res)
{
  int		i;

  i = 0;
  while (res[i])
    {
      free(res[i]);
      i++;
    }
  free(res);
  return (0);
}

int	show_wdtb(char **tab)
{
  int		j;

  j = 0;
  while (tab[j])
    {
      my_putchar('{');
      my_putstr(tab[j]);
      my_putchar('}');
      my_putchar('\n');
      j++;
    }
  return (0);
}

static int	in_command(char *command, t_glob *glob)
{
  char		**tmp;

  if (check_quotes(command) == ERROR)
    return (0);
  if ((tmp = my_command_to_wordtab(command, "|&")) == NULL)
    return (error_int("Memory allocation error on command parsing\n"));
  if (check_command_tab(tmp) == ERROR)
    return (0);
  if (!(tmp = cut_redir_tab(tmp, glob)))
    {
      if (glob->retval == ERROR)
	return (ERROR);
      return (SUCCESS);
    }
  if (check_conflict_redir(tmp) == ERROR)
    return (SUCCESS);
  if (tree_call(tmp, glob) == ERROR)
    return (ERROR);
  free_wordtab(tmp);
  return (0);
}

static int	exec_separated_command(char **command, t_glob *glob)
{
  int		k;

  k = 0;
  while (command[k])
    {
      if (command[k][0] && in_command(command[k], glob) == ERROR)
      	return (ERROR);
      k++;
    }
  return (0);
}

int		mysh(t_glob *glob)
{
  char		**command;

  if (dev_urandom(glob->input) == ERROR)
    {
      free(glob->input);
      return (0);
    }
  if ((glob->input = epur_str(glob->input, "><|;&", 0)) == NULL)
    return (ERROR);
  if (glob->input[0] == '\0')
    {
      free(glob->input);
      return (0);
    }
  if ((glob->input = glob_it(glob->input, "*?[]{}")) == NULL)
    return (ERROR);
  if ((glob->input = epur_str(glob->input, "><|;&", 0)) == NULL)
    return (ERROR);
  if ((command = my_str_to_wordtab(glob->input, ";")) == NULL)
    return (error_int("Memory allocation error on command parsing\n"));
  free(glob->input);
  if (exec_separated_command(command, glob) == ERROR)
    return (ERROR);
  free_wordtab(command);
  return (0);
}
