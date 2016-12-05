/*
** basics2.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sun Dec 30 19:36:05 2012 louis-philippe baron
** Last update Mon Feb 11 17:38:13 2013 louis-philippe baron
*/

#include	"hminishell1.h"

int		my_getnbr(char *str)
{
  int		i;
  int		nb;
  int		a;

  i = 0;
  a = 1;
  nb = 0;
  if (str[i] == '-')
    {
      a = a * -1;
      i++;
    }
  while (str[i])
    {
      nb = nb * 10 + (str[i] - '0');
      i++;
    }
  return (nb * a);
}

char		*my_strcpy(char *str)
{
  int		i;
  char		*res;

  i = my_strlen(str);
  if ((res = malloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}

char		*create_inex_path()
{
  int		i;
  char		*res;
  char		*path;

  path = "PATH=/usr/sbin:/usr/bin:/sbin:/bin";
  i = my_strlen(path);
  if ((res = malloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (path[i])
    {
      res[i] = path[i];
      i++;
    }
  return (res);
}
