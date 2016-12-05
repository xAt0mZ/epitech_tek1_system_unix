/*
** epurtest.c for minishell2 in /home/baron_l//local/rendu/projets/system_unix/minishell2/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Feb 25 17:14:30 2013 louis-philippe baron
** Last update Sun May 26 16:13:08 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

static int	clean_str(char *str)
{
  int		i;
  char		bool;

  i = 0;
  bool = 0;
  while (str[i])
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      if (!bool && str[i] == '\t')
	str[i] = ' ';
      i++;
    }
  return (0);
}

static	char	*copy(char *str, int size, char bool)
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
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      if ((!bool && ((str[i] != ' ' && str[i] != ';') ||
		     (i && ((str[i] == ' ' && str[i - 1] != ' ') ||
			    (str[i] == ';' && str[i - 1] != ';'))))) || bool)
	res[j++] = str[i];
      i++;
    }
  res[j] = '\0';
  if (j && res[j - 1] == ' ')
    res[j - 1] = '\0';
  return (res);
}

static	char	*spaces(char *str, int j, char *param, char bool)
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
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      if (is_in(str[i], param, bool) == 0 && i &&
	  is_in(str[i - 1], param, bool) == ERROR && str[i - 1] != ' ')
	res[j++] = ' ';
      res[j++] = str[i];
      if (is_in(str[i], param, bool) == 0 &&
	  is_in(str[i + 1], param, bool) == ERROR && str[i + 1] != ' ')
	res[j++] = ' ';
      i++;
    }
  res[j] = '\0';
  return (res);
}

static	char	*add_spaces(char *str, char *param, char bool)
{
  int		i;
  int		j;
  char		*res;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      if (is_in(str[i], param, bool) == 0 && i &&
	  is_in(str[i - 1], param, bool) == ERROR && str[i - 1] != ' ')
	j++;
      if (is_in(str[i], param, bool) == 0 &&
	  is_in(str[i + 1], param, bool) == ERROR && str[i + 1] != ' ')
	j++;
      i++;
    }
  if ((res = spaces(str, j, param, 0)) == NULL)
    return (NULL);
  free(str);
  return (res);
}

char	*epur_str(char *str, char *param, char bool)
{
  int	i;
  int	j;
  char	*res;

  i = 0;
  j = 0;
  clean_str(str);
  while (str[i])
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      if ((!bool && ((str[i] != ' ' && str[i] != ';') ||
		     (i && ((str[i] == ' ' && str[i - 1] != ' ') ||
			    (str[i] == ';' && str[i - 1] != ';'))))) || bool)
	j++;
      i++;
    }
  if ((res = copy(str, j, 0)) == NULL
      || (res = add_spaces(res, param, 0)) == NULL)
    return (error_ptr("Problem in memory allocation during epur_str\n"));
  free(str);
  return (res);
}
