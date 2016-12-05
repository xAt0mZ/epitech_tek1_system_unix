/*
** builtins.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Dec 28 11:31:14 2012 louis-philippe baron
** Last update Sun Dec 30 18:10:37 2012 louis-philippe baron
*/

#include	"hminishell1.h"

int		command_size(char **command)
{
  int		i;

  i = 0;
  while (command[i])
    i++;
  return (i);
}

int		is_a_builtin(char **command)
{
  if (my_strcmp(command[0], "cd") == ERROR &&
      my_strcmp(command[0], "setenv") == ERROR &&
      my_strcmp(command[0], "unsetenv") == ERROR &&
      (my_strcmp(command[0], "env") == ERROR ||
       (my_strcmp(command[0], "env") != ERROR && command[1] != NULL)) &&
      my_strcmp(command[0], "exit") == ERROR)
    return (ERROR);
  return (0);
}

int		find_builtin(char *command)
{
  int		i;

  if (my_strcmp(command, "cd") != ERROR)
    i = 0;
  else if (my_strcmp(command, "setenv") != ERROR)
    i = 1;
  else if (my_strcmp(command, "unsetenv") != ERROR)
    i = 2;
  else if (my_strcmp(command, "env") != ERROR)
    i = 3;
  else if (my_strcmp(command, "exit") != ERROR)
    i = 4;
  return (i);
}

int		exec_builtin(char **command, char **env)
{
  int		i;
  int		(*builtins[5])(char **, char **);

  builtins[0] = built_cd;
  builtins[1] = built_setenv;
  builtins[2] = built_unsetenv;
  builtins[3] = built_env;
  builtins[4] = built_exit;
  i = find_builtin(command[0]);
  if (builtins[i](command, env) == ERROR)
    return (ERROR);
  return (0);
}
