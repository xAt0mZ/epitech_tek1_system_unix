/*
** types.c for printf in /home/baron_l//local/rendu/piscine/projets/printf
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Nov 14 17:57:26 2012 louis-philippe baron
** Last update Fri Nov 30 11:41:41 2012 louis-philippe baron
*/

#include	"hprintf.h"

void		simp_type(char c, va_list varl)
{
  if (c == 'd' || c == 'i')
    my_putnbr(va_arg(varl, int));
  else if (c == 's')
    my_putstr(va_arg(varl, char *));
  else if (c == 'u')
    my_putnbr_base(va_arg(varl, unsigned int), "0123456789");
  else if (c == 'x')
    my_putnbr_base(va_arg(varl, unsigned int), "0123456789abcdef");
  else if (c == 'X')
    my_putnbr_base(va_arg(varl, unsigned int), "0123456789ABCDEF");
  else if (c == 'b')
    my_putnbr_base(va_arg(varl, unsigned int), "01");
  else if (c == 'o')
    my_putnbr_base(va_arg(varl, unsigned int), "01234567");
  else if (c == 'S')
    my_showstr(va_arg(varl, char *), "01234567");
}

void		comp_type(char c, va_list varl)
{
  unsigned char	r;
  long		l;

  if (c == 'p')
    {
      l = (long)va_arg(varl, void *);
      my_putstr("0x");
      my_putnbr_base(l, "0123456789abcdef");
    }
  if (c == 'c')
    {
      r = (unsigned char)va_arg(varl, int);
      my_putchar(r);
    }
}
