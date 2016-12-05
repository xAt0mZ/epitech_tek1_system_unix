/*
** sort_params.c for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Nov 30 17:20:13 2012 louis-philippe baron
** Last update Sun Dec  2 22:49:14 2012 louis-philippe baron
*/

#include	"hmy_ls.h"
#include	<stdlib.h>

int		fill_files(char **res, char *av, int nb)
{
  int		i;
  char		*cpy;

  if ((cpy = malloc((my_strlen(av) + 1) * sizeof(char))) == NULL)
    return (ERROR);
  i = 0;
  while (av[i])
    {
      cpy[i] = av[i];
      i++;
    }
  cpy[i] = '\0';
  res[nb] = cpy;
  return (0);
}

char		**sort_files(int ac, char **av)
{
  int		k;
  char		**res;
  int		nb;

  k = 1;
  nb = 0;
  while (k < ac)
    {
      if (av[k][0] != '-')
	nb++;
      k++;
    }
  if ((res = malloc((nb + 1) * sizeof(char *))) == NULL)
    return (NULL);
  nb = 0;
  k = 1;
  while (k < ac)
    {
      if (av[k][0] != '-')
	{
	  fill_files(res, av[k], nb);
	  nb++;
	}
      k++;
    }
  res[nb] = NULL;
  return (res);
}

int		fill_options(char *res, char *av)
{
  int		i;

  i = 1;
  while (av[i])
    {
      if (av[i] == 'l')
	res[0] = 'l';
      else if (av[i] == 'r')
	res[1] = 'r';
      else if (av[i] == 'd')
	res[2] = 'd';
      else if (av[i] == 't')
	res[3] = 't';
      else if (av[i] == 'R')
	res[4] = 'R';
      else
	{
	  my_printf("Wrong option has been set\n");
	  free(res);
	  return (1);
	}
      i++;
    }
  return (0);
}

char		*sort_options(int ac, char **av)
{
  int		k;
  char		*res;

  if ((res = my_malloc((5 + 1) * sizeof(char))) == NULL)
    return (NULL);
  k = 1;
  while (k < ac)
    {
      if (av[k][0] == '-')
	if (fill_options(res, av[k]) == 1)
	  return (NULL);
      k++;
    }
  return (res);
}
