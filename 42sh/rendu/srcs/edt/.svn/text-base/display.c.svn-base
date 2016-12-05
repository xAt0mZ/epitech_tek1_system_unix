/*
** display.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Mon May 20 13:27:35 2013 damien sauvalle
** Last update Sun May 26 16:40:15 2013 damien sauvalle
*/

#include	"../h42.h"
#include	"edt.h"

void		list_show(t_charl *list)
{
  t_item	*tmp;
  int		i;

  my_putstr("42sh_> ");
  i = 0;
  tmp = list->top;
  while (tmp)
    {
      my_putchar(tmp->data->str);
      tmp = tmp->next;
      i++;
    }
}

void	refresh(t_charl *list, t_caps *caps)
{
  tputs(caps->lclean, 0, my_putchar_int);
  tputs(caps->restc, 0, my_putchar_int);
  list_show(list);
  my_tgoto(list, caps);
}
