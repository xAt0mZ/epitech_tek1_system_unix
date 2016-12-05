/*
** tree_redir.c for 42sh in /home/lefebv_z//projet/unix/42sh/42sh-2017-baron_l/tree
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Tue May 21 14:34:57 2013 marie lefebvre
** Last update Sun May 26 16:29:20 2013 marie lefebvre
*/

#include	<sys/wait.h>
#include	<unistd.h>
#include	"h42.h"

int	tree_redir_and_exec(t_tree *tree, t_glob *glob, int fd, int fd2)
{
  int	files[2];

  if (fd2 != -1)
    {
      if (tree->right->token[0] == '<')
	dup2(fd2, 0);
      else if (tree->right->token[0] == '>')
	dup2(fd2, 1);
    }
  if (fd != -1)
    {
      if (tree->token[0] == '<')
	dup2(fd, 0);
      else if (tree->token[0] == '>')
	dup2(fd, 1);
    }
  files[0] = -1;
  files[1] = -1;
  return (tree_pipe_exec(tree->left, glob, files));
}

static int	tree_redir_fds(t_tree *tree, int fd[])
{
  if (tree->right->type == FILE)
    {
      if ((fd[0] = tree_redir_files(tree->token, tree->right->token)) == -1)
	return (ERROR);
    }
  else if (tree->right->type == SEPARATOR)
    {
      fd[0] = tree_redir_files(tree->token, tree->right->left->token);
      if (fd[0] == -1)
	return (ERROR);
      fd[1] = tree_redir_files(tree->right->token, tree->right->right->token);
      if (fd[1] == -1)
	{
	  close(fd[0]);
	  return (ERROR);
	}
    }
  return (SUCCESS);
}

static int	tree_redir_fork(t_tree *tree, t_glob *glob,
				int pfd[], int files[])
{
  int		ret;

  if ((ret = fork()) == -1)
    return (error_int_set_glob(glob, "Can't fork\n"));
  if (ret == 0)
    {
      if (my_strcmp(tree->token, "<<") == 0
	  || my_strcmp(tree->right->token, "<<") == 0)
	close(pfd[1]);
      tree_redir_and_exec(tree, glob, files[0], files[1]);
      return (0);
    }
  if (my_strcmp(tree->token, "<<") == 0
      || my_strcmp(tree->right->token, "<<") == 0)
    double_right_redir(tree, pfd);
  wait(&ret);
  if (WIFSIGNALED(ret) != 0)
    putstr_fd(2, "Child process was terminated by a signal\n");
  return (ret);
}

int		tree_redir(t_tree *tree, t_glob *glob)
{
  int		files[2];
  char		**command;
  int		pfd[2];

  files[0] = -1;
  files[1] = -1;
  if (tree_redir_fds(tree, files) == ERROR)
    return (ERROR);
  if (!(command = my_str_to_wordtab(tree->left->token, " ")))
    return (error_int_set_glob(glob, MALLOC_ERROR));
  if (is_builtins(command))
    return (tree_exec_builtins(command, glob));
  free_tab(command);
  if (!check_command(tree->left->token, glob))
    return (ERROR);
  if (is_double_right(tree, files, pfd, glob) == ERROR)
    return (ERROR);
  return (tree_redir_fork(tree, glob, pfd, files));
}
