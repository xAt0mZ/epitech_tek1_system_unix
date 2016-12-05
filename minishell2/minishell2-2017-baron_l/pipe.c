/*
** pipe.c for minishell2 in /home/baron_l//local/rendu/projets/system_unix/minishell2/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Feb 21 20:14:31 2013 louis-philippe baron
** Last update Tue Mar  5 09:31:13 2013 louis-philippe baron
*/

#include	"hminishell1.h"

static int	father(int *pipefd, char **tmp, t_list *list, char **path)
{
  close(pipefd[1]);
  if (dup2(pipefd[0], 0) == -1)
    {
      my_printf("Dup2 failed for pipe execution\n");
      return (ERROR);
    }
  if (no_redir(tmp[2], list, path) == ERROR)
    return (ERROR);
  return (0);
}

static int	son(int *pipefd, char **tmp, t_list *list, char **path)
{
  close(pipefd[0]);
  if (dup2(pipefd[1], 1) == -1)
    {
      my_printf("Dup2 failed for pipe execution\n");
      return (ERROR);
    }
  if (no_redir(tmp[0], list, path) == ERROR)
    return (ERROR);
  return (0);
}

int		my_pipe(char **tmp, t_list *list, char **path)
{
  int		pipefd[2];
  int		pid;

  if (pipe(pipefd) == -1)
    {
      my_printf("Pipe error\n");
      return (ERROR);
    }
  if ((pid = fork()) == -1)
    {
      my_printf("Fork failed for pipe execution\n");
      return (ERROR);
    }
  if (pid == 0 && son(pipefd, tmp, list, path) == ERROR)
    return (ERROR);
  else
    {
      wait(&pid);
      if (father(pipefd, tmp, list, path) == ERROR)
	return (ERROR);
    }
  return (0);
}
