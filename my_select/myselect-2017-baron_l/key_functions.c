/*
** key_functions.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Jan 17 15:05:43 2013 louis-philippe baron
** Last update Sat Jan 19 21:37:49 2013 louis-philippe baron
*/

#include	"hselect.h"

void		up(t_ptr *ptr)
{
  ptr->list->under = 0;
  if (ptr->list->prev == NULL)
    ptr->list = ptr->last;
  else
    ptr->list = ptr->list->prev;
  while (ptr->list->print != 1)
    {
      if (ptr->list->prev == NULL)
	ptr->list = ptr->last;
      else
	ptr->list = ptr->list->prev;
    }
  ptr->list->under = 1;
}

void		down(t_ptr *ptr)
{
  ptr->list->under = 0;
  if (ptr->list->next == NULL)
    ptr->list = ptr->first;
  else
    ptr->list = ptr->list->next;
  while (ptr->list->print != 1)
    {
      if (ptr->list->next == NULL)
	ptr->list = ptr->first;
      else
	ptr->list = ptr->list->next;
    }
  ptr->list->under = 1;
}

static	int	check_list(t_ptr *ptr)
{
  t_list	*tmp;
  int		i;

  tmp = ptr->first;
  i = 0;
  while (tmp)
    {
      if (tmp->print == 1)
	i++;
      tmp = tmp->next;
    }
  return (i);
}

void		del_backspace(t_ptr *ptr, int *i)
{
  ptr->list->print = 0;
  down(ptr);
  if (put("cl") == ERROR)
    {
      my_putstr("Screen will not be cleared, ", 2);
      my_putstr("some display bugs may happen.\n", 2);
    }
  if (check_list(ptr) == 0)
    *i = 0;
}
