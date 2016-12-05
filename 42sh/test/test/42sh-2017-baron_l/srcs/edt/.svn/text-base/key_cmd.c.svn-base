/*
** key_cmd.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Mon May 13 12:06:18 2013 damien sauvalle
** Last update Sun May 26 20:55:27 2013 louis-philippe baron
*/

#include	"h42.h"
#include	"key.h"
#include	"edt.h"

int		key_to_int(char *line)
{
  int		i;
  int		key;

  key = 0;
  i = 0;
  while (line[i])
    key += (int)line[i++];
  return (key);
}

int		key2(int key, t_charl *list, t_caps *caps)
{
  if (key == RIGHT_T)
    return (move_right(list, caps));
  else if (key == LEFT_T)
    return (move_left(list, caps));
  else if (key == CTRL_L)
    return (clear_sc(list, caps));
  else if (key == CTRL_T)
    return (swap_char(list, caps));
  else if (key == SUPP)
    return (supress(list, caps));
  else if (key == DELETE)
    return (delete(list, caps));
  else if (key == CTRL_A || key == HOME)
    return (cursor_beg(list));
  else if (key == CTRL_E || key == END)
    return (cursor_end(list));
  return (0);
}

int		key_cmd(char *line, t_charl *list, t_caps *caps)
{
  int		key;
  int		ret;

  key = key_to_int(line);
  ret = key2(key, list, caps);
  if (ret == 2)
    return (2);
  if (key == ENTER)
    return (1);
  else if (key == 4)
    return (-2);
  if (key < 32 || key > 126)
    return (5);
  return (0);
}
