/*
** double_left_redir.c for minishell2 in /home/baron_l//local/rendu/projets/system_unix/minishell2/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Tue Mar  5 10:05:32 2013 louis-philippe baron
** Last update Tue Mar  5 16:54:24 2013 louis-philippe baron
*/

#include	"hminishell1.h"

int		double_left_redir(char **tmp, t_list *list, char **path)
{
  char		*input;

  my_printf("? ");
  if ((input = get_next_line(0)) == NULL)
    {
      my_printf("get next line faile for double left redir\n");
      return (ERROR);
    }
  while (my_strcmp(tmp[2], input) == ERROR)
    {
      free(input);
      my_printf("? ");
      if ((input = get_next_line(0)) == NULL)
	{
	  my_printf("get next line faile for double left redir\n");
	  return (ERROR);
	}
    }
  free(input);
  if (no_redir(tmp[0], list, path) == ERROR)
    return (ERROR);
  return (0);
}
