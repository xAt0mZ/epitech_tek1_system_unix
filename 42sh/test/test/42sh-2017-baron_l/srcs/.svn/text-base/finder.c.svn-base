/*
** finder.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/tree
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 17:13:26 2013 Garnero Philip
** Last update Sun May 26 16:14:15 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

int	get_env(char **env, t_list **envi)
{
  int	i;

  i = 0;
  *envi = NULL;
  if (env[0] == NULL)
    {
      if (my_put_in_list(envi, "PWD=/") == ERROR)
	return (ERROR);
      if (my_put_in_list(envi, "OLDPWD=/") == ERROR)
	return (ERROR);
    }
  else
    {
      while (env[i])
	{
	  if ((my_put_in_list(envi, env[i])) == ERROR)
	    return (ERROR);
	  i = i + 1;
	}
    }
  return (0);
}

t_list		*finder(char *to_find, t_list *envi)
{
  t_list	*tmp;
  int		i;
  int		res;

  tmp = envi;
  while (tmp)
    {
      if (tmp->comp)
	{
	  i = 0;
	  res = 0;
	  while (to_find[i])
	    {
	      if (to_find[i] == tmp->comp[i])
		res = res + 1;
	      i = i + 1;
	    }
	  if (res == i && tmp->comp[i] == '=')
	    return (tmp);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

char		**transform_list(t_list *envi)
{
  t_list	*tmp;
  char		**path;
  int		i;

  tmp = envi;
  i = 1;
  while (tmp->next)
    {
      tmp = tmp->next;
      i = i + 1;
    }
  if ((path = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (error_ptr(MALLOC_ERROR));
  path[i--] = NULL;
  while (i >= 0)
    {
      path[i] = tmp->comp;
      tmp = tmp->prev;
      i = i - 1;
    }
  return (path);
}
