/*
** get_mode.c for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Nov 29 13:35:45 2012 louis-philippe baron
** Last update Thu Nov 29 16:16:29 2012 louis-philippe baron
*/

#include	"hmy_ls.h"
#include	<stdlib.h>

char		*get_mode(int nb, char *base)
{
  int		i;
  int		j;
  char		*res;
  char		tmp;

  i = my_strlen(base);
  if ((res = malloc(7 * sizeof(char))) == NULL)
    return (NULL);
  j = 0;
  while (nb != 0)
    {
      res[j++] = base[nb % i];
      nb = nb / i;
    }
  res[j] = '\0';
  i = 0;
  j = my_strlen(res) - 1;
  while (i < j)
    {
      tmp = res[i];
      res[i] = res[j];
      res[j--] = tmp;
      i++;
    }
   return (res);
}

char		*fill_mode_res(char *mode, char *res, int i, int j)
{
  while (j != (my_strlen(mode) - 4))
    {
      if (mode[j] == '0')
	{
	  res[i] = '-';
	  res[i - 1] = '-';
	  res[i - 2] = '-';
	}
      if (mode[j] == '1' || mode[j] == '3'
	  || mode [j] == '5' || mode[j] == '7')
	res[i] = 'x';
      if (mode[j] == '2' || mode[j] == '3'
	  || mode[j] == '6' || mode[j] == '7')
	res[i - 1] = 'w';
      if (mode[j] == '4' || mode[j] == '6'
	  || mode[j] == '5' || mode[j] == '7')
	res[i - 2] = 'r';
      j--;
      i = i - 3;
    }
  return (res);
}

char		*get_rights(char *mode)
{
  int		i;
  char		*res;
  int		j;

  if ((res = my_malloc(11 * sizeof(char))) == NULL)
    return (NULL);
  i = 9;
  j = my_strlen(mode) - 1;
  res = fill_mode_res(mode, res, i, j);
  return (res);
}
