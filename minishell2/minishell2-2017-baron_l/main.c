/*
** main.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Dec 17 14:58:49 2012 louis-philippe baron
** Last update Mon Mar  4 18:02:58 2013 louis-philippe baron
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
  t_list	list;

  list.k = 0;
  list.env = env;
  list.envlen = get_len_env(list.env);
  if (ac == 1 && av[0])
    while (42)
      {
	if (get_len_env(list.env) >= list.envlen)
	  {
	    if ((list.env = clone_env(list.env, list.envlen + 42, list.k++)) == NULL)
	      return (ERROR);
	    list.envlen += 42;
	  }
	my_printf("minishell_> ");
	if ((list.input = get_next_line(0)) == NULL)
	  return (ERROR);
	if (mysh(&list) == ERROR)
	  return (ERROR);
      }
  return (0);
}
