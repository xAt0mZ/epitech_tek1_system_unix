/*
** swap_char.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Thu May 23 23:51:25 2013 damien sauvalle
** Last update Sun May 26 20:56:35 2013 louis-philippe baron
*/

#include	"edt.h"

static void	swap_c(t_char **data1, t_char **data2)
{
  char		tmp;

  tmp = (*data1)->str;
  (*data1)->str = (*data2)->str;
  (*data2)->str = tmp;
}

static void	cursor_swap(t_charl *list, t_caps *caps)
{
  if (list->cur.x == caps->col - 1)
    {
      list->cur.x = 0;
      if (list->cur.y + 1 < caps->line)
	list->cur.y++;
    }
  else
    list->cur.x++;
}

int		swap_char(t_charl *list, t_caps *caps)
{
  t_item	*tmp;

  tmp = list->top;
  if (tmp->data->cur == 1 || list->len <= 2)
    return (2);
  while (tmp->data->cur != 1)
    tmp = tmp->next;
  if (tmp->next)
    {
      tmp->data->cur = 0;
      tmp->next->data->cur = 1;
      swap_c(&tmp->data, &tmp->prev->data);
      cursor_swap(list, caps);
    }
  else if (tmp == list->bot)
    swap_c(&tmp->prev->data, &tmp->prev->prev->data);
  give_num(list->top);
  return (2);
}
