/*
** built_cd.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Dec 28 17:14:00 2012 louis-philippe baron
** Last update Fri Mar  1 11:32:02 2013 louis-philippe baron
*/

#include	"hminishell1.h"

int		check_access(char *str)
{
  t_stat	t_stat;

  if (stat(str, &t_stat) == -1)
    {
      my_printf("%s: No such file or directory.\n", str);
      return (0);
    }
  if ((t_stat.st_mode & S_IXUSR) == 0)
    my_printf("%s: Access denied\n", str);
  return (0);
}

char		*cut_home(char *env)
{
  int		i;
  int		k;
  char		*home;

  i = 0;
  while (env[i] != '=')
    i++;
  i++;
  k = i;
  while (env[k])
    k++;
  if ((home = malloc((k - i + 1) * sizeof(char))) == NULL)
    return (NULL);
  k = 0;
  while (env[i])
    home[k++] = env[i++];
  home[k] = '\0';
  return (home);
}

char		*get_home(char **env)
{
  int		i;
  char		*home;

  i = 0;
  while (env[i] && my_strcmp(env[i], "HOME") == ERROR)
    i++;
  if (env[i] == NULL)
    {
      my_printf("There is no HOME variable in env, can't change dir.\n");
      return (NULL);
    }
  if ((home = cut_home(env[i])) == NULL)
    {
      my_printf("Problem during HOME finding.\n");
      return (NULL);
    }
  return (home);
}

int		built_cd(char **command, t_list *list)
{
  int		chdirval;
  char		*home;

  if (command[1] == NULL || command[1][0] == '\0'
      || (command[1][0] == '~' && command[1][1] == '\0'))
    {
      if ((home = get_home(list->env)) == NULL)
	return (ERROR);
      if ((chdirval = chdir(home)) == -1)
  	check_access(home);
      free(home);
    }
  else if (command[1][0] == '-' && command[1][1] == '\0')
    my_printf("{cd -} not implemented yet\n");
  else
    {
      if ((chdirval = chdir(command[1])) == -1)
  	check_access(command[1]);
    }
  return (0);
}
