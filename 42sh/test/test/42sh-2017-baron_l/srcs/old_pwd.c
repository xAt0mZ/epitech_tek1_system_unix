/*
** old_pwd.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Thu May  9 18:39:27 2013 Garnero Philip
** Last update Sun May 26 16:22:18 2013 marie lefebvre
*/

#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	"h42.h"

static char	*find_cur_pwd()
{
  int		i;
  char		*str;
  DIR		*dir;
  t_stat	sb;
  t_list	*pwd;

  pwd = NULL;
  i = 0;
  str = build_path(i + 1);
  while ((dir = opendir(str)) != NULL && i < 20)
    {
      free(str);
      str = build_path(i);
      if (stat(str, &sb) == -1)
	return (error_ptr("Stat error in pwd builder\n"));
      free(str);
      if ((str = return_good_str(dir, sb.st_ino)) != NULL)
	if (my_put_in_list(&pwd, str) == ERROR)
	  return (NULL);
      if (closedir(dir) == -1)
	return (error_ptr("Close error in pwd builder\n"));
      str = build_path(++i + 1);
    }
  free(str);
  return (pwd_tab(&pwd));
}

void	verif(t_list *tmp, char *to_set, t_list **envi)
{
  if (tmp != NULL)
    {
      delete_mail(envi, tmp);
      my_put_in_list(envi, to_set);
    }
  else
    my_put_in_list(envi, to_set);
}

int		set_old(t_list **envi)
{
  t_list	*old;
  t_list	*pwd;
  char		*str;
  char		*new;

  pwd = finder("PWD", *envi);
  old = finder("OLDPWD", *envi);
  if (pwd)
    {
      if ((str = malloc(sizeof(char) * (my_strlen(pwd->comp) + 4))) == NULL)
	return (error_int(MALLOC_ERROR));
      str = my_strcpy(str, "OLDPWD=");
      str = my_strccat(str, pwd->comp, 4);
    }
  else
    {
      new = find_cur_pwd();
      if ((str = malloc(sizeof(char) * (my_strlen(new) + 8))) == NULL)
	return (error_int(MALLOC_ERROR));
      str = my_strcpy(str, "OLDPWD=");
      str = my_strcat(str, new);
      free(new);
    }
  verif(old, str, envi);
  return (0);
}

int		set_pwd(t_list **envi)
{
  t_list	*pwd;
  char		*str;
  char		*new;

  pwd = finder("PWD", *envi);
  new = find_cur_pwd();
  if ((str = malloc(sizeof(char) * (my_strlen(new) + 8))) == NULL)
    return (error_int(MALLOC_ERROR));
  memset(str, 0, my_strlen(new) + 8);
  str = my_strcpy(str, "PWD=");
  str = my_strcat(str, new);
  free(new);
  verif(pwd, str, envi);
  return (0);
}
