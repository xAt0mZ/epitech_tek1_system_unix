/*
** ioctl.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sat Jan 19 13:35:51 2013 louis-philippe baron
** Last update Sat Jan 19 21:42:49 2013 louis-philippe baron
*/

#include	"hselect.h"

int		set_val(t_list *list, t_winsize *win)
{
  int		i;

  i = 1;
  while (list)
    {
      if (i == win->ws_row)
	{
	  list->top = 1;
	  i = 0;
	}
      else
	{
	  list->top = 0;
	  i++;
	}
      list = list->next;
    }
  return (0);
}

int		calc_list_size(t_list *list)
{
  int		i;

  i = 0;
  while (list)
    {
      if (list->print == 1)
	i++;
      list = list->next;
    }
  return (i);
}

int		set_top(t_winsize *win, t_list *list)
{
  int		tmp;
  t_list	*elem;

  win->ws_xpixel = 0;
  elem = list;
  while (elem)
    {
      tmp = my_strlen(elem->data);
      if (win->ws_xpixel < tmp)
	win->ws_xpixel = tmp;
      elem = elem->next;
    }
  elem = list;
  tmp = calc_list_size(list);
  if (win->ws_col < win->ws_xpixel ||
      win->ws_col / win->ws_xpixel * win->ws_row < tmp)
    {
      my_putstr("Window is too small to display all possibilities.\n", 2);
      return (ERROR);
    }
  set_val(list, win);
  return (0);
}

int		do_ioctl(t_winsize *win, t_list *list)
{
  static int	x = 0;
  static int	y = 0;

  if (ioctl(0, TIOCGWINSZ, win) == -1)
    {
      my_putstr("ioctl failed, winsize can't be managed.\n", 2);
      return (ERROR);
    }
  if (x != win->ws_col || y != win->ws_row)
    {
      x = win->ws_col;
      y = win->ws_row;
      if (put("cl") == ERROR)
	{
	  my_putstr("Screen will not be cleared, ", 2);
	  my_putstr("some display bugs may happen.\n", 2);
	}
    }
  if (set_top(win, list) == ERROR)
    return (ERROR);
  put_goto(0, 0);
  return (0);
}
