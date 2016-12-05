/*
** r_option.c for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sun Dec  2 21:55:13 2012 louis-philippe baron
** Last update Sun Dec  2 22:02:40 2012 louis-philippe baron
*/

#include	"hmy_ls.h"

int		r_option(char **wdtb)
{
  int		k;
  int		i;
  int		max;
  char		*tmp;

  k = 0;
  i = 0;
  while (wdtb[k])
    k++;
  k--;
  max = k;
  while (i < max / 2)
    {
      tmp = wdtb[i];
      wdtb[i] = wdtb[k];
      wdtb[k] = tmp;
      k++;
      i++;
    }
  return (0);
}
