/*
** main.c for tp in /home/baron_l//local/rendu/piscine/projets/my_ls/tp
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Nov 28 14:08:28 2012 louis-philippe baron
** Last update Wed Nov 28 14:24:02 2012 louis-philippe baron
*/

#include	<sys/types.h>
#include	<dirent.h>
#include	"htp.h"

int		main(int ac, char **av)
{
  DIR		*stream;
  struct dirent	*rd;

  if (ac == 2)
    stream = opendir(av[1]);
  else
    stream = opendir(".");
  while ((rd = readdir(stream)))
    {
      my_putstr(rd->d_name);
      my_putchar(10);
    }
  return (0);
}
