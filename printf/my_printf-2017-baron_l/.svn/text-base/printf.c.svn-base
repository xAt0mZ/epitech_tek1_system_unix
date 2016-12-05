/*
** printf.c for printf in /home/baron_l//local/rendu/piscine/projets/printf
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Tue Nov 13 14:24:24 2012 louis-philippe baron
** Last update Sat Nov 17 14:49:38 2012 louis-philippe baron
*/

/* d s u x X p b S c o */
/* . a A e E f F g G # 0 1 2 3 4 5 6 7 8 9 - + ' I h l L q j z t */

#include	"hprintf.h"
#include	"hmy.h"

int		is_a_type(char c)
{
  if (C_IS_1)
    return (1);
  else if (C_IS_2)
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
      else if (is_a_type(str[i]) == 1 && (VARL_UI))
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
