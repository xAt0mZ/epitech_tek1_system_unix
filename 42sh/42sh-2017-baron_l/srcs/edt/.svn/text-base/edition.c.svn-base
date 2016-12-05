/*
** main.c for 42sh in /home/sauval_d//42sh/edit_line/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Thu May  2 13:08:39 2013 damien sauvalle
** Last update Sun May 26 23:10:28 2013 damien sauvalle
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	"h42.h"
#include	"edt.h"

char		*list_to_char(t_charl *list)
{
  int		i;
  t_item	*tmp;
  char		*new;

  i = list->len;
  tmp = list->top;
  if ((new = malloc(sizeof(char) * (i + 1))) == NULL)
    return (error_ptr(MALLOC_ERROR));
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

int		edition(t_charl *list, t_caps *caps)
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
	return (-1);
      if ((ret = key_cmd(line, list, caps)) == 0)
	{
	  if (put_in_list(list, line[0]) == -1)
	    return (-1);
	  add_cursor(list, caps);
	}
      else if (ret == -2)
	return (-2);
      else if (ret == 1)
	return (0);
      if (refresh(list, caps) == -1)
	return (-1);
    }
  return (0);
}

int		error_edition(int ret, t_glob *glob, t_term t)
{
  if (ret == -2)
    {
      glob->retval = EXIT;
      glob->exit = 0;
      if (dis_can_echo(&t) == -1)
	return (-1);
      return (ERROR);
    }
  if (ret == -1)
    glob->retval = ERROR;
  return (0);
}

int		edition_line(t_glob *glob, t_caps *caps)
{
  t_term	t;
  t_charl	*list;
  int		ret;

  if (tcgetattr(0, &t) == -1)
    return (-1);
  if (activ_can_echo(&t) == -1)
    return (-1);
  if ((list = init_list()) == NULL)
    return (-1);
  init_cur(list);
  if (tputs(caps->sauvc, 0, my_putchar_int) == -1)
    return (-1);
  my_putstr("42sh_> ");
  if (my_tgoto(list, caps) == -1)
    return (-1);
  if ((ret = edition(list, caps)) < 0)
    return (error_edition(ret, glob, t));
  if ((glob->input = list_to_char(list)) == NULL)
    return (ERROR);
  free_list(list);
  if (dis_can_echo(&t) == -1)
    return (-1);
  my_putchar('\n');
  return (0);
}
