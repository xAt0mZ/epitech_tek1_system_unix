/*
** exec.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/tree
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 17:11:54 2013 Garnero Philip
** Last update Sun May 26 19:51:41 2013 louis-philippe baron
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"h42.h"

static void	delete_quotes(char **tab, char bool)
{
  int		i;
  int		j;

  j = 0;
  while (tab[j])
    {
      i = 0;
      while (tab[j][i])
	{
	  if (tab[j][i] == '\'' || tab[j][i] == '\"')
	    {
	      bool_condition(&bool, tab[j][i]);
	      if ((bool == 1 && tab[j][i] == '\'')
		  || (bool == 2 && tab[j][i] == '\"')
		  || !bool)
		{
		  del_case(&tab[j][i]);
		  i--;
		}
	    }
	  i++;
	}
      j++;
    }
}

static void	choose_prog_e(char **dtab, char **envi, t_glob *glob, int *ret)
{
  if (my_strcmp(dtab[0], "exit") == 0)
    {
      glob->retval = EXIT;
      if (dtab[1] != NULL)
	glob->exit = my_getnbr(dtab[1]);
      else
	glob->exit = 0;
      *ret = EXIT;
    }
  else
    if ((execve(dtab[0], dtab, envi)) == -1)
      {
	putstr_fd(2, "Problem in execve execution !\n");
	exit(-1);
      }
}

int	choose_prog(char **dtab, char **envi, t_glob *glob)
{
  int	ret;

  delete_quotes(dtab, 0);
  if (dtab[0] == NULL)
    return (SUCCESS);
  if (my_strcmp(dtab[0], "cd") == 0)
    ret = cd(dtab, &(glob->env));
  else if (my_strcmp(dtab[0], "env") == 0)
    {
      my_show_list(glob->env);
      ret = SUCCESS;
    }
  else if (my_strcmp(dtab[0], "setenv") == 0)
    ret = set_env(dtab, &(glob->env));
  else if (my_strcmp(dtab[0], "unsetenv") == 0)
    ret = unset_env(dtab, &(glob->env));
  else if (my_strcmp(dtab[0], "echo") == 0)
    ret = my_echo(tab_len(dtab), dtab);
  else
    choose_prog_e(dtab, envi, glob, &ret);
  free_tab(dtab);
  free(envi);
  return (ret);
}
