/*
** basics.c for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Tue Nov 27 15:11:47 2012 louis-philippe baron
** Last update Fri Nov 30 17:17:38 2012 louis-philippe baron
*/

#include	<unistd.h>
#include	<stdlib.h>

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

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char		*my_malloc(int size)
{
  char		*res;
  int		i;

  if ((res = malloc(size)) == NULL)
    return (NULL);
  i = 0;
  while (i < size - 1)
    res[i++] = '-';
  res[i] = '\0';
  return (res);
}
