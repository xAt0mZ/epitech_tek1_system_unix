/*
** basics.c for printf in /home/baron_l//local/rendu/piscine/projets/printf
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Tue Nov 13 16:59:06 2012 louis-philippe baron
** Last update Fri Nov 30 11:41:21 2012 louis-philippe baron
*/

#include	"hprintf.h"

int	my_putnbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  if (nb == -2147483648)
    {
      my_putstr("2147483648");
      return (0);
    }
  if (nb > 9)
     my_putnbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return (0);
}
