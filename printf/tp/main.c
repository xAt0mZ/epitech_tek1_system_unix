/*
** main.c for tp_printf in /home/baron_l//local/rendu/piscine/projets/printf/tp
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Tue Nov 13 09:21:23 2012 louis-philippe baron
** Last update Tue Nov 13 11:03:35 2012 louis-philippe baron
*/

#include	"header.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

void		my_putnbr(int nb)
{
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
}

int		fct(int param1, struct ex2 param2, char *param3)
{
  int		*ptr;
  struct ex2	*ptr2;
  char		**ptr3;

  ptr = &param1;
  my_putnbr(ptr);
  my_putchar('\n');
  my_putnbr(param1);
  my_putchar('\n');
  ptr2 = &param2;
  my_putnbr(ptr2);
  my_putchar('\n');
  my_putchar(param2.c);
  my_putnbr(param2.i);
  my_putnbr(param2.s);
  my_putchar('\n');
  ptr3 = &param3;
  my_putnbr(ptr3);
  my_putchar('\n');
  my_putstr(param3);
  my_putchar('\n');
  return (0);
}

int		main(int ac, char **av)
{
  struct ex2 toto;

  toto.c = 'u';
  toto.i = 9999;
  toto.s = 1818;
  fct(25, toto, "424242");
  return (0);
}
