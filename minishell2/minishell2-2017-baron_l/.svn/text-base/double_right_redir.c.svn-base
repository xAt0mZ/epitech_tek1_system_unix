/*
** double_right_redir.c for minishell2 in /home/baron_l//local/rendu/projets/system_unix/minishell2/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Tue Mar  5 10:04:58 2013 louis-philippe baron
** Last update Tue Mar  5 10:47:47 2013 louis-philippe baron
*/

#include	"hminishell1.h"

int		double_right_redir(char **tmp, t_list *list, char **path)
{
  int		fd;

  if ((fd = open(tmp[2], (O_RDWR | O_CREAT | O_APPEND),
		 (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH))) == -1)
    {
      my_printf("%s: Can't open file\n", tmp[2]);
      return (ERROR);
    }
  if (dup2(fd, 1) == -1)
    {
      my_printf("Dup2 failed for right redir execution\n");
      return (ERROR);
    }
  if (no_redir(tmp[0], list, path) == ERROR)
    return (ERROR);
  return (0);
}
