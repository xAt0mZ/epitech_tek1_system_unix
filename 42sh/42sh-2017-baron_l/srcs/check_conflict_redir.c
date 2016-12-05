/*
** check_conflict_redir.c for 42sh in /home/lefebv_z//projet/unix/42sh/42sh-2017-baron_l
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Sat May 25 18:36:09 2013 marie lefebvre
** Last update Sat May 25 18:57:52 2013 marie lefebvre
*/

#include	"h42.h"

static int	is_pipe_conflict(char **tab, int i, int j)
{
  while (j >= 0 && tab[j] && my_strcmp(tab[j], "&&") != 0
	 && my_strcmp(tab[j], "||") != 0)
    {
      if (my_strcmp(tab[j], "|") == 0)
	{
	  if (tab[i][0] == '<')
	    return (error_int("Ambiguous input redirect.\n"));
	  else if (tab[i][0] == '>')
	    return (error_int("Ambiguous output redirect.\n"));
	}
      if (tab[i][0] == '<')
	j--;
      else if (tab[i][0] == '>')
	j++;
    }
  return (SUCCESS);
}

int	check_conflict_redir(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (REDIR_CHAR(tab[i][0]))
	if (is_pipe_conflict(tab, i, i) == ERROR)
	  return (ERROR);
      i++;
    }
  return (SUCCESS);
}
