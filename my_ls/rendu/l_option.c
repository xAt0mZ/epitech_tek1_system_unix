/*
** l_option.c for my_ls in /home/baron_l//local/rendu/piscine/projets/my_ls/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Nov 29 15:19:18 2012 louis-philippe baron
** Last update Sun Dec  2 23:16:24 2012 louis-philippe baron
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"hmy_ls.h"
#include	<dirent.h>
#include	<pwd.h>
#include	<grp.h>
#include	<time.h>
#include	<sys/types.h>
#include	<sys/stat.h>

int		start_l_option(t_data *data)
{
  int		k;
  char		**wdtb;

  k = 0;
  if (data->files[k])
    while (data->files[k])
      {
	l_option(data->files[k], ".");
	k++;
      }
  else
    {
      if ((wdtb = myls(".")) == NULL)
	return (ERROR);
      while (wdtb[k])
	{
	  l_option(wdtb[k], ".");
	  k++;
	}
    }
  return (0);
}

int		l_option(char *wdtb, char *str)
{
  t_file	*file;
  struct stat	s_stat;
  struct passwd	*pwuid;
  struct group	*grgid;

  if ((file = malloc(sizeof(*file))) == NULL)
    return (ERROR);
  if ((file->path = get_path(str, wdtb)) == NULL)
    return (ERROR);
  stat(file->path, &s_stat);
  pwuid = getpwuid(s_stat.st_uid);
  grgid = getgrgid(s_stat.st_gid);
  file->time = ctime(&s_stat.st_mtime);
  if ((file->mode = get_mode(s_stat.st_mode, "01234567")) == NULL)
    return (ERROR);
  if ((file->res_time = copy_time(file->time)) == NULL)
    return (ERROR);
  if ((file->rights = get_rights(file->mode)) == NULL)
    return (ERROR);
  my_printf("%s %d %s %s %d\t%s %s\n", file->rights, s_stat.st_nlink,
	    pwuid->pw_name, grgid->gr_name, s_stat.st_size,
	    file->res_time, wdtb);
  freeall_l_option(file);
  return (0);
}
