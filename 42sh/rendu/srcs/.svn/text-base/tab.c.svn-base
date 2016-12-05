/*
** tab.c for 42sh in /home/lefebv_z//projet/unix/42sh/tree
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Thu May 23 15:57:20 2013 marie lefebvre
** Last update Fri May 24 18:07:47 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

int		tab_len(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
