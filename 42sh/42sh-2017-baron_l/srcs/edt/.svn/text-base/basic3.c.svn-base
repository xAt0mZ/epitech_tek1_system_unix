/*
** basics.c for 42sh in /home/sauval_d//42sh/edit_line
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Mon Apr 29 16:41:40 2013 damien sauvalle
** Last update Sun May 26 20:53:26 2013 louis-philippe baron
*/

#include	"h42.h"
#include	"edt.h"

void		clean_buf(char *buf)
{
  int		j;

  j = 0;
  while (j < 9)
    {
      buf[j] = '\0';
      j++;
    }
}

int		my_putchar_int(int c)
{
  return (write(1, &c, 1));
}

int		xread(int fd, char *buf, int len)
{
  int		i;

  i = read(fd, buf, len);
  buf[i] = '\0';
  return (i);
}
