/*
** exec.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Dec 26 13:02:52 2012 louis-philippe baron
** Last update Mon Mar  4 17:41:35 2013 louis-philippe baron
*/

#include	"hminishell1.h"

static char	*concat_exe(char *command, char *path)
{
  int		s1;
  int		s2;
  char		*exe;

  s1 = my_strlen(command);
  s2 = my_strlen(path);
  if ((exe = malloc((s1 + s2 + 2) * sizeof(char))) == NULL)
    return (NULL);
  s1 = 0;
  s2 = 0;
  while (path[s1])
    exe[s2++] = path[s1++];
  exe[s2++] = '/';
  s1 = 0;
  while (command[s1])
    exe[s2++] = command[s1++];
  exe[s2] = '\0';
  return (exe);
}

static int	infork(char **command, char **path, char **env)
{
  int		i;
  char		*exe;

  if (exec_command(command[0], command, env) == ERROR)
    {
      i = 0;
      if ((exe = concat_exe(command[0], path[i])) == NULL)
	return (ERROR);
      while (exec_command(exe, command, env) == ERROR)
	{
	  i++;
	  if (path[i] == NULL)
	    return (ERROR);
	  if ((exe = concat_exe(command[0], path[i])) == NULL)
	    {
	      my_printf("Cannot concat exe\n");
	      return (ERROR);
	    }
	}
      free(exe);
    }
  return (0);
}

int		exec(char **command, char **path, char **env)
{
  if ((command[0][0] == '/' &&
       exec_command(command[0], command, env) == ERROR)
      || (command[0][0] == '.' &&
	  exec_command(command[0], command, env) == ERROR)
      || (command[0][0] != '/' && command[0][0] != '.' &&
	  infork(command, path, env) == ERROR))
    return (ERROR);
  free_wordtab(command);
  return (0);
}
