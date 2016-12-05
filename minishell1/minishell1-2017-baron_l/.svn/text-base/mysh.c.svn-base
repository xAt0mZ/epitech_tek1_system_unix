/*
** mysh.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Dec 17 15:45:17 2012 louis-philippe baron
** Last update Sun Dec 30 20:47:35 2012 louis-philippe baron
*/

#include	"hminishell1.h"

char		**get_path(char **env)
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

int		mysh(char *input, char **env)
{
  char		**command;
  char		**path;
  int		retvalue;

  retvalue = 0;
  if ((command = my_str_to_wordtab(input, " ")) == NULL)
    {
      my_printf("Problem in memory allocation during command parsing\n");
      return (ERROR);
    }
  free(input);
  if (is_a_builtin(command) != ERROR)
    retvalue = exec_builtin(command, env);
  else
    {
      if ((path = get_path(env)) == NULL)
	return (ERROR);
      retvalue = exec(command, path, env);
      free_wordtab(path);
    }
  free_wordtab(command);
  return (retvalue);
}
