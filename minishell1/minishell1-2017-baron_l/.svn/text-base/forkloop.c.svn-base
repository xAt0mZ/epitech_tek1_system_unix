/*
** forkloop.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Dec 28 13:26:11 2012 louis-philippe baron
** Last update Sun Dec 30 17:08:03 2012 louis-philippe baron
*/

#include	"hminishell1.h"

int		exec_command(char *exe, char **command, char **env)
{
  char		*tmp;

  tmp = command[0];
  command[0] = exe;
  if (execve(exe, command, env) == -1)
    {
      command[0] = tmp;
      return (ERROR);
    }
  return (0);
}
