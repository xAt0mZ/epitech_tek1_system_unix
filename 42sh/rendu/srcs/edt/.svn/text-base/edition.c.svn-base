/*
** main.c for 42sh in /home/sauval_d//42sh/edit_line/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Thu May  2 13:08:39 2013 damien sauvalle
** Last update Sun May 26 17:04:55 2013 damien sauvalle
*/

#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>

#include	"../h42.h"
#include	"edt.h"

/*
** autocompletion -- historique
**  gere le rezise de la fenetre + size char > taille fenetre 
**  ctrl - fleche
**  faire ctrl-k ctrl-y
** faire le kiKOO
**
**
*/

void		clean_buf(char *buf)
{
  int		j;

  j = 0;
  while (j < 9)
    {
      buf[j] = '\0';
      j++;
    }
}

int		edition(t_charl *list, t_caps *caps, t_glob *glob)
{
  char		line[9];
  int		ret;
  int		x;

  ret = 0;
  while (ret != -1)
    {
      clean_buf(line);
      x = xread(1, line, 9);
      if (x < 0)
	return (-1); /* MALLOC ERROR*/
      if((ret = key_cmd(line, list, caps, glob)) == 0)
	{
	  if (put_in_list(list, line) == -1)
	    return (-1);
	  add_cursor(list, caps);
	}
      else if (ret == -2)
	return (-2);
      else if (ret == 1)
	return (0);
      refresh(list, caps);
    }
  return (0);
}

char *list_to_char(t_charl *list)
{
  int i;
  t_item *tmp;
  char *new;

  i = list->len;
  tmp = list->top;
  new = malloc(sizeof(char) * (i + 1));
  i = 0;
  while (tmp)
    {
      new[i] = tmp->data->str;
      tmp = tmp->next;
      i++;
  }
  new[i] = '\0';
  return (new);
}

void init_cur(t_charl *list)
{
  int y;

  y = my_getpos();
  list->cur.x = 7;
  list->cur.y = y;
  list->beg.x = list->cur.x;
  list->beg.y = list->cur.y;
  list->end.x = list->cur.x;
  list->end.y = list->cur.y;
}

int edition_line(t_glob *glob, t_caps *caps)
{
  t_term	t;
  t_charl	*list;
  int ret;

  if (tcgetattr(0, &t) == -1)
    return (-1);/* ERROR*/
  if (activ_can_echo(&t) == -1)
    return (-1);
  if ((list = init_list()) == NULL)
    return (-1);
  init_cur(list);
  list->idh = glob->hist_id;
  tputs(caps->sauvc, 0, my_putchar_int);
  my_putstr("42sh_> ");
  my_tgoto(list, caps);
  if (list->top == NULL)
    if (first_insert(list, "\0") == -1)
      return (-1);
  if ((ret = edition(list, caps, glob)) < 0)
    {
      if (ret == -2)
	{
	  glob->retval = EXIT;
	  glob->exit = 0;
	  return (ERROR);
	}
      if (ret == -1)
	glob->retval = ERROR;
      return (0);
    }
  if ((glob->input = list_to_char(list)) == NULL)
    return (ERROR);
  free_list(list);
  dis_can_echo(&t);
  my_putchar('\n');
  return (0);
}
