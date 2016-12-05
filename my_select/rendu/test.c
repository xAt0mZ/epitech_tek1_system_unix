#include	<unistd.h>
#include	<stdlib.h>
#include	<termios.h>
#include	<curses.h>
#include	<term.h>
#include	<sys/ioctl.h>

typedef	struct	termios	t_termios;
#define	ERROR	(-1)

int		main()
{
  t_termios	termios;

  if (tcgetattr(0, &termios) == -1)
    {
      printf("tcgetattr failure for raw mode.\n", 2);
      return (ERROR);
    }
  termios.c_lflag &= ~ICANON;
  termios.c_lflag &= ~ECHO;
  termios.c_cc[VMIN] = 1;
  termios.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &termios) == -1)
    {
      printf("tcsetattr failure for raw mode.\n", 2);
      return (ERROR);
    }
  while (42);
  return (0);
}
