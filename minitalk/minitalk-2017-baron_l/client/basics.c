/*
** basics.c for minitalk client in /home/baron_l//local/rendu/projets/system_unix/minitalk/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Mar 18 15:00:16 2013 louis-philippe baron
** Last update Wed Mar 20 15:00:59 2013 louis-philippe baron
*/

#include	"hminitalk.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int		my_getnbr(char *str)
{
  int		nb;
  int		i;

  i = 0;
  nb = 0;
  while (str[i])
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (ERROR);
      nb = nb * 10 + (str[i] - '0');
      i++;
    }
  return (nb);
}
