/*
** built_exit.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Dec 28 17:14:17 2012 louis-philippe baron
** Last update Mon Mar  4 16:43:33 2013 louis-philippe baron
*/

#include	"hminishell1.h"

static int	check_exit_val(char *str)
{
  int		i;

  i = 0;
  if (str[i] == '-')
    i++;
  while (str[i])
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	{
	  my_printf("exit: Expression Syntax.\n");
	  return (ERROR);
	}
      i++;
    }
  return (0);
}

int		built_exit(char **command, t_list *list)
{
  int		nb;
  char		ex_val;

  ex_val = 0;
  if (command[1])
    {
      if (check_exit_val(command[1]) == ERROR)
	return (0);
      nb = my_getnbr(command[1]);
      ex_val = (char)nb;
    }
  my_printf("exit\n");
  free_wordtab(command);
  free_wordtab(list->env);
  free_wordtab(list->coma);
  free_wordtab(list->redir);
  free_wordtab(list->path);
  exit(ex_val);
}
