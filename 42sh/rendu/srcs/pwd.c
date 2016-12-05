/*
** pwd.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Thu May  9 18:39:15 2013 Garnero Philip
** Last update Sun May 26 16:22:49 2013 marie lefebvre
*/

#include	<string.h>
#include	<stdlib.h>
#include	"h42.h"

char	*build_path(int i)
{
  char	*str;
  int	j;

  if ((str = malloc(sizeof(char) * ((i * 3) + 3))) == NULL)
    return (error_ptr(MALLOC_ERROR));
  j = 0;
  str[j++] = '.';
  while (j < (i * 3))
    {
      str[j] = '/';
      str[j + 1] = '.';
      str[j + 2] = '.';
      j = j + 3;
    }
  str[j] = '\0';
  return (str);
}

char		*return_good_str(DIR *dir, ino_t ino)
{
  struct dirent	*info;
  char		*ret;

  while ((info = readdir(dir)) != NULL)
    {
      if (info->d_ino == ino)
	{
	  if ((ret = malloc(sizeof(char) * (my_strlen(info->d_name) + 2))) == NULL)
	    return (error_ptr(MALLOC_ERROR));
	  memset(ret, 0, my_strlen(info->d_name));
	  ret[0] = '/';
	  ret[1] = 0;
	  ret = my_strcat(ret, info->d_name);
	  return (ret);
	}
    }
  return (NULL);
}

static void	epur_list(t_list **pwd, t_list *tmp)
{
  if (tmp->next)
    epur_list(pwd, tmp->next);
  if (my_strcmp(tmp->comp, "/.") == 0 || my_strcmp(tmp->comp, "/..") == 0)
    delete_mail(pwd, tmp);
}

char		*return_pwd(t_list **pwd)
{
  t_list	*tmp;
  char		*str;
  int		i;

  i = 0;
  tmp = *pwd;
  while (tmp)
    {
      i = my_strlen(tmp->comp) + i;
      tmp = tmp->next;
    }
  if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
    return (error_ptr(MALLOC_ERROR));
  memset(str, 0, i + 1);
  tmp = *pwd;
  while (tmp)
    {
      my_strcat(str, tmp->comp);
      tmp = tmp->next;
    }
  return (str);
}

char		*pwd_tab(t_list **pwd)
{
  char		*str;
  t_list	*tmp;

  tmp = *pwd;
  epur_list(pwd, tmp);
  my_rev_list(pwd);
  if (*pwd)
    str = return_pwd(pwd);
  else
    {
      if ((str = malloc(sizeof(char) * 2)) == NULL)
	return (error_ptr(MALLOC_ERROR));
      str[0] = '/';
      str[1] = '\0';
    }
  return (str);
}
