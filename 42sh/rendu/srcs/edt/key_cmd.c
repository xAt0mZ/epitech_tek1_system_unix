/*
** key_cmd.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Mon May 13 12:06:18 2013 damien sauvalle
** Last update Sun May 26 17:03:10 2013 damien sauvalle
*/

#include	"../h42.h"
#include	"key.h"
#include	"edt.h"

/*	TOUCHE A RECUPER
**	CTRL - DROITE GAUCHE HAUT BAS
**	ctrl - D
*/

int	key_to_int(char *line)
{
  int	i;
  int	key;

  key = 0;
  i = 0;
  while (line[i])
    key += (int)line[i++];
  return (key);
}

int	my_histo(t_charl *list, t_glob *glob)
{
  int i;
  char *new;

  list->idh--;
  if (hist_line(list->idh, glob) == NULL)
    return (2);
  new = hist_line(list->idh, glob);
  
  return (2);
}

int		key_cmd(char *line, t_charl *list, t_caps *caps, t_glob *glob)
{
  int		key;

  key = key_to_int(line);
  if (key == ENTER)
    return (1);
  else if (key == TABULATION)    /*return (pre_tab(list, caps));*/
    return (pre_tab(list, caps));
  else if (key == UP)
    return (my_histo(list, glob));
  else if (key == DOWN)
    return (2);
  else if (key == RIGHT_T)
    return (move_right(list, caps)); 
  else if (key == LEFT_T)
    return (move_left(list, caps));
  else if (key == CTRL_L)
    return (clear_sc(list, caps));
  else if (key == CTRL_A || key == HOME)
    return (cursor_beg(list));
  else if (key == CTRL_E || key == END)
    return (cursor_end(list));
  else if (key == CTRL_T)
    return (swap_char(list, caps));
  else if (key == SUPP)
    return (supress(list,caps));  
  else if (key == DELETE)
    return (delete(list, caps));
  if (key == 4)
    return (-2);
  if (key < 32 || key > 126)
    return (5); 
 return (0);
}
