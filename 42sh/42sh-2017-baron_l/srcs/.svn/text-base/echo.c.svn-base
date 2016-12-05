/*
** echo.c for 42sh in /home/lefebv_z//projet/unix/42sh
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Fri May 10 18:37:46 2013 marie lefebvre
** Last update Fri May 24 14:40:39 2013 marie lefebvre
*/

#include	"h42.h"

static int	echo_option(char **av, int *opt_n, int *opt_e)
{
  int		i;
  int		is_opt;

  i = 1;
  is_opt = 1;
  while (av[i] && is_opt)
    {
      if (my_strcmp(av[i], "-n") == 0)
	*opt_n = 1;
      else if (my_strcmp(av[i], "-e") == 0)
	*opt_e = 1;
      else if (my_strcmp(av[i], "-E") == 0)
	*opt_e = 0;
      else
	is_opt = 0;
      i++;
    }
  return (i - 1);
}

static int	interprete_char(char *str, char *opt, int i)
{
  int		j;

  j = 0;
  while (opt[j] && opt[j] != str[i + 1])
    j++;
  if (opt[j])
    {
      str[i] = j + 7;
      del_case(str + i + 1);
    }
  else if (str[i + 1] == '\\')
    del_case(str + i + 1);
  else if (str[i + 1] == 'c')
    {
      str[i--] = '\0';
      my_putstr(str);
      return (1);
    }
  return (0);
}

static int	interprete_str(char *str)
{
  int		i;
  char		*opt;

  opt = "abtnvfr";
  i = 0;
  while (str[i])
    {
      if (str[i] == '\\')
	if (interprete_char(str, opt, i) == 1)
	  return (1);
      i++;
    }
  return (0);
}

static int	do_echo(char **tab, int i, int opt_e)
{
  while (tab[i])
    {
      if (opt_e == 1)
	if (interprete_str(tab[i]) == 1)
	  return (1);
      my_putstr(tab[i++]);
      if (tab[i])
	my_putchar(' ');
    }
  return (0);
}

int		my_echo(int ac, char **tab)
{
  int		opt_n;
  int		opt_e;
  int		i;

  opt_n = 0;
  opt_e = 0;
  if (ac > 1)
    {
      i = echo_option(tab, &opt_n, &opt_e);
      if (do_echo(tab, i, opt_e) == 1)
	return (SUCCESS);
    }
  if (opt_n == 0)
    my_putchar('\n');
  return (SUCCESS);
}
