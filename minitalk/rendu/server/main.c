/*
** main.c for minitalk server in /home/baron_l//local/rendu/projets/system_unix/minitalk/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Mar 18 11:16:27 2013 louis-philippe baron
** Last update Wed Mar 20 16:16:32 2013 louis-philippe baron
*/

#include	"hminitalk.h"

t_all		g_all;

static char	get_char(int sig)
{
  if (sig == SIGUSR1)
    g_all.tab[g_all.i] = 0;
  else
    g_all.tab[g_all.i] = 1;
  g_all.i += 1;
  if (g_all.i == 8)
    {
      if ((g_all.str[g_all.j] = (char)my_getnbr(g_all.tab)) != 0)
	{
	  g_all.j++;
	  g_all.i = 0;
	}
      else
	{
	  my_putstr("Client said : ");
	  my_putstr(g_all.str);
	  my_putchar('\n');
	  if (g_all.str)
	    free(g_all.str);
	  init();
	}
    }
  return (0);
}

static int	get_size(int sig)
{
  if (sig == SIGUSR1)
    g_all.tab[g_all.i++] = 0;
  else
    g_all.tab[g_all.i++] = 1;
  if (g_all.i == 8)
    {
      g_all.size = g_all.size * 256 + my_getnbr(g_all.tab);
      g_all.getting_size += 1;
      g_all.i = 0;
    }
  return (0);
}

static void	sighandler(int sig)
{
  if (sig == SIGUSR1)
    my_putchar('0');
  else
    my_putchar('1');
  if (g_all.getting_size < 4)
    get_size(sig);
  if (g_all.getting_size == 4)
    {
      if ((g_all.str = malloc((g_all.size + 1) * sizeof(char))) == NULL)
  	{
  	  my_putstr("Malloc on server failed\n");
  	  exit(ERROR);
  	}
      g_all.getting_size += 1;
    }
  else if (g_all.getting_size > 4)
    get_char(sig);
}

static int	server()
{
  my_putstr("Server pid is : ");
  my_putnbr(getpid());
  my_putchar('\n');
  init();
  signal(SIGUSR1, &sighandler);
  signal(SIGUSR2, &sighandler);
  while (42)
    pause();
  return (0);
}

int		main(int ac, char **av)
{
  (void)av;
  if (ac == 1)
    {
      if (server() == ERROR)
	return (ERROR);
    }
  else
    my_putstr("Usage : ./server\n");
  return (0);
}
