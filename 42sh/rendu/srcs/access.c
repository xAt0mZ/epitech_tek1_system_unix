/*
** access.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/srcs
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Sat May 25 15:49:24 2013 Garnero Philip
** Last update Sun May 26 17:52:35 2013 louis-philippe baron
*/

#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"h42.h"

static int	isbin(char *bin)
{
  int		i;

  i = 0;
  while (bin[i])
    {
      if (bin[i] == '/')
	return (1);
      i = i + 1;
    }
  return (0);
}

static int	get_longest(char **path)
{
  int		i;
  int		max;

  i = 0;
  max = 0;
  while (path[i])
    {
      if (max < my_strlen(path[i]))
	max = my_strlen(path[i]);
      i = i + 1;
    }
  return (max);
}

char	*see_access(char *bin, t_list *tmp)
{
  char	**path;
  char	*buffer;
  int	max;
  int	i;

  if (bin == NULL)
    return (NULL);
  if (isbin(bin) && (access(bin, X_OK)) == 0)
    return (bin);
  if (isbin(bin) == 1 || tmp == NULL || (path = get_path(tmp->comp)) == NULL)
    return (NULL);
  max = get_longest(path);
  if ((buffer = malloc(sizeof(char) * (my_strlen(bin) + max + 1))) == NULL)
    return (error_ptr(MALLOC_ERROR));
  i = 0;
  memset(buffer, 0, my_strlen(bin) + max);
  while (path[i])
    {
      my_strcat(buffer, path[i]);
      my_strcat(buffer, bin);
      if ((access(buffer, X_OK)) == 0)
	return (buffer);
      memset(buffer, 0, my_strlen(bin) + max);
      i = i + 1;
    }
  return (NULL);
}

int	is_builtins(char **dtab)
{
  if (my_strcmp(dtab[0], "cd") == 0
      || my_strcmp(dtab[0], "env") == 0
      || my_strcmp(dtab[0], "setenv") == 0
      || my_strcmp(dtab[0], "unsetenv") == 0
      || my_strcmp(dtab[0], "echo") == 0
      || my_strcmp(dtab[0], "exit") == 0)
    return (1);
  return (0);
}
