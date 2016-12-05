/*
** epurtest.c for minishell2 in /home/baron_l//local/rendu/projets/system_unix/minishell2/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Feb 25 17:14:30 2013 louis-philippe baron
** Last update Mon Mar  4 18:19:02 2013 louis-philippe baron
*/

#include	"hminishell1.h"

static int	clean_str(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
  return (0);
}

static	char	*copy(char *str, int size)
{
  char		*res;
  int		i;
  int		j;

  if ((res = malloc((size + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] != ' ' || (i && str[i] == ' ' && str[i - 1] != ' '))
	{
	  res[j] = str[i];
	  j++;
	}
      i++;
    }
  res[j] = '\0';
  if (j && res[j - 1] == ' ')
    res[j - 1] = '\0';
  return (res);
}

static	char	*spaces(char *str, int j, char *param)
{
  int		i;
  char		*res;

  i = my_strlen(str);
  if ((res = malloc((i + j + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i])
    {
      if (is_in(str[i], param) == 0 && i &&
	  is_in(str[i - 1], param) == ERROR && str[i - 1] != ' ')
	res[j++] = ' ';
      res[j++] = str[i];
      if (is_in(str[i], param) == 0 &&
	  is_in(str[i + 1], param) == ERROR && str[i + 1] != ' ')
	res[j++] = ' ';
      i++;
    }
  res[j] = '\0';
  return (res);
}

static	char	*add_spaces(char *str, char *param)
{
  int		i;
  int		j;
  char		*res;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (is_in(str[i], param) == 0 && i &&
	  is_in(str[i - 1], param) == ERROR && str[i - 1] != ' ')
	j++;
      if (is_in(str[i], param) == 0 &&
	  is_in(str[i + 1], param) == ERROR && str[i + 1] != ' ')
	j++;
      i++;
    }
  if ((res = spaces(str, j, param)) == NULL)
    return (NULL);
  free(str);
  return (res);
}

char		*epur_str(char *str, char *param)
{
  int		i;
  int		j;
  char		*res;

  i = 0;
  j = 0;
  clean_str(str);
  while (str[i])
    {
      if (str[i] != ' ' || (i && str[i] == ' ' && str[i - 1] != ' '))
	j++;
      i++;
    }
  if (((res = copy(str, j)) == NULL)
      || ((res = add_spaces(res, param)) == NULL))
    {
      my_printf("Problem in memory allocation during epur_str\n");
      return (NULL);
    }
  free(str);
  return (res);
}
