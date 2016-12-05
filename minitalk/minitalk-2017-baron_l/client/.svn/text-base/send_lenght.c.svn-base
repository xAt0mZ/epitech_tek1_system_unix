/*
** send_lenght.c for minitalk client in /home/baron_l//local/rendu/projets/system_unix/minitalk/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Mar 18 19:42:03 2013 louis-philippe baron
** Last update Wed Mar 20 16:15:36 2013 louis-philippe baron
*/

#include	"hminitalk.h"

static int	get_len(unsigned char c, unsigned char *tab)
{
  int		i;

  i = 0;
  while (i < 8)
    tab[i++] = 0;
  i = 7;
  while (i >= 0)
    {
      tab[i] = c % 2;
      c /= 2;
      i--;
    }
  return (0);
}

int		send_lenght(int len, int pid)
{
  unsigned char	str[4];
  unsigned char	tab[8];
  int		i;

  i = 3;
  while (i >= 0)
    {
      str[i] = len % 256;
      len = len / 256;
      i--;
    }
  i = 0;
  while (i <= 3)
    {
      get_len(str[i], tab);
      if (print_char(tab, pid) == ERROR)
	return (ERROR);
      usleep(TIME);
      i++;
    }
  return (0);
}
