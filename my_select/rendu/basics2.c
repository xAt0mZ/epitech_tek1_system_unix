/*
** basics2.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Jan 17 13:28:39 2013 louis-philippe baron
** Last update Sat Jan 19 19:45:45 2013 louis-philippe baron
*/

#include	"hselect.h"

void		my_putchar(char c, int fd)
{
  write(fd, &c, 1);
}

void		my_putstr(char *str, int fd)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i], fd);
      i++;
    }
}

int		tputschar(int i)
{
  char		c;

  c = i;
  write(0, &c, 1);
  return (0);
}
