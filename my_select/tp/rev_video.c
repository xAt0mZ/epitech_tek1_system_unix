#include	<termios.h>
#include	<unistd.h>
#include	<curses.h>
#include	<term.h>

int		tputschar(int i)
{
  char		c;

  c = i;
  write(1, &c, 1);
}

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

int			main()
{
  struct termios	termios;
  char			*toto;
  char			buffer[256];

  tgetent(NULL, "xterm");
  toto = tgetstr("mr", NULL);
  tputs(toto, 1, tputschar);
  while (42)
    {
      clean_str(buffer);
      read(0, buffer, 256);
      my_putstr(buffer);
    }
}
