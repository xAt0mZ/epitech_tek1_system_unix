/*
** printf.c for printf in /home/baron_l//local/rendu/piscine/projets/printf
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Tue Nov 13 14:24:24 2012 louis-philippe baron
** Last update Tue Dec 18 09:39:27 2012 louis-philippe baron
*/

#include	"hminishell1.h"

void		do_print(char c, va_list varl)
{
  if (c == 'd')
    my_putnbr(va_arg(varl, int));
  else if (c == 's')
    my_putstr(va_arg(varl, char *));
}

int		my_printf(char *str, ...)
{
  va_list	varl;
  int		i;

  i = 0;
  va_start(varl, str);
  while (str[i] != '\0')
    {
      if (i >= 1 && str[i] == '%' && str[i - 1] == '%')
	i++;
      if (str[i] == '%')
	{
	  do_print(str[i + 1], varl);
	  i++;
	}
      else
	my_putchar(str[i]);
      i++;
    }
  va_end(varl);
  return (0);
}
