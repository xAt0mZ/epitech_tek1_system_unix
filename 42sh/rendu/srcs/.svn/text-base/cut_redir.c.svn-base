/*
** cut_redir.c for 42sh in /home/lefebv_z//projet/unix/42sh/tree
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Wed May 22 19:12:20 2013 marie lefebvre
** Last update Sun May 26 16:30:21 2013 marie lefebvre
*/

#define		_BSD_SOURCE
#include	<string.h>
#include	<stdlib.h>
#include	"h42.h"

int		count_redir_line(char *str)
{
  int		i;
  int		redir[2];

  i = 0;
  redir[0] = 0;
  redir[1] = 0;
  while (str[i])
    {
      if (str[i] == '<' || str[i] == '>')
	{
	  if (str[i] == '<')
	    redir[0]++;
	  else if (str[i] == '>')
	    redir[1]++;
	  if (str[i + 1] == str[i])
	    i++;
	}
      i++;
    }
  if (redir[0] > 1)
    return (error_int("Error syntax : multiple redirection '<'\n"));
  if (redir[1] > 1)
    return (error_int("Error syntax : multiple redirection '>'\n"));
  return (redir[0] + redir[1]);
}

int		count_redir(char **tab)
{
  int		i;
  int		redir;
  int		redir_line;

  i = 0;
  redir = 0;
  while (tab[i])
    {
      if ((redir_line = count_redir_line(tab[i++])) == ERROR)
	return (ERROR);
      redir += redir_line;
    }
  return (redir);
}

static char	**create_redir_tab(char **tab, t_glob *glob)
{
  int		nb_redir;
  int		len;
  char		**new;

  if ((nb_redir = count_redir(tab)) == ERROR)
    return (NULL);
  len = tab_len(tab) + (2 * nb_redir);
  if (!(new = malloc(sizeof(char *) * (len + 1))))
    return (error_ptr_set_glob(glob, MALLOC_ERROR));
  return (new);
}

char		**cut_redir_tab(char **tab, t_glob *glob)
{
  char		**new;
  int		i;
  int		j;
  char		**tmp;
  int		k;

  if (!(new = create_redir_tab(tab, glob)))
    return (NULL);
  i = 0;
  j = 0;
  while (tab[i])
    {
      if (!count_redir_line(tab[i]))
	new[j++] = tab[i++];
      else
	{
	  if (!(tmp = cut_redir_line(tab[i++], glob)))
	    return (NULL);
	  k = 0;
	  while (tmp[k])
	    new[j++] = strdup(tmp[k++]);
	}
    }
  new[j] = NULL;
  return (new);
}
