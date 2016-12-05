/*
** built_setenv.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Dec 28 17:14:40 2012 louis-philippe baron
** Last update Sun Dec 30 19:07:39 2012 louis-philippe baron
*/

#include	"hminishell1.h"

char		*concat_envarg(char *name, char *value)
{
  int		i;
  int		j;
  char		*res;

  i = my_strlen(name);
  j = 0;
  if (value)
    j = my_strlen(value);
  if ((res = malloc((i + j + 2) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (name[j])
    res[i++] = name[j++];
  res[i++] = '=';
  j = 0;
  if (value)
    while (value[j])
    res[i++] = value[j++];
  res[i] = '\0';
  return (res);
}

int		modify_envarg(char **command, char **env, int i)
{
  char		*res;

  if ((res = concat_envarg(command[1], command[2])) == NULL)
    return (ERROR);
  if (env[i])
    free(env[i]);
  else
    env[i + 1] = NULL;
  env[i] = res;
  return (0);
}

int		built_setenv(char **command, char **env)
{
  int		i;
  int		retvalue;

  i = command_size(command);
  retvalue = 0;
  if (i > 3)
    my_printf("setenv: Too many arguments.\n");
  else if (i == 1)
    built_env(command, env);
  else
    {
      i = 0;
      while (env[i] && my_strcmp(env[i], command[1]) == ERROR)
	i++;
      retvalue = modify_envarg(command, env, i);
    }
  return (retvalue);
}
