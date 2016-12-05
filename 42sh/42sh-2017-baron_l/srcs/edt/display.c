/*
** display.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Mon May 20 13:27:35 2013 damien sauvalle
** Last update Sun May 26 20:25:36 2013 damien sauvalle
*/

#include	"h42.h"
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

int		refresh(t_charl *list, t_caps *caps)
{
  if ((tputs(caps->lclean, 0, my_putchar_int)) ||
      (tputs(caps->restc, 0, my_putchar_int)))
    return (-1);
  list_show(list);
  return (my_tgoto(list, caps));
}
