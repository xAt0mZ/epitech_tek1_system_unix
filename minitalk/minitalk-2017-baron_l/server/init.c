/*
** init.c for minitalk server in /home/baron_l//local/rendu/projets/system_unix/minitalk/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Tue Mar 19 15:25:42 2013 louis-philippe baron
** Last update Wed Mar 20 15:14:46 2013 louis-philippe baron
*/

#include	"hminitalk.h"

extern t_all	g_all;

int		init()
{
  int		i;

  i = 0;
  while (i < 8)
    g_all.tab[i++] = 0;
  g_all.i = 0;
  g_all.j = 0;
  g_all.size = 0;
  g_all.getting_size = 0;
  g_all.str = NULL;
  return (0);
}
