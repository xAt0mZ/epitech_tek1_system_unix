/*
** basics.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Jan 16 11:46:24 2013 louis-philippe baron
** Last update Fri Jan 18 11:21:03 2013 louis-philippe baron
*/

#include	"hselect.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char		*my_strdup(char *str)
{
  int		i;
  char		*res;

  if ((res = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (s1[i])
    {
      if (s1[i] == s2[j])
	j++;
      i++;
    }
  if (s2[j] == '\0')
    return (0);
  return (ERROR);
}

void		clean_buffer(char *buffer)
{
  int		i;

  i = 0;
  while (i < 256)
    {
      buffer[i] = '\0';
      i++;
    }
}

void		init_ptr(t_ptr *ptr, t_list *list)
{
  t_list	*tmp;

  ptr->first = list;
  tmp = list;
  while (tmp->next)
    tmp = tmp->next;
  ptr->last = tmp;
  ptr->list = list;
  ptr->list->under = 1;
}
