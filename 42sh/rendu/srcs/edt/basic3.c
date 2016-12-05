/*
** basics.c for 42sh in /home/sauval_d//42sh/edit_line
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Mon Apr 29 16:41:40 2013 damien sauvalle
** Last update Sun May 26 16:56:31 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../h42.h"
#include	"edt.h"

int		my_putchar_int(int c)
{
  return(write(1, &c, 1));
}

int		xread(int fd, char *buf, int len)
{
  int		i;
  int		t;

  i = read(fd, buf, len); 
  buf[i] = '\0';
  return (i);
}
