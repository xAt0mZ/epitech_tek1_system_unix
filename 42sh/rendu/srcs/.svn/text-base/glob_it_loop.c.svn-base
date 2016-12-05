/*
** glob_it_loop.c for 42sh in /home/baron_l//local/rendu/projets/system_unix/42sh/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri May 24 18:41:58 2013 louis-philippe baron
** Last update Sun May 26 16:17:43 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

static char	*glob_line(char *str, char *param, char bool, char mod)
{
  char		*res;
  int		i;

  i = 0;
  res = str;
  while (!mod && str[i])
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      if (is_in(str[i], param, bool) == 0)
	{
	  if ((res = glob_return(str)) == NULL)
	    return (NULL);
	  mod = 1;
	}
      i++;
    }
  return (res);
}

int		glob_loop(char **tmp, char *param)
{
  int		k;

  k = 0;
  while (tmp[k])
    {
      if ((tmp[k] = glob_line(tmp[k], param, 0, 0)) == NULL)
	return (ERROR);
      k++;
    }
  return (0);
}
