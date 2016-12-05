/*
** free_list.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Jan 16 19:43:36 2013 louis-philippe baron
** Last update Wed Jan 16 19:54:45 2013 louis-philippe baron
*/

#include	"hselect.h"

void		free_list(t_list **list)
{
  t_list	*elem;
  t_list	*link;

  elem = *list;
  while (elem)
    {
      link = elem->next;
      free(elem->data);
      free(elem);
      elem = link;
    }
}
