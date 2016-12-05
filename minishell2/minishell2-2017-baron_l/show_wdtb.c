/*
** show_wdtb.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell2/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Feb 18 14:43:46 2013 louis-philippe baron
** Last update Mon Feb 18 14:47:25 2013 louis-philippe baron
*/

#include	"hminishell1.h"

int		show_wdtb(char **tab)
{
  int		j;

  j = 0;
  while (tab[j])
    {
      my_putstr(tab[j]);
      my_putchar('\n');
      j++;
    }
  return (0);
}
