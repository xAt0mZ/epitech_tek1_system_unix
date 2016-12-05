/*
** aply_caps.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Tue May 14 18:23:22 2013 damien sauvalle
** Last update Sun May 26 20:53:13 2013 louis-philippe baron
*/

#include	"h42.h"
#include	"edt.h"

int		cursor_beg(t_charl *list)
{
  t_item	*tmp;

  tmp = list->top;
  while (tmp->data->cur != 1)
    tmp = tmp->next;
  tmp->data->cur = 0;
  list->top->data->cur = 1;
  list->cur.x = list->beg.x;
  list->cur.y = list->beg.y;
  return (2);
}

int		cursor_end(t_charl *list)
{
  t_item	*tmp;

  tmp = list->top;
  while (tmp->data->cur != 1)
    tmp = tmp->next;
  tmp->data->cur = 0;
  list->bot->data->cur = 1;
  list->cur.x = list->end.x;
  list->cur.y = list->end.y;
  return (2);
}

int		clear_sc(t_charl *list, t_caps *caps)
{
  int		y;
  int		x;
  int		ty;

  x = list->cur.x;
  y = list->beg.y;
  list->beg.y = 0;
  list->beg.x = 7;
  ty = list->cur.y - y;
  list->end.y -= y;
  list->cur.y = 0;
  list->cur.x = 0;
  if ((my_tgoto(list, caps) == -1) ||
      (tputs(caps->sauvc, 0, my_putchar_int)) ||
      (tputs(caps->clearsc, 0, my_putchar_int)))
    return (-1);
  list->cur.x = x;
  list->cur.y = ty;
  if (my_tgoto(list, caps) == -1)
    return (-1);
  refresh(list, caps);
  return (2);
}

int		move_left(t_charl *list, t_caps *caps)
{
  t_item	*tmp;

  if (list->len == 1)
    return (2);
  tmp = list->top;
  while (tmp->data->cur != 1)
    tmp = tmp->next;
  if (tmp->prev)
    {
      tmp->prev->data->cur = 1;
      tmp->data->cur = 0;
      if (list->cur.x == 0)
	{
	  list->cur.x = caps->col - 1;
	  list->cur.y--;
	}
      else
	list->cur.x--;
    }
  return (2);
}

int		move_right(t_charl *list, t_caps *caps)
{
  t_item	*tmp;

  if (list->len == 1)
    return (2);
  tmp = list->top;
  while (tmp->data->cur != 1)
    tmp = tmp->next;
  if (tmp->next)
    {
      tmp->next->data->cur = 1;
      tmp->data->cur = 0;
      list->cur.x++;
      if (list->cur.x == caps->col)
	{
	  list->cur.x = 0;
	  if (list->cur.y + 1 < caps->line)
	    list->cur.y++;
	}
    }
  return (2);
}
