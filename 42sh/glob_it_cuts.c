/*
** glob_it_cuts.c for 42sh in /home/baron_l//local/rendu/projets/system_unix/42sh/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri May 24 17:49:58 2013 louis-philippe baron
** Last update Fri May 24 21:42:24 2013 louis-philippe baron
*/

#include	"h42.h"

static char	*get_first(char *str, int i, char *param)
{
  char		*res;
  int		cpt[2];

  while (i > 0 && str[i] != ' ')
    i--;
  cpt[0] = i;
  i = find_start(str, i, param);
  if ((res = malloc((cpt[0] - i + 1) * sizeof(char))) == NULL)
    return (NULL);
  cpt[0] -= i;
  cpt[1] = 0;
  while (cpt[1] < cpt[0])
    {
      res[cpt[1]] = str[i++];
      cpt[1] += 1;
    }
  res[cpt[1]] = '\0';
  return (res);
}

static char	*get_second(char *str, int *i)
{
  char		*res;
  int		j;

  while (*i >= 0 && str[*i] != ' ')
    *i -= 1;
  if (*i)
    *i += 1;
  j = *i;
  while (str[j] && str[j] != ' ')
    j++;
  if ((res = malloc((j - *i + 1) * sizeof(char))) == NULL)
    return (NULL);
  j = 0;
  while (str[*i] && str[*i] != ' ')
    {
      res[j++] = str[*i];
      *i += 1;
    }
  res[j] = '\0';
  return (res);
}

static char	*save_end(char *str, int i)
{
  char		*res;
  int		j;

  j = i;
  while (str[j])
    j++;
  if ((res = malloc((j - i + 1) * sizeof(char))) == NULL)
    return (NULL);
  j = 0;
  while (str[i])
    res[j++] = str[i++];
  res[j] = '\0';
  return (res);
}

static int	contain_glob(char *str, char *param)
{
  int		i;
  char		bool;

  i = 0;
  bool = 0;
  while (str[i])
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      if (is_in(str[i], param, bool) == 0)
	return (0);
      i++;
    }
  return (ERROR);
}

int		do_multi_cuts(char *str, int *cpt, char *param, char **res)
{
  if ((res[cpt[1]] = get_first(str, cpt[0], param)) == NULL)
    return (NULL);
  cpt[1] += 1;
  if ((res[cpt[1]] = get_second(str, &cpt[0])) == NULL)
    return (NULL);
  cpt[1] += 1;
  if ((res[cpt[1]] = save_end(str, cpt[0])) == NULL)
    return (NULL);
  if (str[cpt[0]] == ' ')
    cpt[0] -= 1;
  if (res[cpt[1]][0] == '\0' || contain_glob(res[cpt[1]], param) == 0)
    {
      free(res[cpt[1]]);
      res[cpt[1]] = NULL;
    }
  else
    cpt[1] += 1;
  return (0);
}
