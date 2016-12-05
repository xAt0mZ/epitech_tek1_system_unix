/*
** cursor.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Fri May 24 00:08:28 2013 damien sauvalle
** Last update Sun May 26 16:41:10 2013 damien sauvalle
*/

#include	"../h42.h"
#include	<term.h>
#include	"edt.h"


int     my_getpos()
{
  char  buf[10];
  int   i;
  char	to[3];
  int	j;

  write(0,"\e[6n", 10);
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

void	my_tgoto(t_charl *list, t_caps *caps)
{
  tputs(tgoto(caps->cm, list->cur.x, list->cur.y), 0, my_putchar_int);
}

void	add_cursor(t_charl *list, t_caps *caps)/*refresh la position cursor*/
{
  int y;
  int x;

  list->cur.x++;
  list->end.x++;
  if (list->cur.x == caps->col)/*refrefh cur*/
    {
      list->cur.x = 0;
      if (list->cur.y + 1 < caps->line)
	list->cur.y++;
    }
  if (list->end.x == caps->col)/*refrefh end*/
    {
      list->end.x = 0;
      if (list->end.y + 1 < caps->line)
	list->end.y++;
      if (list->end.y == caps->line - 1)
	{
	  x = list->cur.x;
	  y = list->cur.y;
	  list->cur.y = list->beg.y - 1;
	  list->cur.x = 0; 
	  list->beg.y = list->beg.y - 1;
	  list->beg.x = 0;
	  my_tgoto(list, caps);
	  tputs(caps->sauvc, 0, my_putchar_int);  
	  refresh(list, caps);
	  list->beg.x = 7;
	  list->end.y = caps->line -2;
	  list->cur.x = x;
	  list->cur.y = y - 1;
	  my_tgoto(list, caps);

	}  
    }
}
