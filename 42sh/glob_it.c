/*
** glob_it.c for 42sh in /home/baron_l//local/rendu/projets/system_unix/42sh/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sat May 18 20:36:16 2013 louis-philippe baron
** Last update Sat May 25 16:08:24 2013 louis-philippe baron
*/

#include	"h42.h"

static char	**glob_tmp_allocation(char *str, char bool, char word, char *param)
{
  int		i;
  int		nb;
  char		*res;

  i = 0;
  nb = 1;
  while (str[i])
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      if (!bool && word && str[i] == ' ')
	word = 0;
      if (!bool && !word && is_in(str[i], param, bool) == 0)
	{
	  nb += 2;
	  word = 1;
	}
       i++;
    }
  if ((res = malloc((nb + 2) * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  while (i < nb + 2)
    res[i++] = NULL;
  return (res);
}

int		find_start(char *str, int i, char *param)
{
  char		bool;

  bool = 0;
  while (i > 0 && is_in(str[i], param, bool))
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      i--;
    }
  if (i)
    {
      while (str[i] && str[i] != ' ')
	i++;
    }
  return (i);
}

static char	**cut_str_glob(char *str, char bool, char word, char *param)
{
  char		**res;
  int		cpt[2];

  if ((res = glob_tmp_allocation(str, 0, 0, param)) == NULL)
    return (NULL);
  cpt[0] = 0;
  cpt[1] = 0;
  while (str[cpt[0]])
    {
      if (str[cpt[0]] == '\'' || str[cpt[0]] == '\"')
	bool_condition(&bool, str[cpt[0]]);
      if (!bool && word && str[cpt[0]] == ' ')
	word = 0;
      if (!bool && !word && is_in(str[cpt[0]], param, bool) == 0)
	{
	  if (do_multi_cuts(str, cpt, param, res) == ERROR)
	    return (NULL);
	  word = 1;
	}
      if (str[cpt[0]])
	cpt[0] += 1;
    }
  if (cpt[1])
    res[cpt[1]] = NULL;
  else if ((res[0] = my_strdup(str)) == NULL)
    return (NULL);
  return (res);
}

char		*glob_it(char *str, char *param)
{
  char		**tmp;

  if ((tmp = cut_str_glob(str, 0, 0, param)) == NULL
      || (tmp = clean_it(tmp)) == NULL)
    return (error_ptr("Error in memory allocation during globbing\n"));
  free(str);
  if (glob_loop(tmp, param) == ERROR || (str = glob_cat_all(tmp)) == NULL)
    return (NULL);
  free_wordtab(tmp);
  return (str);
}
