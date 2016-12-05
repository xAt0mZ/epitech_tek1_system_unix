/*
** basics.c for tp in /home/baron_l//local/rendu/piscine/projets/my_ls/tp
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Nov 28 14:18:02 2012 louis-philippe baron
** Last update Wed Nov 28 14:20:52 2012 louis-philippe baron
*/

#include	<unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}
