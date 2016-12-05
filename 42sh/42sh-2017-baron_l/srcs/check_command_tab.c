/*
** check_command_tab.c for 42sh in /home/baron_l//local/rendu/projets/system_unix/42sh/42sh-2017-baron_l/srcs
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sun May 26 20:21:12 2013 louis-philippe baron
** Last update Sun May 26 21:35:53 2013 louis-philippe baron
*/

#include	"h42.h"

int		check_command_tab(char **tab)
{
  int		k;

  k = 0;
  while (tab[k])
    {
      if (k % 2 == 1)
	{
	  if (my_strcmp(tab[k], "&&") == ERROR
	      && my_strcmp(tab[k], "||") == ERROR
	      && my_strcmp(tab[k], "|") == ERROR)
	    return (error_int("Invalid null command.\n"));
	}
      k++;
    }
  return (0);
}
