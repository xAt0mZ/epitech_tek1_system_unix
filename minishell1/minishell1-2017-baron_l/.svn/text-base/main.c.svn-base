/*
** main.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Dec 17 14:58:49 2012 louis-philippe baron
** Last update Sun Dec 30 20:37:21 2012 louis-philippe baron
*/

#include	"hminishell1.h"

int		get_len_env(char **env)
{
  int		i;

  i = 0;
  if (env)
    while (env[i])
      i++;
  return (i);
}

int		main(int ac, char **av, char **env)
{
  char		*input;
  int		envlen;
  int		k;

  k = 0;
  envlen = get_len_env(env);
  if (ac == 1 && av[0])
    while (42)
      {
	if (get_len_env(env) >= envlen - 2)
	  {
	    if ((env = clone_env(env, envlen + 42, k++)) == NULL)
	      return (ERROR);
	    envlen += 42;
	  }
	my_printf("minishell_> ");
	if ((input = get_next_line(0)) == NULL)
	  return (ERROR);
	if (mysh(input, env) == ERROR)
	  return (ERROR);
      }
  return (0);
}
