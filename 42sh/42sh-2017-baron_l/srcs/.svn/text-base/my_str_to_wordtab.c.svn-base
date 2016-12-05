/*
** my_str_to_wordtab.c for minishell1 in /home/baron_l/local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Tue Dec 18 10:31:05 2012 louis-philippe baron
** Last update Sun May 26 16:20:32 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

int	is_in(char c, char *params, char bool)
{
  int	i;

  if (bool)
    return (ERROR);
  i = 0;
  while (params[i])
    {
      if (params[i] == c)
	return (0);
      i++;
    }
  return (ERROR);
}

static char	*get_res(int k, int i, char *str)
{
  char		*res;
  int		j;

  if ((res = malloc((i - k + 1) * sizeof(char))) == NULL)
    return (NULL);
  j = 0;
  if (str[k] == ' ')
    k++;
  while (k < i)
    {
      res[j] = str[k];
      k++;
      j++;
    }
  res[j] = '\0';
  if (j && res[j - 1] == ' ')
    res[j - 1] = '\0';
  return (res);
}

static char	*strcpy_for_wdtb(char *str, int max, char *params, int k)
{
  int		i;
  char		*res;
  char		bool;

  i = 0;
  bool = 0;
  while (str[i] && k < max)
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      if (is_in(str[i], params, bool) != ERROR)
	k++;
      i++;
    }
  k = i;
  while (str[i] && is_in(str[i], params, bool) == ERROR)
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      i++;
    }
  if ((res = get_res(k, i, str)) == NULL)
    return (NULL);
  return (res);
}

static int	word_count(char *str, char *params)
{
  int		i;
  int		nb;
  char		bool;

  i = 0;
  nb = 1;
  bool = 0;
  while (str[i])
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      if (is_in(str[i], params, bool) == 0
	  && is_in(str[i + 1], params, bool) == ERROR)
	nb++;
      i++;
    }
  return (nb);
}

char	**my_str_to_wordtab(char *str, char *params)
{
  char	**res;
  int	nb;
  int	i;

  nb = word_count(str, params);
  if ((res = malloc((nb + 1) * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  while (i < nb)
    {
      if ((res[i] = strcpy_for_wdtb(str, i, params, 0)) == NULL)
	return (NULL);
      i++;
    }
  res[i] = NULL;
  if (i && res[i - 1][0] == '\0')
    {
      free(res[i - 1]);
      res[i - 1] = NULL;
    }
  return (res);
}
