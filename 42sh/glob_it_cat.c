/*
** glob_it_cat.c for 42sh in /home/baron_l//local/rendu/projets/system_unix/42sh/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri May 24 21:17:56 2013 louis-philippe baron
** Last update Sat May 25 16:07:57 2013 louis-philippe baron
*/

#include	"h42.h"

static char	*my_cat_for_glob(char *s1, char *s2)
{
  char		*res;
  int		i;
  int		j;

  j = my_strlen(s1) + my_strlen(s2);
  if ((res = malloc((j + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (s1[i])
    res[j++] = s1[i++];
  i = 0;
  while (s2[i])
    res[j++] = s2[i++];
  res[j] = '\0';
  free(s1);
  return (res);
}

char		*glob_cat_all(char **tab)
{
  char		*res;
  int		k;

  k = 0;
  if ((res = malloc(sizeof(char))) == NULL)
    return (error_ptr(MALLOC_ERROR));
  res[0] = '\0';
  while (tab[k])
    {
      if ((res = my_cat_for_glob(res, tab[k])) == NULL)
	return (error_ptr(MALLOC_ERROR));
      k++;
    }
  return (res);
}
