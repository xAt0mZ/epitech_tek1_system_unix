/*
** built_exit.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri Dec 28 17:14:17 2012 louis-philippe baron
** Last update Sun Dec 30 11:41:50 2012 louis-philippe baron
*/

#include	"hminishell1.h"

int		built_exit(char **command, char **env)
{
  my_printf("exit\n");
  free_wordtab(command);
  free_wordtab(env);
  exit(0);
}
