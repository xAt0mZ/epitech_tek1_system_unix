/*
** path.c for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Nov 29 15:16:20 2012 louis-philippe baron
** Last update Thu Nov 29 15:16:49 2012 louis-philippe baron
*/


#include	<stdlib.h>
#include	"hmy_ls.h"

char		*get_path(char *str, char *d_name)
{
  int		i;
  int		j;
  char		*res;

  if ((res = malloc((my_strlen(str) + my_strlen(d_name) + 2) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[j])
    res[i++] = str[j++];
  res[i++] = '/';
  j = 0;
  while (d_name[j])
    res[i++] = d_name[j++];
  res[i] = '\0';
  return (res);
}
