/*
** tree_pipes.c for 42sh in /home/lefebv_z//projet/unix/42sh/42sh-2017-baron_l/tree
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Tue May 21 10:42:42 2013 marie lefebvre
** Last update Sun May 26 21:07:55 2013 marie lefebvre
*/

#include	<unistd.h>
#include	<sys/wait.h>
#include	"h42.h"

int		tree_pipe_exec(t_tree *tree, t_glob *glob, int files[])
{
  char		**command;
  char		**env;

  if (tree->token[0] == '<')
    return (tree_redir_and_exec(tree, glob, files[0], -1));
  else if (tree->token[0] == '>')
    return (tree_redir_and_exec(tree, glob, files[1], -1));
  if (!(command = my_str_to_wordtab(tree->token, " ")))
    return (error_int_set_glob(glob, MALLOC_ERROR));
  command[0] = see_access(command[0], finder("PATH", glob->env));
  env = transform_list(glob->env);
  return (choose_prog(command, env, glob));
}

static int	pipe_father(t_tree *tree, t_glob *glob,
			    int pfd[], int files[])
{
  int		ret;

  close(pfd[1]);
  if (my_strcmp(tree->right->token, "|") == 0)
    return (tree_pipes(tree->right, pfd[0], glob, files));
  else
    {
      if ((ret = vfork()) == -1)
	return (error_int_set_glob(glob, "Can't fork\n"));
      if (ret == 0)
	{
	  if (dup2(pfd[0], 0) == -1)
	    return (error_int_set_glob(glob, "Can't dup\n"));
	  return (tree_pipe_exec(tree->right, glob, files));
	}
      wait(&ret);
      if (WIFSIGNALED(ret) != 0)
	putstr_fd(2, "Child process was terminated by a signal\n");
    }
  return (ret);
}

static int	tree_pipe_dup(t_tree *tree, int right_fd[],
			      int infd, int pfd[])
{
  if (my_strcmp(tree->left->token, "<<") == 0)
    {
      close(right_fd[1]);
      infd = right_fd[0];
    }
  close(pfd[0]);
  if (dup2(infd, 0) == -1)
    return (error_int("Can't dup input\n"));
  if (dup2(pfd[1], 1) == -1)
    return (error_int("Can't dup output\n"));
  return (SUCCESS);
}

int	tree_pipes(t_tree *tree, int infd, t_glob *glob, int files[])
{
  int	ret;
  int	status;
  int	pfd[2];
  int	right_fd[2];

  if (is_double_right(tree->left, files, right_fd, glob) == ERROR)
    return (ERROR);
  if (pipe(pfd) == -1)
    return (error_int_set_glob(glob, "Can't pipe\n"));
  if ((ret = vfork()) == -1)
    return (error_int_set_glob(glob, "Can't fork\n"));
  if (ret == 0)
    {
      if (tree_pipe_dup(tree, right_fd, infd, pfd) == ERROR)
	return (error_int_set_glob(glob, ""));
      return (tree_pipe_exec(tree->left, glob, files));
    }
  if (my_strcmp(tree->left->token, "<<") == 0)
    double_right_redir(tree->left, right_fd, ret);
  ret = pipe_father(tree, glob, pfd, files);
  wait(&status);
  if (WIFSIGNALED(status) != 0)
    putstr_fd(2, "Child process was terminated by a signal\n");
  return ((ret == SUCCESS) ? (status) : (ret));
}

int		pipe_branch(t_tree *tree, t_glob *glob)
{
  int		files[2];
  t_tree	*tmp;

  if (tree_check_pipes(tree, glob) == ERROR)
    return (ERROR);
  files[0] = -1;
  files[1] = -1;
  tmp = tree;
  if (tmp->left->token[0] == '<')
    {
      tmp = tmp->left;
      files[0] = tree_redir_files(tmp->token, tmp->right->token);
      if (files[0] == -1)
	return (ERROR);
      tmp = tmp->prev;
    }
  while (my_strcmp(tmp->token, "|") == 0)
    tmp = tmp->right;
  if (tmp->token[0] == '>')
    if ((files[1] = tree_redir_files(tmp->token, tmp->right->token)) == -1)
      return (ERROR);
  return (tree_pipes(tree, 0, glob, files));
}
