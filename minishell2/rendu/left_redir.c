/*
** left_redir.c for minishell2 in /home/baron_l//local/rendu/projets/system_unix/minishell2/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Feb 28 13:47:14 2013 louis-philippe baron
** Last update Tue Mar  5 16:54:02 2013 louis-philippe baron
*/

#include	"hminishell1.h"

static char	*concat(char *tmp, char *cat)
{
  char		*res;
  int		i;
  int		j;

  if ((res = malloc((my_strlen(tmp) + 1 + 4) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (cat[i])
    res[j++] = cat[i++];
  i = 0;
  while (tmp[i])
    res[j++] = tmp[i++];
  res[j] = '\0';
  return (res);
}

static char	*cpy_pipe()
{
  char		*res;

  if ((res = malloc(2 * sizeof(char))) == NULL)
    return (NULL);
  res[0] = '|';
  res[1] = '\0';
  return (res);
}

static char	**change_tmp(char **tmp)
{
  char		**res;

  if ((res = malloc(3 * sizeof(char *))) == NULL)
    return (NULL);
  res[0] = concat(tmp[2], "cat ");
  res[1] = cpy_pipe();
  res[2] = my_strcpy(tmp[0]);
  if (res[0] == NULL || res[1] == NULL || res[2] == NULL)
    return (NULL);
  free_wordtab(tmp);
  return (res);
}

int		left_redir(char **tmp, t_list *list, char **path)
{
  if ((tmp = change_tmp(tmp)) == NULL)
    {
      my_printf("Problem during parsing for left redir\n");
      return (ERROR);
    }
  list->redir = tmp;
  if (my_pipe(tmp, list, path) == ERROR)
    return (ERROR);
  return (0);
}
