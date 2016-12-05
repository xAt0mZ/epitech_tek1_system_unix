/*
** globbing.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/srcs
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 19:19:39 2013 Garnero Philip
** Last update Sun May 26 16:15:27 2013 marie lefebvre
*/

#include	<glob.h>
#include	<string.h>
#include	<stdlib.h>
#include	"h42.h"

char		*glob_return(char *pattern)
{
  glob_t	buff;
  char		*rep;
  size_t	i;
  int		size;

  i = 0;
  size = 0;
  glob(pattern, GLOB_BRACE | GLOB_TILDE | GLOB_MARK, NULL, &buff);
  while (i < buff.gl_pathc)
    size = my_strlen(buff.gl_pathv[i++]) + size + 1;
  if ((rep = malloc(sizeof(char) * (size + 2))) == NULL)
    return (error_ptr(MALLOC_ERROR));
  memset(rep, 0, size + 1);
  rep = my_strcat(rep, " ");
  i = 0;
  while (i < buff.gl_pathc)
    {
      rep = my_strcat(rep, buff.gl_pathv[i]);
      i = i + 1;
      if (i != buff.gl_pathc)
	rep = my_strcat(rep, " ");
    }
  globfree(&buff);
  return (rep);
}
