/*
** list_siders.c for siders in /home/garner_p/Save/lib/functions
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Fri Dec 14 16:23:35 2012 Garnero Philip
** Last update Sun May 26 16:19:25 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

int		free_loop(t_list *first)
{
  t_list	*vog;
  t_list	*tmp;

  vog = first;
  while (vog != NULL)
    {
      tmp = vog;
      vog = vog->next;
      free(tmp);
    }
  first = NULL;
  return (0);
}

int		my_put_in_list(t_list **list, char *str)
{
  t_list	*elem;
  t_list	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (error_int(MALLOC_ERROR));
  elem->comp = str;
  elem->next = NULL;
  elem->prev = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      elem->prev = tmp;
    }
  return (0);
}

void		my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->comp);
      tmp = tmp->next;
      my_putchar('\n');
    }
}

void		my_rev_list(t_list **begin)
{
  t_list	 *tmp;
  t_list	 *scd;

  tmp = NULL;
  scd = NULL;
  while (*begin != NULL)
    {
      tmp = *begin;
      *begin = tmp->next;
      tmp->next = scd;
      scd = tmp;
    }
  *begin = tmp;
}

int     delete_mail(t_list **envi, t_list *tmp)
{
  if (tmp == NULL)
    return (1);
  if (tmp->prev != NULL && tmp->next != NULL)
    {
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;
    }
  else if (tmp->prev != NULL && tmp->next == NULL)
    tmp->prev->next = NULL;
  else if (tmp->next != NULL && tmp->prev == NULL)
    {
      tmp->next->prev = NULL;
      *envi = tmp->next;
    }
  else if (tmp->next == NULL && tmp->prev == NULL)
    *envi = NULL;
  tmp->comp = NULL;
  free(tmp);
  return (0);
}
