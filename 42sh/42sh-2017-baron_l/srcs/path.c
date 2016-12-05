/*
** path.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/tree
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 17:38:29 2013 Garnero Philip
** Last update Sun May 26 16:22:30 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

static char	*cutter(char *path, int *i)
{
  char		*little;
  int		j;

  if ((little = malloc(sizeof(char) * 250)) == NULL)
    return (error_ptr(MALLOC_ERROR));
  j = 0;
  while (path[*i] != ':' && path[*i] != '\0')
    {
      little[j] = path[*i];
      *i = *i + 1;
      j = j + 1;
      if (j > 200)
	return (error_ptr("One path in the env PATH section is too long\n"));
    }
  if (path[*i] == ':')
    *i = *i + 1;
  little[j] = '/';
  little[j + 1] = '\0';
  return (little);
}

char	**get_path(char *to_cut)
{
  int	j;
  int	c;
  int	count;
  char	**path;

  count = 1;
  j = 0;
  while (to_cut[j])
    {
      if (to_cut[j] == ':')
	count = count + 1;
      j = j + 1;
    }
  if ((path = malloc(sizeof(char *) * (count + 1))) == NULL)
    return (error_ptr(MALLOC_ERROR));
  j = 0;
  c = 5;
  while (count)
    {
      path[j] = cutter(to_cut, &c);
      j = j + 1;
      count = count - 1;
    }
  path[j] = NULL;
  return (path);
}
