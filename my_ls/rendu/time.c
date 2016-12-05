/*
** time.c for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Nov 29 15:11:26 2012 louis-philippe baron
** Last update Thu Nov 29 15:13:03 2012 louis-philippe baron
*/

#include	<stdlib.h>
#include	"hmy_ls.h"

char		*copy_time(char *time)
{
  int		i;
  int		j;
  char		*res_time;

  i = 0;
  if ((res_time = malloc(13 * sizeof(char))) == NULL)
    return (NULL);
  while (time[i] != ' ')
    i++;
  i++;
  j = 0;
  while (j < 12)
    {
      res_time[j] = time[i];
      j++;
      i++;
    }
  res_time[j] = '\0';
  return (res_time);
}
