/*
** chained_list.c for push_swap in /home/baron_l//local/rendu/projets/c_prog_elem/push_swap/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Jan  4 18:59:30 2013 louis-philippe baron
** Last update Thu Jan 17 16:27:15 2013 louis-philippe baron
*/

#include	"hselect.h"

static	int	set_before(t_list **list)
{
  t_list	*tmp;
  t_list	*elem;

  elem = *list;
  elem->prev = NULL;
  tmp = elem;
  elem = elem->next;
  while (elem)
    {
      elem->prev = tmp;
      tmp = elem;
      elem = elem->next;
    }
  return (0);
}

static	int	add_elem(t_list **list, char *str)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (ERROR);
  elem->next = *list;
  if ((elem->data = my_strdup(str)) == NULL)
    return (ERROR);
  elem->video = 0;
  elem->under = 0;
  elem->print = 1;
  *list = elem;
  return (0);
}

t_list		*init_list(int ac, char **av)
{
  int		i;
  t_list	*list;

  i = 1;
  list = NULL;
  while (i < ac)
    {
      if (add_elem(&list, av[i]) == ERROR)
	return (NULL);
      i++;
    }
  rev_list(&list);
  set_before(&list);
  return (list);
}
