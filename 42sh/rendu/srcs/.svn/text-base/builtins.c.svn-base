/*
** builtins.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/tree
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 17:54:14 2013 Garnero Philip
** Last update Sun May 26 16:12:18 2013 marie lefebvre
*/

#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"h42.h"

int		set_env(char **dtab, t_list **envi)
{
  t_list	*tmp;
  char		*var;
  int		var_len;

  if (dtab[1])
    {
      if (dtab[2])
	{
	  var_len = my_strlen(dtab[1]) + my_strlen(dtab[2]) + 2;
	  if ((var = malloc(sizeof(char) * var_len)) == NULL)
	    return (error_int(MALLOC_ERROR));
	}
      else
	if ((var = malloc(sizeof(char) * (my_strlen(dtab[1]) + 2))) == NULL)
	  return (error_int(MALLOC_ERROR));
      var = my_strcpy(var, dtab[1]);
      var = my_strcat(var, "=");
      if (dtab[2])
	var = my_strcat(var, dtab[2]);
      tmp = finder(dtab[1], *envi);
      verif(tmp, var, envi);
    }
  return (0);
}

int		unset_env(char **dtab, t_list **envi)
{
  t_list	*tmp;
  int		i;

  i = 1;
  while (dtab[i])
    {
      tmp = finder(dtab[i], *envi);
      if (tmp != NULL)
	delete_mail(envi, tmp);
      i = i + 1;
    }
  return (SUCCESS);
}

static int	cd_min(t_list **envi)
{
  char		*str;
  t_list	*pwd;

  pwd = finder("OLDPWD", *envi);
  if (pwd)
    {
      if ((str = malloc(sizeof(char) * (my_strlen(pwd->comp)))) == NULL)
	return (error_int(MALLOC_ERROR));
      memset(str, 0, my_strlen(pwd->comp));
      str = my_strccat(str, pwd->comp, 7);
      set_old(envi);
      if (chdir(str) == -1)
	{
	  free(str);
	  return (error_int("Couldn't access OLDPWD !\n"));
	}
      free(str);
      set_pwd(envi);
    }
  else
    return (error_int("OLDPWD not set !\n"));
  return (0);
}

static int	cd_home(t_list **envi)
{
  char		*str;
  t_list	*tmp;

  if ((tmp = finder("HOME", *envi)) == NULL)
    return (1);
  if ((str = malloc(sizeof(char) * my_strlen(tmp->comp))) == NULL)
    return (error_int(MALLOC_ERROR));
  memset(str, 0, my_strlen(tmp->comp));
  str = my_strccat(str, tmp->comp, 5);
  set_old(envi);
  if (chdir(str) == -1)
    return (error_int("Couldn't access the specified file !\n"));
  set_pwd(envi);
  return (0);
}

int		cd(char **dtab, t_list **envi)
{
  t_list	*pwd;

  pwd = finder("PWD", *envi);
  if (dtab[1] == NULL)
    cd_home(envi);
  else if (dtab[1][0] == '-' && dtab[1][1] == '\0')
    cd_min(envi);
  else
    {
      set_old(envi);
      if (chdir(dtab[1]) == -1)
	return (error_int("Couldn't access the specified file !\n"));
      else if (my_strcmp(dtab[1], "/") == 0)
	verif(pwd, "PWD=/", envi);
      else
	set_pwd(envi);

    }
  return (0);
}
