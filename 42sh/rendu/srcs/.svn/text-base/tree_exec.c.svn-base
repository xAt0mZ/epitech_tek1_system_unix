/*
** tree_exec.c for 42sh in /home/lefebv_z//projet/unix/42sh/42sh-2017-baron_l
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Fri May 24 13:56:20 2013 marie lefebvre
** Last update Sun May 26 16:28:42 2013 marie lefebvre
*/

#include	<sys/wait.h>
#include	<unistd.h>
#include	"h42.h"

int		tree_exec_command(char *token, t_glob *glob)
{
  char		**command;
  char		**env;
  int		ret;
  int		status;

  if (!(command = check_command(token, glob)))
    return (ERROR);
  if (!(env = transform_list(glob->env)))
    {
      glob->retval = ERROR;
      return (ERROR);
    }
  if ((ret = fork()) == -1)
    {
      glob->retval = ERROR;
      return (error_int("Can't fork\n"));
    }
  if (ret == 0)
    return (choose_prog(command, env, glob));
  wait(&status);
  if (WIFSIGNALED(status) != 0)
    putstr_fd(2, "Child process was terminated by a signal\n");
  return (status);
}

int	tree_exec_builtins(char **command, t_glob *glob)
{
  char	**env;

  if (!(env = transform_list(glob->env)))
    {
      glob->retval = ERROR;
      return (ERROR);
    }
  return (choose_prog(command, env, glob));
}
