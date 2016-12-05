
/*
** main.c for minitalk client in /home/baron_l//local/rendu/projets/system_unix/minitalk/rendu/client
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Mar 18 11:15:26 2013 louis-philippe baron
** Last update Wed Mar 20 16:15:40 2013 louis-philippe baron
*/

#include	"hminitalk.h"

int		print_char(unsigned char *tab, int pid)
{
  int		i;

  i = 0;
  while (i < 8)
    {
      if ((tab[i] == 0 && kill(pid, SIGUSR1) == -1)
      	  || (tab[i] == 1 && kill(pid, SIGUSR2) == -1))
      	{
      	  my_putstr("A signal send has failed, program exits\n");
      	  return (ERROR);
      	}
      usleep(TIME);
      my_putchar(tab[i]);
      i++;
    }
  return (0);
}

int		get_bits(unsigned char c, unsigned char *tab)
{
  int		i;

  i = 0;
  while (i < 8)
    tab[i++] = 0;
  i = 7;
  while (i >= 0)
    {
      tab[i] = c % 2;
      c /= 2;
      i--;
    }
  return (0);
}

int		send(char *str, int pid)
{
  int		i;
  unsigned char	tab[8];

  i = 0;
  while (str[i])
    {
      get_bits(str[i], tab);
      if (print_char(tab, pid) == ERROR)
	return (ERROR);
      i++;
    }
  tab[0] = 0;
  tab[1] = 0;
  tab[2] = 0;
  tab[3] = 0;
  tab[4] = 0;
  tab[5] = 0;
  tab[6] = 0;
  tab[7] = 0;
  print_char(tab, pid);
  return (0);
}

static int	client(char *id, char *str)
{
  int		pid;
  int		len;

  if ((pid = my_getnbr(id)) == ERROR)
    {
      my_putstr("Enter a valid pid\n");
      return (ERROR);
    }
  len = 0;
  while (str[len])
    len++;
  if (send_lenght(len, pid) == ERROR)
    return (ERROR);
  usleep(TIME);
  if (send(str, pid) == ERROR)
    return (ERROR);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac == 3)
    {
      if (client(av[1], av[2]) == ERROR)
	return (ERROR);
    }
  else
    my_putstr("Usage : ./client id message\n");
  return (0);
}
