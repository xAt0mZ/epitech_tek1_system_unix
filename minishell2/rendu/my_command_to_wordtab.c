/*
** my_command_to_wordtab.c for minishell2 in /home/baron_l//local/rendu/projets/system_unix/minishell2/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Feb 21 18:47:54 2013 louis-philippe baron
** Last update Wed Feb 27 20:17:23 2013 louis-philippe baron
*/

#include	"hminishell1.h"

static int	word_count(char *str, char *params)
{
  int		i;
  int		nb;

  i = 0;
  nb = 1;
  while (str[i])
    {
      if (is_in(str[i], params) == 0
	  && is_in(str[i + 1], params) == ERROR)
	nb += 2;
      i++;
    }
  return (nb);
}

static int	get_res(int *i, char *str, char *res, char *param)
{
  int		j;

  j = 0;
  while (str[*i])
    {
      if ((str[*i] == ' ' && is_in(str[*i + 1], param) == 0)
	  || (str[*i] == ' ' && is_in(str[*i - 1], param) == 0))
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

  k = i;
  while (str[i])
    {
      if ((str[i] == ' ' && is_in(str[i + 1], param) == 0)
	  || (str[i] == ' ' && is_in(str[i - 1], param) == 0))
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
	{
	  return (NULL);
	}
      get_res(&i, str, res[k], params);
      k++;
    }
  res[k] = NULL;
  return (res);
}
