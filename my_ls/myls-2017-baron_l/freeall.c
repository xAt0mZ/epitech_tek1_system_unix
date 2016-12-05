/*
** freeall.c for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Nov 29 16:19:24 2012 louis-philippe baron
** Last update Sun Dec  2 22:06:14 2012 louis-philippe baron
*/

#include	"hmy_ls.h"
#include	<stdlib.h>

int		free_params(t_data *data)
{
  int		k;

  k = 0;
  while (data->files[k])
    {
      free(data->files[k]);
      k++;
    }
  free(data->files);
  free(data->options);
  free(data);
  return (0);
}

int		freeall_l_option(t_file *file)
{
  free(file->path);
  free(file->res_time);
  free(file->mode);
  free(file->rights);
  free(file);
  return (0);
}

int		free_wordtab(char **wdtb)
{
  int		k;

  k = 0;
  while (wdtb[k])
    {
      free(wdtb[k]);
      k++;
    }
  free(wdtb);
  return (0);
}
