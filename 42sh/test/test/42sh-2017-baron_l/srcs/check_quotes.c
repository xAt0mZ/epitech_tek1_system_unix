/*
** check_quotes.c for 42sh in /home/baron_l//local/rendu/projets/system_unix/42sh/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu May  9 19:41:32 2013 louis-philippe baron
** Last update Fri May 24 18:58:44 2013 louis-philippe baron
*/

#include	"h42.h"

static int	put_error_message(char bool)
{
  if (bool == 1)
    putstr_fd(2, "Unmatched \'.\n");
  else if (bool == 2)
    putstr_fd(2, "Unmatched \".\n");
  if (bool)
    return (ERROR);
  return (0);
}

int	check_quotes(char *str)
{
  int	i;
  char	bool;

  i = 0;
  bool = 0;
  while (str[i])
    {
      if (str[i] == '\'' || str[i] == '\"')
	bool_condition(&bool, str[i]);
      i += 1;
    }
  if (put_error_message(bool) == ERROR)
    return (ERROR);
  return (0);
}
