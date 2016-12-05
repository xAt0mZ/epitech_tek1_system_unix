/*
** env.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sun Dec 30 13:10:06 2012 louis-philippe baron
** Last update Sun Dec 30 20:54:07 2012 louis-philippe baron
*/

#include	"hminishell1.h"

char		**define_env(int clonesize)
{
  char		**res;

  if ((res = malloc(clonesize * sizeof(char *))) == NULL)
    return (NULL);
  if ((res[0] = create_inex_path()) == NULL)
    return (NULL);
  res[1] = NULL;
  return (res);
}

char		**clone_ptrs(char **env, int clonesize)
{
  char		**res;
  int		i;

  if ((res = malloc(clonesize * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  while (env[i])
    {
      res[i] = env[i];
      i++;
    }
  res[i] = NULL;
  free(env);
  return (res);
}

char		**get_simple_env(char **env, int clonesize, int k)
{
  char		**res;
  int		i;

  if (k == 0)
    {
      if ((res = malloc(clonesize * sizeof(char *))) == NULL)
	return (NULL);
      i = 0;
      while (env[i])
	{
	  if ((res[i] = my_strcpy(env[i])) == NULL)
	    return (NULL);
	  i++;
	}
      res[i] = NULL;
    }
  else
    if ((res = clone_ptrs(env, clonesize)) == NULL)
      return (NULL);
  return (res);
}

char		**clone_env(char **env, int clonesize, int k)
{
  char		**res;

  if ((env && env[0] == NULL) || (env == NULL))
    {
      if ((res = define_env(clonesize)) == NULL)
	{
	  my_printf("Problem in memory allocation during env setting\n");
	  return (NULL);
	}
    }
  else
    {
      if ((res = get_simple_env(env, clonesize, k)) == NULL)
	{
	  my_printf("Problem in memory allocation during env parsing\n");
	  return (NULL);
	}
    }
  return (res);
}
