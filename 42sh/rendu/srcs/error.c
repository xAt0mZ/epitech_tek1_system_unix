/*
** error.c for 42sh in /home/lefebv_z//projet/unix/42sh/42sh-2017-baron_l/tree
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Tue May 21 11:03:15 2013 marie lefebvre
** Last update Sun May 26 16:13:22 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"h42.h"

int	error_int(char *mess)
{
  putstr_fd(2, mess);
  return (ERROR);
}

int	error_int_set_glob(t_glob *glob, char *mess)
{
  glob->retval = ERROR;
  if (mess[0] != '\0')
    putstr_fd(2, mess);
  return (ERROR);
}

int	error_v_int(char *mess, int ret)
{
  putstr_fd(2, mess);
  return (ret);
}

void	*error_ptr(char *mess)
{
  putstr_fd(2, mess);
  return (NULL);
}

void	*error_ptr_set_glob(t_glob *glob, char *mess)
{
  glob->retval = ERROR;
  if (mess[0] != '\0')
    putstr_fd(2, mess);
  return (NULL);
}
