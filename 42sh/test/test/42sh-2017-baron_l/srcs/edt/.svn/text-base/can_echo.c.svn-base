/*
** cano_echo.c for 42sh in /home/sauval_d//EDT
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Wed Apr 17 17:11:46 2013 damien sauvalle
** Last update Sun May 26 20:01:36 2013 damien sauvalle
*/

#include	"edt.h"

int		activ_can_echo(t_term *t)
{
  t->c_lflag &= ~ECHO;
  t->c_lflag &= ~ICANON;
  if (tcsetattr(0, TCSANOW, t) == -1)
    return (-1);
  return (0);
}

int		dis_can_echo(t_term *t)
{
  t->c_lflag |= ECHO;
  t->c_lflag |= ICANON;
  if (tcsetattr(0, TCSANOW, t) == -1)
    return (-1);
  return (0);
}
