/*
** main.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 21:42:49 2013 Garnero Philip
** Last update Sun May 26 22:19:20 2013 louis-philippe baron
*/

#include	<signal.h>
#include	"h42.h"
#include	"edt.h"

static void	get_sigint()
{
  return ;
}

static int	do_term_exist(char **env)
{
  int		k;

  k = 0;
  while (env[k])
    {
      if (my_cmp(env[k], "TERM=") == 0)
	return (0);
      k++;
    }
  return (1);
}

static int	submain(t_glob *glob, t_caps *caps, char **env)
{
  while (glob->retval == 0)
    {
      if (env[0] && do_term_exist(env) == 0 && (isatty(0) == 1))
      	{
      	  if (edition_line(glob, caps) == ERROR)
      	    return (ERROR);
      	}
      else
      	{
      	  my_putstr("42sh_> ");
	  if ((glob->input = get_next_line(0)) == NULL)
	    return (ERROR);
	}
      if (mysh(glob) == ERROR)
	return (ERROR);
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_glob	glob;
  t_caps	*caps;

  if (env[0] && do_term_exist(env) == 0)
    if ((caps = init_caps(env)) == NULL)
      return (ERROR);
  glob.retval = 0;
  if (ac != 1 && av[0])
    return (error_int("Usage : ./42sh\n"));
  signal(SIGINT, get_sigint);
  if (get_env(env, &(glob).env) == ERROR)
    return (ERROR);
  if (submain(&glob, caps, env) == ERROR)
    return (ERROR);
  if (glob.retval == EXIT)
    return (glob.exit);
  return (glob.retval);
}
