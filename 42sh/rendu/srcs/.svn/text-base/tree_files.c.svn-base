/*
** tree_files.c for 42sh in /home/lefebv_z//projet/unix/42sh/test_arbres
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Thu May 16 15:36:35 2013 marie lefebvre
** Last update Wed May 22 17:47:56 2013 Garnero Philip
*/

#include	"h42.h"

static void	mark_files(t_tree *tree)
{
  if (tree->type == COMMAND)
    tree->type = FILE;
  else if (tree->token[0] == '<' || tree->token[0] == '>')
    {
      tree->left->type = FILE;
      tree->right->type = FILE;
    }
}

int		tree_files(t_tree *tree)
{
  if (tree)
    {
      if (tree->token[0] == '<' || tree->token[0] == '>')
	mark_files(tree->right);
      else
	{
	  if (tree->left)
	    {
	      tree = tree->left;
	      tree_files(tree);
	      tree = tree->prev;
	    }
	  if (tree->right)
	    {
	      tree = tree->right;
	      tree_files(tree);
	      tree = tree->prev;
	    }
	}
    }
  return (0);
}
