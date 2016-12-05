/*
** basics.c for minitalk server in /home/baron_l//local/rendu/projets/system_unix/minitalk/rendu/server
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Mar 18 11:56:40 2013 louis-philippe baron
** Last update Wed Mar 20 16:16:19 2013 louis-philippe baron
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

int		my_putnbr(int nb)
{
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
  return (0);
}

int		my_getnbr(unsigned char *str)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (i < 8)
    {
      nb = nb * 2 + str[i];
      i++;
    }
  return (nb);
}

int		my_pow(int nb, int pow)
{
  int		res;
  int		i;

  res = 1;
  i = 0;
  while (i <= pow)
    {
      res *= nb;
      i++;
    }
  return (res);
}
