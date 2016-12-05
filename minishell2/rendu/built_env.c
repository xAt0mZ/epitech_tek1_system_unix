/*
** built_env.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Dec 28 17:15:34 2012 louis-philippe baron
** Last update Fri Mar  1 11:32:59 2013 louis-philippe baron
*/

#include	"hminishell1.h"

int		built_env(char **command, t_list *list)
{
  int		i;

  i = 0;
  (void)command;
  while (list->env[i])
    {
      my_printf("%s\n", list->env[i]);
      i++;
    }
  return (0);
}
