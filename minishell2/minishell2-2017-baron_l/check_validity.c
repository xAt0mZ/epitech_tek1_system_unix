/*
** check_validity.c for minishell2 in /home/baron_l//local/rendu/projets/system_unix/minishell2/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Feb 28 16:05:19 2013 louis-philippe baron
** Last update Mon Mar  4 18:06:19 2013 louis-philippe baron
*/

#include	"hminishell1.h"

static int	check_redir(char *command_1, char *command_2)
{
  if ((my_strcmp(command_1, ">") == 0 && my_strcmp(command_2, ">") == 0)
      || (my_strcmp(command_1, "<") == 0 && my_strcmp(command_2, "<") == 0)
      || (my_strcmp(command_1, ">>") == 0 && my_strcmp(command_2, ">>") == 0)
      || (my_strcmp(command_1, "<<") == 0 && my_strcmp(command_2, "<<") == 0))
    {
      my_printf("Ambiguous output redirect.\n");
      return (ERROR);
    }
  return (0);
}

int		is_valid(char **command)
{
  int		k;

  if (command[0][0] == '<' || command[0][0] == '>' || command[0][0] == '|')
    {
      my_printf("Swapped redir -as {> toto ls} for {ls > toto}");
      my_printf(" for example- aren't supported yet\n");
      return (ERROR);
    }
  k = 0;
  while (command[k])
    k++;
  if (k % 2 == 0)
    {
      my_printf("Missing name for redirect.\n");
      return (ERROR);
    }
  if (k == 5 && check_redir(command[1], command[3]) == ERROR)
    return (ERROR);
  return (0);
}

