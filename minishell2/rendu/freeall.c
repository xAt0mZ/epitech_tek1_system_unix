/*
** freeall.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sun Dec 30 11:38:27 2012 louis-philippe baron
** Last update Sun Dec 30 20:29:27 2012 louis-philippe baron
*/

#include	"hminishell1.h"

int		free_wordtab(char **res)
{
  int		i;

  i = 0;
  while (res[i])
    {
      free(res[i]);
      i++;
    }
  free(res);
  return (0);
}
