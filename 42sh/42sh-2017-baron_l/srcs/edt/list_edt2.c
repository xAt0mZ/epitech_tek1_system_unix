/*
** list_siders2.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Mon May 13 12:03:19 2013 damien sauvalle
** Last update Sun May 26 20:56:23 2013 louis-philippe baron
*/

#include	<stdlib.h>
#include	"edt.h"

void		give_num(t_item *list)
{
  t_item	*tmp;
  int		i;

  i = 0;
  tmp = list;
  while (tmp)
    {
      tmp->data->num = i;
      tmp = tmp->next;
      i++;
    }
}

void		refresh_supp(t_charl *list, t_caps *caps)
{
  list->end.x--;
  if (list->end.x == 0)
    {
      list->end.x = caps->col;
      list->end.y--;
    }
}

int		supress(t_charl *list, t_caps *caps)
{
  t_item	*tmp;

  if (list->len == 1)
    return (2);
  tmp = list->top;
  while (tmp->data->cur != 1)
    tmp = tmp->next;
  if (tmp == list->bot)
    return (2);
  if (tmp->next)
    {
      tmp->next->data->cur = 1;
      tmp->next->prev = tmp->prev;
    }
  if (tmp->prev)
    tmp->prev->next = tmp->next;
  if (tmp == list->top)
    list->top = tmp->next;
  list->len--;
  free(tmp->data);
  free(tmp);
  refresh_supp(list, caps);
  give_num(list->top);
  return (2);
}

void		refresh_del(t_charl *list, t_caps *caps)
{
  if (list->cur.x == 0)
    {
      list->cur.x = caps->col - 1;
      list->cur.y--;
    }
  else
    list->cur.x--;
  if (list->end.x == 0)
    {
      list->end.x = caps->col - 1;
      list->end.y--;
    }
  else
    list->end.x--;
  refresh(list, caps);
}

int		delete(t_charl *list, t_caps *caps)
{
  t_item	*tmp;

  if (list->len == 1)
    return (2);
  tmp = list->top;
  if (tmp->data->cur == 1)
    return (2);
  while (tmp->next->data->cur != 1)
    tmp = tmp->next;
  if (tmp != NULL)
    {
      if (tmp->prev)
	tmp->prev->next = tmp->next;
      if (tmp->next)
	tmp->next->prev = tmp->prev;
      if (tmp == list->top)
	list->top = tmp->next;
      list->len--;
      free(tmp->data);
      free(tmp);
      give_num(list->top);
      refresh_del(list, caps);
    }
  return (2);
}
