/*
** main.c for tp in /home/baron_l//local/rendu/projets/system_unix/my_select/tp
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Jan 14 12:05:49 2013 louis-philippe baron
** Last update Thu Jan 17 13:01:00 2013 louis-philippe baron
*/

#include	<unistd.h>
#include	<termios.h>

static void	my_putchar(char c)
{
  write(1, &c, 1);
}

static void	my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

static void	clean_str(char *str)
{
  int		i;

  i = 0;
  while (i < 256)
    {
      str[i] = '\0';
      i++;
    }
}

int			main(int ac, char **av)
{
  char			buffer[256];
  struct termios	termios;

  tcgetattr(0, &termios);
  printf("%d\n", termios.c_lflag);
  termios.c_lflag &= ~ICANON;
  /* termios.c_lflag &= ~ECHO; */
  tcsetattr(0, TCSANOW, &termios);
  printf("%d\n", termios.c_lflag);
  while (42)
    {
      clean_str(buffer);
      read(0, buffer, 256);
      my_putstr(buffer);
    }
}
