/*
** find_term.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Jan 16 19:58:23 2013 louis-philippe baron
** Last update Sun Jan 20 19:50:28 2013 louis-philippe baron
*/

#include	"hselect.h"

static	char	*get_term(char *str)
{
  char		*res;
  int		i;
  int		k;

  i = 0;
  while (str[i] != '=')
    i++;
  k = i;
  while (str[i])
    i++;
  if ((res = malloc((i - k + 1) * sizeof(char))) == NULL)
    {
      my_putstr("Error in memory allocation.\n", 2);
      return (NULL);
    }
  i = 0;
  k++;
  while (str[k])
    res[i++] = str[k++];
  res[i] = '\0';
  return (res);
}

char		*find_term(char **env)
{
  int		k;

  k = 0;
  if (env == NULL || env[0] == NULL)
    my_putstr("Env is NULL.\n", 2);
  else
    {
      while (env[k])
	{
	  if (my_strcmp(env[k], "TERM") == 0)
	    return (get_term(env[k]));
	  k++;
	}
      my_putstr("Can not find a TERM variable in env.\n", 2);
    }
  return (NULL);
}
