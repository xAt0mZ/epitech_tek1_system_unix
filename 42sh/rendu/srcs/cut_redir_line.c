/*
** cut_redir_line.c for 42sh in /home/lefebv_z//projet/unix/42sh/tree
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Thu May 23 15:59:18 2013 marie lefebvre
** Last update Sun May 26 16:12:33 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

static char	**swap(char **tab, int i)
{
  char		*str;

  str = tab[i + 2];
  tab[i + 2] = tab[i + 1];
  tab[i + 1] = tab[i];
  tab[i] = str;
  return (tab);
}

static char	**swap_to_redir(char **tab, int redir_place)
{
  int		i;

  i = 0;
  while (tab[i] && tab[i][0] != '<' && tab[i][0] != '>')
    i++;
  if (!tab[i])
    return (error_ptr("Missing name for redirect.\n"));
  while (i != redir_place)
    {
      if (!tab[i + 1] || !tab[i + 2])
	return (error_ptr("Missing name for redirect.\n"));
      tab = swap(tab, i++);
    }
  return (tab);
}

static int	redir_good_place(char *str, char **tab, int len)
{
  int		first_redir;
  int		second_redir;

  first_redir = REDIR_CHAR(tab[len - 2][0]);
  if (len < 4)
    second_redir = 1;
  else
    second_redir = REDIR_CHAR(tab[len - 4][0]);
  if ((count_redir_line(str) == 1 && first_redir)
      || (count_redir_line(str) == 2 && first_redir && second_redir))
    return (1);
  return (0);
}

int		is_file_after_redir(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if (tab[i][0] == '<' || tab[i][0] == '>')
	if (!tab[i + 1] || tab[i + 1][0] == '<' || tab[i + 1][0] == '>')
	  return (error_int("Missing name for redirect.\n"));
      i++;
    }
  return (SUCCESS);
}

char		**cut_redir_line(char *str, t_glob *glob)
{
  char		**tab;
  int		len;

  if (!(tab = my_str_to_wordtab(str, " ")))
    return (error_ptr_set_glob(glob, MALLOC_ERROR));
  len = tab_len(tab);
  if (len < 2)
    return (error_ptr("Missing name for redirect.\n"));
  if (is_file_after_redir(tab) == ERROR)
    return (NULL);
  if (redir_good_place(str, tab, len))
    return (stick_back_arg(tab, len));
  if (!(tab = swap_to_redir(tab, len - 2)))
    return (NULL);
  if (redir_good_place(str, tab, len))
    return (stick_back_arg(tab, len));
  if (!(tab = swap_to_redir(tab, len - 4)))
    return (NULL);
  return (stick_back_arg(tab, len));
}
