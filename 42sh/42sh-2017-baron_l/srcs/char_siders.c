/*
** char_siders.c for siders in /home/garner_p/Save/lib/functions
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Fri Dec 14 15:37:45 2012 Garnero Philip
** Last update Sun May 26 17:00:07 2013 louis-philippe baron
*/

#include	<unistd.h>
#include	"h42.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(1, &(str[i]), 1);
      i = i + 1;
    }
}

void	putstr_fd(int fd, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(fd, &(str[i]), 1);
      i = i + 1;
    }
}

int     my_strlen(char *str)
{
  int   n;

  n = 0;
  while (str[n])
    n = n + 1;
  return (n);
}

char    *my_strcpy(char *dest, char *src)
{
  int   lenght;

  lenght = 0;
  while (src[lenght])
    {
      dest[lenght] = src[lenght];
      lenght = lenght + 1;
    }
  dest[lenght] = '\0';
  return (dest);
}
