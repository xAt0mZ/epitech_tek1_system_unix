/*
** return_cmp.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Sat May 25 12:05:26 2013 damien sauvalle
** Last update Sun May 26 11:11:48 2013 damien sauvalle
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "edt.h"

int list_len(t_auto *aut)
{
  t_auto *tmp;
  int i;

  i = 0;
  tmp = aut;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

char	*str_to_cmp(t_auto *aut, char *str)
{
  int	i;
  int	n;

  n  = strlen(str);
  i = list_len(aut);
  if (i == 0)
    return (NULL);
  else if (i == 1)
    return (strdup(aut->str) + n);

  
  return (NULL);
}
