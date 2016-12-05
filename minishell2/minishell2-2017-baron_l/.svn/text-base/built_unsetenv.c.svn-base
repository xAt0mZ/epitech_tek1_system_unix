/*
** built_unsetenv.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Dec 28 17:15:11 2012 louis-philippe baron
** Last update Fri Mar  1 11:34:37 2013 louis-philippe baron
*/

#include	"hminishell1.h"

int		unset(char *name, char **env)
{
  int		i;

  i = 0;
  while (env[i] && my_strcmp(env[i], name) == ERROR)
    i++;
  if (env[i])
    {
      free(env[i]);
      while (env[i])
	{
	  env[i] = env[i + 1];
	  i++;
	}
    }
  return (0);
}

int		built_unsetenv(char **command, t_list *list)
{
  int		i;

  i = command_size(command);
  if (i == 1)
    my_printf("unsetenv: Too few arguments.\n");
  else
    {
      i = 1;
      while (command[i])
	{
	  unset(command[i], list->env);
	  i++;
	}
    }
  return (0);
}
