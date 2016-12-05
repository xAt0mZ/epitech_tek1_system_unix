/*
** show_final_list.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sat Jan 19 21:43:45 2013 louis-philippe baron
** Last update Sat Jan 19 21:44:08 2013 louis-philippe baron
*/

#include	"hselect.h"

void		show_final_list(t_ptr *ptr)
{
  t_list	*tmp;

  if (put("cl") == ERROR)
    my_putstr("Screen will not be cleared, some display bugs may happen.\n", 2);
  tmp = ptr->first;
  while (tmp)
    {
      if (tmp->print == 1 && tmp->video == 1)
	{
	  my_putstr(tmp->data, 1);
	  my_putchar(' ', 1);
	}
      tmp = tmp->next;
    }
}
