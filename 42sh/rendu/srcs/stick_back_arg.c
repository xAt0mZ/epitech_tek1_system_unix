/*
** stick_back_arg.c for 42sh in /home/lefebv_z//projet/unix/42sh/tree
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Thu May 23 18:30:47 2013 marie lefebvre
** Last update Sat May 25 20:50:11 2013 marie lefebvre
*/

#define		_BSD_SOURCE
#include	<string.h>
#include	<stdlib.h>
#include	"h42.h"

static int	tab_len_to_redir(char **tab)
{
  int		i;
  int		len;

  i = 0;
  len = 0;
  while (tab[i][0] != '<' && tab[i][0] != '>')
    len += my_strlen(tab[i++]) + 1;
  return (len);
}

static char	**create_stick_tab(char **tab)
{
  char		**new;
  int		len;

  if (!(new = malloc(sizeof(char *) * (2 * count_redir(tab) + 2))))
    {
      free_tab(tab);
      return (NULL);
    }
  if ((len = tab_len_to_redir(tab)) == 0)
    {
      free_tab(tab);
      return (error_ptr("Invalid null command.\n"));
    }
  if (!(new[0] = malloc(sizeof(char) * (tab_len_to_redir(tab) + 1))))
    {
      free_tab(tab);
      return (NULL);
    }
  new[0][0] = '\0';
  return (new);
}

char		**stick_back_arg(char **tab, int len)
{
  char		**new;
  int		i;
  int		j;

  if (!(new = create_stick_tab(tab)))
    return (NULL);
  i = 0;
  while (tab[i][0] != '<' && tab[i][0] != '>')
    {
      new[0] = my_strcat(new[0], tab[i++]);
      if (!REDIR_CHAR(tab[i][0]))
	my_strcat(new[0], " ");
    }
  j = 1;
  while (i < len)
    if (!(new[j++] = strdup(tab[i++])))
      {
	free_tab(tab);
	return (error_ptr("Can't strdup"));
      }
  new[j] = NULL;
  free_tab(tab);
  return (new);
}
