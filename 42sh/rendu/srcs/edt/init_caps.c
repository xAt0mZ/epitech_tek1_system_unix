/*
** init_caps.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Mon May 13 01:57:07 2013 damien sauvalle
** Last update Sun May 26 16:29:55 2013 damien sauvalle
*/

#include	<term.h>
#include	<stdlib.h>
#include	"edt.h"

char		*recup_term(char **env)
{
  int		i;

  i = 0;
  while (env[i] && strncmp(env[i], "TERM=", 5) != 0)
    i++;
  return (strdup(env[i] + 5));
}

char		*my_tgetstr(char *id, char *term) /*recuper la variable TERM*/
{
  char		*name;

  tgetent(NULL, term);
  name = tgetstr(id, NULL);
  return (name);
}

t_caps		*init_caps(char **env)
{
  t_caps	*caps;
  char		*name;

  name = recup_term(env);
  caps = malloc(sizeof(t_caps));
  if (caps == NULL)
    return (NULL);  
  if (((caps->clearsc = my_tgetstr("cl", name)) == NULL) ||
      ((caps->sauvc = my_tgetstr("sc", name)) == NULL) ||
      ((caps->restc = my_tgetstr("rc", name)) == NULL) ||
      ((caps->cm = my_tgetstr("cm", name)) == NULL) ||
      ((caps->lclean = my_tgetstr("dl", name)) == NULL) ||
      ((caps->col = tgetnum("co")) == -1) ||
      ((caps->line = tgetnum("li")) == -1))
    return (NULL);
  return (caps);
}

void		free_caps(t_caps *caps)
{
  free(caps->clearsc);
  free(caps->sauvc);
  free(caps->restc);
  free(caps->cm);
  free(caps->lclean);
  free(caps);
}
