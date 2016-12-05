/*
** history.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/tree
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 17:22:22 2013 Garnero Philip
** Last update Sun May 26 16:19:10 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"h42.h"

int	init_histo(t_glob *glob)
{
  char	*str;
  int	i;

  if ((glob->hist_fd = open(".42history", O_RDWR | O_CREAT, S_IRWXU)) == -1)
    return (error_int("Historic file opening failed\n"));
  i = 1;
  while ((str = get_next_line(glob->hist_fd)) && i <= 1000)
    {
      my_put_in_hist(&(glob)->hist, str, i);
      i = i + 1;
    }
  return (i);
}

void		write_hist(t_glob *glob)
{
  int		i;
  t_hist	*tmp;

  tmp = glob->hist;
  i = glob->hist_id - 1000;
  while (i > 0)
    {
      tmp = tmp->next;
      i = i - 1;
    }
  while (tmp)
    {
      putstr_fd(glob->hist_fd, tmp->command);
      putstr_fd(glob->hist_fd, "\n");
      tmp = tmp->next;
    }
}

int	add_command(t_glob *glob, char *line)
{
  if ((my_put_in_hist(&(glob)->hist, line, glob->hist_id)) == 1)
    return (ERROR);
  glob->hist_id = glob->hist_id + 1;
  return (0);
}

char		*hist_line(int id, t_glob *glob)
{
  int		i;
  t_hist	*tmp;

  tmp = glob->hist;
  if (tmp == NULL)
    return (NULL);
  i = 1;
  while (tmp && i < id)
    {
      i = i + 1;
      tmp = tmp->next;
    }
  return (tmp->command);
}

int		my_put_in_hist(t_hist **list, char *cmd, int red)
{
  t_hist	*elem;
  t_hist	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (error_int(MALLOC_ERROR));
  elem->command = cmd;
  elem->id = red;
  elem->next = NULL;
  elem->prev = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      elem->prev = tmp;
    }
  return (0);
}
