/*
** pipe1.c for tp in /home/baron_l//local/rendu/projets/system_unix/minishell2/tp
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Thu Feb 21 09:31:57 2013 louis-philippe baron
** Last update Thu Feb 21 20:47:52 2013 louis-philippe baron
*/

#include	"unistd.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int		main()
{
  int		fdtab[2];
  char		buffer[20];
  int		rd;

  if (pipe(fdtab) == -1)
    {
      printf("pipe error\n");
      return (-1);
    }
  my_putstr("J'écris dans le fd : \"Coucou\"");
  write(fdtab[1], "Coucou", 7);
  my_putstr("Je lis dans le fd :");
  rd = read(fdtab[0], buffer, 19);
  buffer[rd] = '\0';
  printf("%s\n", buffer);
  return (0);
}
