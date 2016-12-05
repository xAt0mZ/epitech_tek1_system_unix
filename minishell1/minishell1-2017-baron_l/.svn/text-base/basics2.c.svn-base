/*
** basics2.c for minishell1 in /home/baron_l//local/rendu/projets/system_unix/minishell1/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Sun Dec 30 19:36:05 2012 louis-philippe baron
** Last update Sun Dec 30 20:53:02 2012 louis-philippe baron
*/

#include	"hminishell1.h"

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
  int		k;
  int		j;
  char		*res;
  char		*path[4];

  path[0] = "PATH=/usr/sbin:/usr/bin:/sbin:/bin:/usr/school/sbin:";
  path[1] = "/usr/school/bin:/usr/netsoul/sbin:/usr/netsoul/bin:";
  path[2] = "/usr/kerberos/sbin:/usr/kerberos/bin:";
  path[3] = "/usr/local/sbin:/usr/local/bin:/usr/bin/eclipse";
  i = my_strlen(path[0]) + my_strlen(path[1]) + my_strlen(path[2]) + my_strlen(path[3]);
  if ((res = malloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  k = 0;
  j = 0;
  while (k < 4)
    {
      i = 0;
      while (path[k][i])
	res[j++] = path[k][i++];
      k++;
    }
  res[j] = '\0';
  return (res);
}
