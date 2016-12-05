/*
** built_env.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Dec 28 17:15:34 2012 louis-philippe baron
** Last update Sun Dec 30 20:20:05 2012 louis-philippe baron
*/

#include	"hminishell1.h"

int		built_env(char **command, char **env)
{
  int		i;

  i = 0;
  command[0] = command[0];
  while (env[i])
    {
      my_printf("%s\n", env[i]);
      i++;
    }
  return (0);
}
