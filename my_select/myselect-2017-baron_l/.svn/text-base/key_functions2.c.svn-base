/*
** key_functions2.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Jan 17 15:14:46 2013 louis-philippe baron
** Last update Thu Jan 17 16:04:35 2013 louis-philippe baron
*/

#include	"hselect.h"

void		space(t_ptr *ptr)
{
  if (ptr->list->video == 0)
    ptr->list->video = 1;
  else
    ptr->list->video = 0;
  down(ptr);
}

void		echap(t_ptr *ptr, int *i)
{
  t_list	*tmp;

  tmp = ptr->first;
  while (tmp)
    {
      tmp->video = 0;
      tmp = tmp->next;
    }
  *i = 0;
}
