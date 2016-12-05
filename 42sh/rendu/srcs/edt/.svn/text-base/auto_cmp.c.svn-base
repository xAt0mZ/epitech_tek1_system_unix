/*
** auto_cmp.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Fri May 24 21:26:25 2013 damien sauvalle
** Last update Sun May 26 16:26:37 2013 marie lefebvre
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include	<stdlib.h>
#include	<string.h>
#include "../h42.h"
#include	"edt.h"


char **init_bin()/* utiliser freeTAB*/
{
  char		**bin;

  bin = malloc(sizeof(char*) * 6);
  bin[0] = strdup(".");
  bin[1] = strdup("/bin/");
  bin[2] = strdup("/sbin");
  bin[3] = strdup("/usr/bin");
  bin[4] = strdup("/usr/sbin");
  bin[5] = '\0';
  return (bin);
}

	  /*
	   mettre dans la list
	    si plusieur posibilite afficher 1 par ligne 
	    auto-cmp ls n char
	    si fin chaine ajout 1 espace
	   */

int	if_rigth(int mode)
{
  int i;

  i = 0;
  if (mode & S_IXUSR)
    i++;
  if (mode & S_IXGRP)
    i++;
  if (mode & S_IXOTH)
    i++;
  if (i > 0)
    return (1);
  return (0);
}

int	put_aut_list(t_auto **aut, char *str)
{
  t_auto *elem;
 
  elem = malloc(sizeof(t_auto));
  elem->str = strdup(str);
  elem->next = *aut;
  *aut = elem;
  return (0);
}

void show_aut(t_auto *aut)
{
  t_auto *tmp;
  
  tmp = aut;
  while (tmp)
    {
      my_putstr(tmp->str);
      my_putstr("\n");
      tmp = tmp->next;
    }

}

int pre_put_aut(char *str, char *name, t_auto **aut)
{
  if (str[0] == '\0')
    put_aut_list(aut, name);
  else if (strncmp(str,name, strlen(str)) == 0)/*verifier strncmp & strlen*/
    put_aut_list(aut, name);
  return (0);
}

t_auto *recup_file_bin(char **bin, char *str, int i)
{
  t_auto	*aut;  
  DIR *rep;
  struct dirent *cont;
  struct stat s;
  int mode;
  
  aut = NULL;
  while (bin[i])
    {
      if (access(bin[i], F_OK) == 0)
	{
	  rep = opendir(bin[i]);
	  cont = readdir(rep);
	  while (cont != NULL)
	    {
	      stat(cont->d_name, &s);	
	      mode = s.st_mode;	
	      if (if_rigth(mode) == 1)
		pre_put_aut(str, cont->d_name, &aut);
	      cont = readdir(rep);
	    }
	}
      i++;
    }
  return (aut);
}

void		thats_bin(char *str)
{
  t_auto	*aut;
  char		**bin;
  char		*new;

  bin = init_bin();
  aut = recup_file_bin(bin, str, 0);
  new = str_to_cmp(aut, str);
  printf("\nnew == [%s]\n", new);
}


