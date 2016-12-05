/*
** modes.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Jan 17 14:50:46 2013 louis-philippe baron
** Last update Sat Jan 19 14:28:57 2013 louis-philippe baron
*/

#include	"hselect.h"

int		raw_mode()
{
  t_termios	termios;

  if (tcgetattr(0, &termios) == -1)
    {
      my_putstr("tcgetattr failure for raw mode.\n", 2);
      return (ERROR);
    }
  termios.c_lflag &= ~ICANON;
  termios.c_lflag &= ~ECHO;
  termios.c_cc[VMIN] = 1;
  termios.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &termios) == -1)
    {
      my_putstr("tcsetattr failure for raw mode.\n", 2);
      return (ERROR);
    }
  return (0);
}

int		normal_mode()
{
  t_termios	termios;

  if (tcgetattr(0, &termios) == -1)
    {
      my_putstr("tcgetattr failure for normal mode.\n", 2);
      return (ERROR);
    }
  termios.c_lflag &= ~ICANON;
  termios.c_lflag &= ~ECHO;
  if (tcsetattr(0, TCSANOW, &termios) == -1)
    {
      my_putstr("tcsetattr failure for normal mode.\n", 2);
      return (ERROR);
    }
  return (0);
}
