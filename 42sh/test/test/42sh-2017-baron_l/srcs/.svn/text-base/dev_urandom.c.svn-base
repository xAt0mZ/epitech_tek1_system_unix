/*
** dev_urandom.c for 42sh in /home/baron_l//local/rendu/projets/system_unix/42sh/42sh-2017-baron_l/srcs
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sun May 26 21:44:32 2013 louis-philippe baron
** Last update Sun May 26 21:46:35 2013 louis-philippe baron
*/

#include	"h42.h"

int		dev_urandom(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (!(str[i] >= ' ' && str[i] < 127))
	return (ERROR);
      i++;
    }
  return (0);
}
