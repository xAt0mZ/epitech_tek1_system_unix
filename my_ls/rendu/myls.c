/*
** my_ls.c for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Tue Nov 27 12:08:07 2012 louis-philippe baron
** Last update Sun Dec  2 23:19:19 2012 louis-philippe baron
*/

/* lRdrt */

#include	<unistd.h>
#include	<stdlib.h>
#include	"hmy_ls.h"
#include	<dirent.h>
#include	<pwd.h>
#include	<grp.h>
#include	<time.h>
#include	<sys/types.h>
#include	<sys/stat.h>


int		my_ls(t_data *data)
{
  if (data->options[1] == 'r')
    r_option(data->files);
  if (data->options[2] == 'd' || data->options[4] == 'R'
      || data->options[3] == 't')
    {
      my_printf("Options d, t and R aren't supported\n");
      return (ERROR);
    }
  if (data->options[0] == 'l')
    start_l_option(data);
  return (0);
}

char		**myls(char *str)
{
  DIR		*stream;
  struct dirent	*rd;
  char		**wdtb;
  int		k;

  if ((wdtb = malloc(sizeof(*wdtb))) == NULL)
    return (NULL);
  wdtb[0] = NULL;
  if ((stream = opendir(str)) == NULL)
    return (NULL);
  while ((rd = readdir(stream)))
    {
      if (rd->d_name[0] != '.')
	if ((wdtb = put_to_wordtab(rd->d_name, wdtb)) == NULL)
	  return (NULL);
    }
  k = 0;
  while (wdtb[k++]);
  if (k >= 2)
    swap_alpha(wdtb);
  closedir(stream);
  return (wdtb);
}
