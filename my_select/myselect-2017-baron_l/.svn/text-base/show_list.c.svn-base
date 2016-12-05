/*
** show_list.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Jan 16 19:21:59 2013 louis-philippe baron
** Last update Sat Jan 19 21:44:03 2013 louis-philippe baron
*/

#include	"hselect.h"

static	void	both(char *str)
{
  char		*toto;

  toto = tgetstr("mr", NULL);
  tputs(toto, 1, tputschar);
  toto = tgetstr("us", NULL);
  tputs(toto, 1, tputschar);
  my_putstr(str, 0);
  toto = tgetstr("me", NULL);
  tputs(toto, 1, tputschar);
}

static	void	video(char *str)
{
  char		*toto;

  toto = tgetstr("mr", NULL);
  tputs(toto, 1, tputschar);
  my_putstr(str, 0);
  toto = tgetstr("me", NULL);
  tputs(toto, 1, tputschar);

}

static	void	under(char *str)
{
  char		*toto;

  toto = tgetstr("us", NULL);
  tputs(toto, 1, tputschar);
  my_putstr(str, 0);
  toto = tgetstr("ue", NULL);
  tputs(toto, 1, tputschar);
}

void		print(t_list *elem, t_winsize *win, int i, int y)
{
  if (elem->video == 1 && elem->under == 1)
    both(elem->data);
  else if (elem->video == 1 && elem->under == 0)
    video(elem->data);
  else if (elem->video == 0 && elem->under == 1)
    under(elem->data);
  else
    my_putstr(elem->data, 0);
  put_goto(i * (win->ws_xpixel + 2), y);
}

void		show_list(t_list **list)
{
  t_list	*elem;
  t_winsize	win;
  int		i;
  int		y;

  i = 0;
  y = 1;
  elem = *list;
  if (do_ioctl(&win, elem) == 0)
    while (elem)
      {
	if (elem->print == 1)
	  {
	    print(elem, &win, i, y);
	    if (y < win.ws_row - 1)
	      y++;
	    else
	      {
		y = 0;
		i++;
	      }
	  }
	elem = elem->next;
      }
}
