/*
** get_next_line.c for get_next_line in /home/garner_p/Workplace/getnextline-2017-garner_p
** 
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
** 
** Started on  Wed Nov 21 15:07:40 2012 Garnero Philip
** Last update Sat May 25 16:11:50 2013 Garnero Philip
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"hget_next_line.h"

static int	liberator(int a, t_charlist *scd, t_charlist **tmp)
{
  while (a + 1 && (*tmp))
    {
      a = a - 1;
      scd = *tmp;
      *tmp = (*tmp)->next;
      free(scd);
    }
  return (0);
}

static char	*malloc_put_free(t_charlist *scd, t_charlist **tmp)
{
  int		a;
  int		b;
  char		*line;

  a = 0;
  b = 0;
  while (scd && scd->letter != '\n' && scd->letter != '\0')
    {
      a = a + 1;
      scd = scd->next;
    }
  line = malloc(sizeof(char) * (a + 2));
  if (line == NULL)
    return (NULL);
  scd = *tmp;
  while (scd && scd->letter != '\n' && scd->letter != '\0')
    {
      line[b++] = scd->letter;
      scd = scd->next;
    }
  line[b] = '\0';
  liberator(a, scd, tmp);
  return (line);
}

static char	*starter(t_charlist **charlist, char *buffer, int bytes, int fd)
{
  if (*charlist == NULL)
    {
      bytes = read(fd, buffer, 1);
      if (bytes <= 0)
	{
	  free(buffer);
	  return (NULL);
	}
      if ((my_put_in_char_list(charlist, buffer[0])) == 1)
	return (NULL);
    }
  return ("OK");
}

static t_charlist	*do_list(t_charlist **charlist, char *buffer,
				 int bytes, int fd)
{
  t_charlist		*tmp;
  t_charlist		*scd;
  int			i;
  int			j;

  tmp = *charlist;
  scd = *charlist;
  j = 0;
  while (tmp && tmp->letter != '\n' && tmp->letter != '\0')
    {
      bytes = read(fd, buffer, READ_AMOUNT);
      if (bytes <= 0 && *charlist == NULL)
	return (NULL);
      buffer[bytes] = '\0';
      i = 0;
      while (buffer[i])
	my_put_in_char_list(charlist, buffer[i++]);
      if (bytes == 0 && j++ == 0)
	if ((my_put_in_char_list(charlist, '\0')) == 1)
	  return (NULL);
      tmp = tmp->next;
    }
  tmp = scd;
  return (tmp);
}

char			*get_next_line(const int fd)
{
  static t_charlist	*charlist = NULL;
  t_charlist		*tmp;
  t_charlist		*scd;
  char			*buffer;
  char			*line;
  int			bytes;

  bytes = 0;
  if (READ_AMOUNT < 1)
    return (NULL);
  if ((buffer = malloc(sizeof(char) * (READ_AMOUNT + 1))) == NULL)
    return (NULL);
  if (starter(&charlist, buffer, bytes, fd) == NULL)
    return (NULL);
  scd = charlist;
  if ((tmp = do_list(&charlist, buffer, bytes, fd)) == NULL)
    return (NULL);
  free(buffer);
  if (charlist != NULL)
    {
      line = malloc_put_free(scd, &tmp);
      charlist = tmp;
      return (line);
    }
  return (NULL);
}
