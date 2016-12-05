/*
** printf.c for printf in /home/baron_l//local/rendu/piscine/projets/printf
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Tue Nov 13 14:24:24 2012 louis-philippe baron
** Last update Fri Nov 30 12:34:25 2012 louis-philippe baron
*/

#include	"hprintf.h"

int		is_a_type(char c)
{
  if (c == 'd' || c == 'i' || c == 's' || c == 'u' || c == 'x' ||
      c == 'X' || c == 'p' || c == 'b' || c == 'S' || c == 'c' || c == 'o')
    return (1);
  else if (c == '.' || c == 'e' || c == 'E' || c == 'f' || c == 'F' ||
	   c == 'g' || c == 'G' || c == 'a' || c == 'A' || c == '#' ||
	   c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
	   c == '5' || c == '6' || c == '7' || c == '8' || c == '9' ||
	   c == '-' || c == ' ' || c == '+' || c == '\'' || c ==  'I' ||
	   c == 'h' || c == 'l' || c == 'L' || c == 'q' || c == 'j' ||
	   c == 'z' || c == 't')
    return (2);
  else
    return (0);
}

void		select_way(char c, va_list varl, char *str)
{
  int		i;

  i = 0;
  if (is_a_type(c) == 1)
    do_print(c, varl);
  else
    {
      while (is_a_type(str[i]) != 1 && str[i] != '%')
	i++;
      if (is_a_type(str[i]) == 1 && (str[i] == 'd' ||
      				     str[i] == 'i' || str[i] == 'c'))
      	va_arg(varl, int);
      else if (is_a_type(str[i]) == 1 && str[i] == 'p')
      	va_arg(varl, void *);
      else if (is_a_type(str[i]) == 1 && (str[i] == 'S' || str[i] == 's'))
      	va_arg(varl, char *);
      else if (is_a_type(str[i]) == 1 && (str[i] == 'u' ||
					  str[i] == 'x' || str[i] == 'X' || str[i] == 'b' || str[i] == 'o'))
      	va_arg(varl, unsigned int);
    }
}

void		do_print(char c, va_list varl)
{
  if (c == 'p' || c == 'c')
    comp_type(c, varl);
  else
    simp_type(c, varl);
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
      if (str[i] == '%' && is_a_type(str[i + 1]) != 0)
	{
	  select_way(str[i + 1], varl, &str[i + 1]);
	  i++;
	}
      else
	my_putchar(str[i]);
      i++;
    }
  va_end(varl);
  return (0);
}
