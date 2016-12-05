/*
** get_passwd.c for tp in /home/baron_l//local/rendu/projets/system_unix/my_select/tp
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Jan 16 14:07:52 2013 louis-philippe baron
** Last update Wed Jan 16 14:44:19 2013 louis-philippe baron
*/

#include	<unistd.h>
#include	<termios.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int			main(int ac, char **av)
{
  char			save[256];
  char			buffer[1];
  struct termios	termios;
  int			i;

  tcgetattr(0, &termios);
  my_putstr("Enter your password : ");
  termios.c_lflag &= ~ECHO;
  buffer[0] = 'a';
  tcsetattr(0, TCSANOW, &termios);
  i = 0;
  while (buffer[0] != '\n' && i < 255)
    {
      read(0, buffer, 1);
      save[i] = buffer[0];
      i++;
    }
  save[i] = '\0';
  my_putstr("\nYour password is : ");
  my_putstr(save);
  return (0);
}
