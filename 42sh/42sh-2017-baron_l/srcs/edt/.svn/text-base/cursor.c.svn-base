/*
** cursor.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Fri May 24 00:08:28 2013 damien sauvalle
** Last update Sun May 26 20:53:36 2013 louis-philippe baron
*/

#include	"h42.h"
#include	"edt.h"

int		my_getpos()
{
  char		buf[10];
  int		i;
  char		to[3];
  int		j;

  write(0, "\e[6n", 10);
  i = xread(0, buf, 10);
  if (i < 1)
    return (-1);
  buf[i] = '\0';
  i = 2;
  j = 0;
  while (buf[i] != ';')
    {
      to[j] = buf[i];
      i++;
      j++;
    }
  to[j] = '\0';
  i = my_getnbr(to);
  my_putstr("\r");
  return (i - 1);
}

int		my_tgoto(t_charl *list, t_caps *caps)
{
  char		*name;

  name = tgoto(caps->cm, list->cur.x, list->cur.y);
  if (name == NULL)
    return (error_v_int("tgoto fail\n", -1));
  if (tputs(name, 0, my_putchar_int) == -1)
    return (error_v_int("tputs fail\n", -1));
  return (0);
}

void		init_cur(t_charl *list)
{
  int		y;

  y = my_getpos();
  if (y == -1)
    y = 0;
  list->cur.x = 7;
  list->cur.y = y;
  list->beg.x = list->cur.x;
  list->beg.y = list->cur.y;
  list->end.x = list->cur.x;
  list->end.y = list->cur.y;
}

int		end_of_term(t_charl *list, t_caps *caps)
{
  int		x;
  int		y;

  x = list->cur.x;
  y = list->cur.y;
  list->cur.y = list->beg.y - 1;
  list->cur.x = 0;
  list->beg.y = list->beg.y - 1;
  list->beg.x = 0;
  if ((my_tgoto(list, caps) == -1) ||
      (tputs(caps->sauvc, 0, my_putchar_int) == -1))
    return (-1);
  refresh(list, caps);
  list->beg.x = 7;
  list->end.y = caps->line -1;
  list->cur.x = x;
  list->cur.y = y;
  if (my_tgoto(list, caps) == -1)
    return (-1);
  return (0);
}

int		add_cursor(t_charl *list, t_caps *caps)
{
  list->cur.x++;
  list->end.x++;
  if (list->cur.x == caps->col)
    {
      list->cur.x = 0;
      if (list->cur.y + 1 < caps->line)
	list->cur.y++;
    }
  if (list->end.x == caps->col)
    {
      list->end.x = 0;
      if (list->end.y + 1 < caps->line)
	list->end.y++;
      if (list->end.y == caps->line - 1)
	if (end_of_term(list, caps) == -1)
	  return (-1);
    }
  return (0);
}
