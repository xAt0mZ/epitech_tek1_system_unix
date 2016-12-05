/*
** wordtabs.c for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sun Dec  2 21:26:10 2012 louis-philippe baron
** Last update Sun Dec  2 21:54:47 2012 louis-philippe baron
*/

#include	<stdlib.h>
#include	"hmy_ls.h"

int		sort_wordtab(char **wdtb)
{
  int		k;

  k = 0;
  while (wdtb[k])
    {
      my_printf("%s\n", wdtb[k]);
      k++;
    }
  return (0);
}

int		swap_alpha(char **wdtb)
{
  int		k;
  int		i;
  char		*tmp;

  k = 1;
  while (wdtb[k])
    {
      i = 0;
      while (ISMAJ(wdtb[k][i]) == ISMAJ(wdtb[k - 1][i]) &&
	     (wdtb[k][i] != '\0' && wdtb[k - 1][i] != '\0'))
	i++;
      if (ISMAJ(wdtb[k][i]) < ISMAJ(wdtb[k - 1][i]))
	{
	  tmp = wdtb[k];
	  wdtb[k] = wdtb[k - 1];
	  wdtb[k - 1] = tmp;
	  k = 0;
	}
      k++;
    }
  return (0);
}

char		**put_to_wordtab(char *str, char **wdtb)
{
  char		*line;
  int		k;
  int		i;
  char		**res;

  k = 0;
  while (wdtb[k])
    k++;
  if ((res = malloc((k + 2) * sizeof(*res))) != NULL)
    if ((line = malloc((my_strlen(str) + 1) * sizeof(char))) != NULL)
      {
	k = 0;
	while (wdtb[k])
	  res[k] = wdtb[k++];
	i = 0;
	while (str[i])
	  line[i] = str[i++];
	line[i] = '\0';
	res[k] = line;
	res[k + 1] = NULL;
      }
  free(wdtb);
  return (res);
}
