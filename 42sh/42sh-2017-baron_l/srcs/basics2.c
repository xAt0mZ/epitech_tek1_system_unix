/*
** basics2.c for 42sh in /home/baron_l//local/rendu/projets/system_unix/42sh/42sh-2017-baron_l/srcs/edt
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sun May 26 21:03:34 2013 louis-philippe baron
** Last update Sun May 26 21:36:51 2013 louis-philippe baron
*/

#include	"h42.h"

int		my_cmp(char *env, char *term)
{
  int		i;

  i = 0;
  while (env[i] && term[i])
    {
      if (env[i] != term[i])
	return (ERROR);
      i++;
    }
  if (term[i] == 0 && env[i])
    return (0);
  return (ERROR);
}
