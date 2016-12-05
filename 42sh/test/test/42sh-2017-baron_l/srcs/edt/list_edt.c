/*
** list_siders.c for 42sh in /home/sauval_d//GIT/42sh/new_edt/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Tue May  7 16:03:45 2013 damien sauvalle
** Last update Sun May 26 20:55:48 2013 louis-philippe baron
*/

#include	<stdlib.h>
#include	"edt.h"

t_charl		*init_list()
{
  t_charl	*list;

  list = malloc(sizeof(t_charl));
  if (list == NULL)
    return (NULL);
  list->top = NULL;
  list->bot = NULL;
  list->len = 0;
  list->cur.x = 0;
  list->cur.y = 0;
  list->end.x = 0;
  list->end.y = 0;
  list->beg.x = 0;
  list->beg.y = 0;
  if (list->top == NULL)
    if (first_insert(list, "\0") == -1)
      return (NULL);
  return (list);
}

int		first_insert(t_charl *list, char *line)
{
  t_item	*elem;

  if ((elem = malloc(sizeof(t_item))) == NULL)
    return (-1);
  if ((elem->data = malloc(sizeof(t_char))) == NULL)
    return (-1);
  elem->data->str = line[0];
  elem->data->cur = 1;
  elem->next = list->bot;
  elem->prev = list->top;
  list->top = elem;
  list->bot = elem;
  list->len++;
  give_num(list->top);
  return (0);
}

int		put_in_list(t_charl *list, char line)
{
  t_item	*elem;
  t_item	*now;

  if (list->len == 5000)
    return (0);
  if ((elem = malloc(sizeof(t_item))) == NULL)
    return (-1);
  if ((elem->data = malloc(sizeof(t_char))) == NULL)
    return (-1);
  elem->data->str = line;
  elem->data->cur = 0;
  now = list->top;
  while (now->data->cur != 1)
    now = now->next;
  elem->next = now;
  elem->prev = now->prev;
  if (now->prev == NULL)
    list->top = elem;
  else
    now->prev->next = elem;
  now->prev = elem;
  list->len++;
  give_num(list->top);
  return (0);
}

void		free_list(t_charl *list)
{
  t_item	*tmp;
  t_item	*tmp2;

  tmp = list->top;
  while (tmp)
    {
      tmp2 = tmp;
      free(tmp2->data);
      tmp = tmp->next;
      free(tmp2);
    }
  free(list);
}
