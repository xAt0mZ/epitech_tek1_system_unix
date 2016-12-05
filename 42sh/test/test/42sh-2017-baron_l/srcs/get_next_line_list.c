/*
** get_next_line_list.c for get_next_line in /home/garner_p/Workplace/C_Prog_Elem/getnextline-2017-garner_p
** 
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
** 
** Started on  Wed Dec  5 13:05:05 2012 Garnero Philip
** Last update Wed May 22 18:01:26 2013 Garnero Philip
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"hget_next_line.h"

int		my_put_in_char_list(t_charlist **list, char letter)
{
  t_charlist	*elem;
  t_charlist	*tmp;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->letter = letter;
  elem->next = NULL;
  if (*list == NULL)
    {
      elem->next = *list;
      *list = elem;
    }
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
    }
  return (0);
}
