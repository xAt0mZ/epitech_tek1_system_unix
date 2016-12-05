/*
** int_siders.c for siders in /home/garner_p/Save/lib/functions
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Fri Dec 14 16:19:55 2012 Garnero Philip
** Last update Wed May 22 17:20:41 2013 Garnero Philip
*/

#include	"h42.h"

static void	my_gettnbr(char *str, int *ptresult)
{
  int	j;

  j = 0;
  while (str[j])
    {
      if (str[j] == '-' && str[j + 1] > 47 && str[j + 1] < 58)
	*ptresult *= -1;
      j = j + 1;
    }
}

int	my_getnbr(char *str)
{
  int	i;
  int	result;

  i = 0;
  result = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 47 && str[i] < 58)
	result = (str[i] - 48) + (result * 10);
      i = i + 1;
      if (result != 0 && (str[i] < 48 || str[i] > 57))
	{
	  my_gettnbr(str, &result);
	  return (result);
	}
    }
  my_gettnbr(str, &result);
  return (result);
}

static void    my_putt_nbr(int n)
{
  int   nb;

  nb = n % 10;
  n = n / 10;
  if (n != 0)
    my_putt_nbr(n);
  if (nb < 0)
    nb *= -1;
  my_putchar('0' + nb);
}

void    my_put_nbr(int nb)
{
  if (nb < 0)
    my_putchar('-');
  my_putt_nbr(nb);
}
