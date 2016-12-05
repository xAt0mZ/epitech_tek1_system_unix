/*
** basics2.c for printf in /home/baron_l//local/rendu/piscine/projets/printf
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Nov 14 12:54:28 2012 louis-philippe baron
** Last update Wed Nov 14 17:00:04 2012 louis-philippe baron
*/

#include	"hmy.h"

int		my_putnbr_base(unsigned int nb, char *base)
{
  int		i;

  i = my_strlen(base);
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  if (nb == 0)
    return (0);
  my_putnbr_base(nb / i, base);
  my_putchar(base[nb % i]);
  return (0);
}

int		my_showstr(char *str, char *base)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 32 && str[i] <= 126))
	{
	  my_putchar('\\');
	  if (str[i] > 0 && str[i] < 16)
	    my_putchar('0');
	  my_putnbr_base(str[i], base);
	}
      else
	my_putchar(str[i]);
      i++;
    }
  return (0);
}
