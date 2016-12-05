/*
** my_command_to_wordtab.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/tree
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 17:29:30 2013 Garnero Philip
** Last update Sun May 26 16:20:50 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

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
	nb += 2;
      i++;
    }
  return (nb);
}

static int	get_res(int *i, char *str, char *res, char *param)
{
  int		j;
  char		bool;

  j = 0;
  bool = 0;
  while (str[*i])
    {
      if (str[*i] == '\'' || str[*i] == '\"')
	bool_condition(&bool, str[*i]);
      if ((str[*i] == ' ' && is_in(str[*i + 1], param, bool) == 0)
	  || (str[*i] == ' ' && is_in(str[*i - 1], param, bool) == 0))
	{
	  *i += 1;
	  res[j] = '\0';
	  return (0);
	}
      res[j] = str[*i];
      *i += 1;
      j++;
    }
  res[j] = '\0';
  return (0);
}

static char	*command_malloc(int i, char *str, char *param)
{
  int		k;
  char		*res;
  char		bool;

  k = i;
  bool = 0;
  while (str[i])
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      if ((str[i] == ' ' && is_in(str[i + 1], param, bool) == 0)
	  || (str[i] == ' ' && is_in(str[i - 1], param, bool) == 0))
	{
	  if ((res = malloc((i - k + 1) * sizeof(char))) == NULL)
	    return (NULL);
	  return (res);
	}
      i++;
    }
  if ((res = malloc((i - k + 1) * sizeof(char))) == NULL)
    return (NULL);
  return (res);
}

char		**my_command_to_wordtab(char *str, char *params)
{
  char		**res;
  int		nb;
  int		i;
  int		k;

  nb = word_count(str, params);
  if ((res = malloc((nb + 1) * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  k = 0;
  while (k < nb)
    {
      if ((res[k] = command_malloc(i, str, params)) == NULL)
	return (NULL);
      get_res(&i, str, res[k], params);
      k++;
    }
  res[k] = NULL;
  if (k && res[k - 1][0] == '\0')
    {
      free(res[k - 1]);
      res[k - 1] = NULL;
    }
  return (res);
}
