/*
** glob_it_clean.c for 42sh in /home/baron_l//local/rendu/projets/system_unix/42sh/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri May 24 18:08:27 2013 louis-philippe baron
** Last update Fri May 24 21:42:14 2013 louis-philippe baron
*/

#include	"h42.h"

static int	glob_fill(char **tab, char **res)
{
  int		j;
  int		k;

  j = 0;
  k = 0;
  while (tab[k])
    {
      if (tab[k][0])
	{
	  res[j] = tab[k];
	  j += 1;
	}
      else
      	free(tab[k]);
      k += 1;
    }
  res[j] = NULL;
  return (0);
}

char		**clean_it(char **tab)
{
  char		**res;
  int		j;
  int		k;

  j = 0;
  k = 0;
  while (tab[k])
    {
      if (tab[k][0])
	j += 1;
      k += 1;
    }
  if ((res = malloc((j + 1) * sizeof(char *))) == NULL)
    return (NULL);
  glob_fill(tab, res);
  free(tab);
  return (res);
}
