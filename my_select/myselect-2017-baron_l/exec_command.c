/*
** exec_command.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Jan 17 12:44:25 2013 louis-philippe baron
** Last update Thu Jan 17 16:32:35 2013 louis-philippe baron
*/

/*
** Note for following function :
** 27 is ESC ascii code / 127 is DEL
*/

#include	"hselect.h"

int		exec_command(char *buffer, t_ptr *ptr, int *i)
{
  if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 'A')
    up(ptr);
  else if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 'B')
    down(ptr);
  else if (buffer[0] == 27 && buffer[1] == '\0')
    echap(ptr, i);
  else if (buffer[0] == 127 || (buffer[0] == 27 && buffer[1] == '['
				&& buffer[2] == '3'))
    del_backspace(ptr, i);
  else if (buffer[0] == '\n')
    *i = 0;
  else if (buffer[0] == ' ')
    space(ptr);
  return (0);
}
