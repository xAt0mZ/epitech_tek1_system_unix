/*
** auto_comp.c for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Sun May 26 16:55:42 2013 Garnero Philip
** Last update Mon May 27 13:56:53 2013 louis-philippe baron
*/

#include	<string.h>
#include	<stdlib.h>
#include	<glob.h>
#include	"h42.h"

static int	count_words_level(char *tab, int cut)
{
  int		words;
  int		i;

  i = 0;
  words = 0;
  while (tab[i] && i < cut)
    {
      if (tab[i] != 32)
	{
	  words = words + 1;
	  while (tab[i] && tab[i] != 32 && i < cut)
	    i = i + 1;
	}
      else
	i = i + 1;
    }
  return (words);
}

static void	take_word(char *tab, int i, char *word, int cut)
{
  int		j;
  int		k;
  int		count;

  j = 0;
  count = 1;
  while (tab[j] && j < cut)
    {
      if (tab[j] != 32)
	{
	  k = 0;
	  while (tab[j] && tab[j] != 32 && k < 510 && j < cut)
	    {
	      if (count == i && tab[j] != '\"' && tab[j] != '\'')
		word[k++] = tab[j];
	      j = j + 1;
	    }
	  count = count + 1;
	}
      else
	j = j + 1;
    }
}

static int	find_pos(char *tab, int word, int cut)
{
  int		j;
  int		count;

  j = 0;
  count = 1;
  while (tab[j] && j < cut)
    {
      if (tab[j] != 32)
	{
	  while (tab[j] && tab[j] != 32 && j < cut)
	    {
	      if (count == word && tab[j] != '\"' && tab[j] != '\'')
		return (j);
	      j = j + 1;
	    }
	  count = count + 1;
	}
      j = j + 1;
    }
  return (0);
}

char	*my_strccpy(char *dest, char *src, int j)
{
  int	i;

  i = 0;
  while (src[j + i])
    {
      dest[i] = src[j + i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

static char	*concat_str(char *str, char *buff, int cut, int where)
{
  char		*end;
  char		*begin;
  char		*new_str;

  if ((begin = malloc(sizeof(char) * (where + 1))) == NULL)
    return (error_ptr(MALLOC_ERROR));
  if ((end = malloc(sizeof(char) * (my_strlen(str) - cut + 1))) == NULL)
    return (error_ptr(MALLOC_ERROR));
  begin = strncpy(begin, str, where);
  end = my_strccpy(end, str, cut);
  if ((new_str = malloc(sizeof(char) * (my_strlen(begin) + my_strlen(buff)
					+ my_strlen(end) + 1))) == NULL)
    return (error_ptr(MALLOC_ERROR));
  memset(new_str, 0, my_strlen(begin) + my_strlen(buff) + my_strlen(end) + 1);
  strcat(new_str, begin);
  strcat(new_str, buff);
  strcat(new_str, end);
  free(str);
  free(end);
  free(begin);
  return (new_str);
}

static int	strcmp_result(glob_t *buff, int i)
{
  int		j;

  j = 0;
  while (j + 1 < buff->gl_pathc)
    {
      if (buff->gl_pathv[j][i] == 0 || buff->gl_pathv[j + 1][i] == 0)
	return (1);
      if (buff->gl_pathv[j][i] != buff->gl_pathv[j + 1][i])
	return (1);
      j = j + 1;
    }
  return (0);
}

static char	*glob_frenzy(char *str, int nb, int cut, glob_t *buff)
{
  int		i;
  char		tmp[512];

  i = 0;
  while (strcmp_result(buff, i) == 0)
    i = i + 1;
  if (i > 511)
    i = 511;
  strncpy(tmp, buff->gl_pathv[0], i);
  return (concat_str(str, tmp, cut, find_pos(str, nb, cut)));
}

static char	*mid_comp(char *str, int nb, int cut, glob_t *buff)
{
  char		*rep;
  size_t	i;

  i = 0;
  rep = glob_frenzy(str, nb, cut, buff);
  while (i < buff->gl_pathc)
    {
      my_putstr(buff->gl_pathv[i++]);
      my_putchar('\n');
    }
  return (rep);
}

char		*auto_comp(char *str, int cut)
{
  char		pattern[512];
  glob_t	buff;
  int		nb;
  char		*rep;

  if (cut > my_strlen(str))
    cut = my_strlen(str) - 1;
  memset(pattern, 0, 512);
  nb = count_words_level(str, cut);
  take_word(str, nb, pattern, cut);
  my_strcat(pattern, "*");
  glob(pattern, GLOB_TILDE | GLOB_MARK, NULL, &buff);
  rep = str;
  if (buff.gl_pathc == 1)
    rep = concat_str(str, buff.gl_pathv[0], cut, find_pos(str, nb, cut));
  else if (buff.gl_pathc != 0)
    rep = mid_comp(str, nb, cut, &buff);
  globfree(&buff);
  return (rep);
}


int	main(int argc, char **argv)
{
  if (argc == 3)
    my_putstr(auto_comp(strdup(argv[1]), atoi(argv[2])));
  return (0);
}
