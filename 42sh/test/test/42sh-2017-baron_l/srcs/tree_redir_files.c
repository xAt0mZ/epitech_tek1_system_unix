/*
** tree_redir_files.c for 42sh in /home/lefebv_z//projet/unix/42sh/new_tree
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Thu May 23 20:45:38 2013 marie lefebvre
** Last update Sun May 26 16:26:00 2013 marie lefebvre
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	"h42.h"

static int	tree_right_redir_file(char *sep, char *name)
{
  int		mode;
  int		flag;
  int		fd;

  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
  if (my_strcmp(sep, ">") == 0)
    flag = O_RDWR | O_CREAT | O_TRUNC;
  else
    flag = O_RDWR | O_CREAT | O_APPEND;
  if ((fd = open(name, flag, mode)) == -1)
    {
      putstr_fd(2, "Can't open or create ");
      putstr_fd(2, name);
      putstr_fd(2, "\n");
      return (-1);
    }
  return (fd);
}

int	tree_redir_files(char *sep, char *name)
{
  int	fd;

  fd = 0;
  if (my_strcmp(sep, "<") == 0)
    {
      if ((fd = open(name, O_RDONLY)) == -1)
	{
	  putstr_fd(2, "Could not find ");
	  putstr_fd(2, name);
	  putstr_fd(2, "\n");
	  return (-1);
	}
    }
  else if (my_strcmp(sep, ">") == 0 || my_strcmp(sep, ">>") == 0)
    fd = tree_right_redir_file(sep, name);
  return (fd);
}
