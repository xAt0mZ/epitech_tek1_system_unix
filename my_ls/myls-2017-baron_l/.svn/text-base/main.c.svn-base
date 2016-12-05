/*
** main.c for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sun Nov 25 15:00:07 2012 louis-philippe baron
** Last update Sun Dec  2 23:11:07 2012 louis-philippe baron
*/

#include	"hmy_ls.h"
#include	<stdlib.h>

t_data		*sort_params(int ac, char **av)
{
  t_data	*data;

  if ((data = malloc(sizeof(*data))) == NULL)
    return (NULL);
  if ((data->files = sort_files(ac, av)) == NULL)
    return (NULL);
  if ((data->options = sort_options(ac, av)) == NULL)
    return (NULL);
  my_ls(data);
  free_params(data);
  return (data);
}

int		main(int ac, char **av)
{
  char		**wdtb;

  if (ac > 1)
    {
      if (sort_params(ac, av) == NULL)
	{
	  my_printf("Error while listing files or options\n");
	  return (ERROR);
	}
    }
  else
    {
      if ((wdtb = myls(".")) == NULL)
	return (ERROR);
      sort_wordtab(wdtb);
      free_wordtab(wdtb);
    }
  return (0);
}
