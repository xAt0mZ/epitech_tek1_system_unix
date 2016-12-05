/*
** puts.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Jan 17 14:52:37 2013 louis-philippe baron
** Last update Sat Jan 19 15:48:26 2013 louis-philippe baron
*/

#include	"hselect.h"

int		put_goto(int x, int y)
{
  char		*toto;

  if ((toto = tgetstr("cm", NULL)) == NULL)
    {
      my_putstr("cm capability not supported.\n", 2);
      return (ERROR);
    }
  if ((toto = tgoto(toto, x, y)) == NULL)
    {
      my_putstr("tgoto for cm capability failed.\n", 2);
      return (ERROR);
    }
  if (tputs(toto, 1, tputschar) == -1)
    {
      my_putstr("tputs for cm cpability failed.\n", 2);
      return (ERROR);
    }
  return (0);
}

int		put(char *str)
{
  char		*toto;

  if ((toto = tgetstr(str, NULL)) == NULL)
    {
      my_putstr(str, 2);
      my_putstr(" capability not supported (tgetstr failed).\n", 2);
      return (ERROR);
    }
  if (tputs(toto, 1, tputschar) == -1)
    {
      my_putstr("tputs for ", 2);
      my_putstr(str, 2);
      my_putstr(" capability failed.\n", 2);
      return (ERROR);
    }
  return (0);
}
