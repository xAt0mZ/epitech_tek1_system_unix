/*
** basics.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/tree
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 16:38:32 2013 Garnero Philip
** Last update Sun May 26 16:10:15 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

int		my_strcmp(char *str, char *find)
{
  int		i;

  if (!str || !find)
    return (ERROR);
  i = 0;
  while (str[i] && find[i])
    {
      if (str[i] != find[i])
	return (ERROR);
      i++;
    }
  if (str[i] == '\0' && find[i] == '\0')
    return (0);
  else
    return (ERROR);
}

char		*my_strdup(char *str)
{
  int		i;
  char		*res;

  i = my_strlen(str);
  if ((res = malloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}

char	*my_strcat(char *dest, char *src)
{
  int   i;
  int   n;

  n = 0;
  i = 0;
  while (dest[i])
    i = i + 1;
  while (src[n])
    {
      dest[i] = src[n];
      i = i + 1;
      n = n + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strccat(char *dest, char *src, int c)
{
  int   i;
  int   n;

  n = c;
  i = 0;
  while (dest[i])
    i = i + 1;
  while (src[n])
    {
      dest[i] = src[n];
      i = i + 1;
      n = n + 1;
    }
  dest[i] = '\0';
  return (dest);
}

void	del_case(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      str[i] = str[i + 1];
      i++;
    }
}
