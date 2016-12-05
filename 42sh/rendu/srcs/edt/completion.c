/*
** completion.c for 42sh in /home/sauval_d//GIT/42sh/new/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Sun May 19 15:48:11 2013 damien sauvalle
** Last update Sun May 26 11:10:24 2013 damien sauvalle
*/

#include	<string.h>
#include	<stdlib.h>
#include	"../h42.h"
#include	"edt.h"
/*
  ajouter si /  . 
 */

char		*recup_bf(t_item *list)
{
  t_item	*tmp;
  int		i;
  char		*new;

  tmp = list;
  while (tmp->data->cur != 1)
    {
      i++;
      tmp = tmp->next;
    }
  new = malloc(sizeof(char) * (i + 1));
  i = 0;
  tmp = list;
  while (tmp->data->cur != 1)
    {
      new[i] = tmp->data->str;
      i++;
      tmp = tmp->next;
    }
  new[i] = '\0';
  return (new);
}

int     is_in2(char c, char *params, int bool)
{
  int   i;

  if (bool)
    return (1);
  i = 0;
  while (params[i])
    {
      if (params[i] == c)
        return (0);
      i++;
    }
  return (1);
}

int	is_binaire(char *str, int len)/* 1 == binaire*/ /*refaire avec un epur_str*/
{
  int	i;
  
  i = len;
  while (str[i] == ' ' && i > 0)
    i--;
  if (i == 0)
    return (1);
  if (is_in2(str[i], ";|&", 0) == 0)
    return (1);
  while (is_in2(str[i], ";|& ", 0) != 0 && i > 0)
    i--;
  if (is_in2(str[i], ";|&", 0) == 0)
    return (1);
 else
   return (0);
  
}

char	*str_to_compl(char *str, int len)
{
  int	i;
  int	j;
  char	*new;

  i = len;
  if (str[i] == ' ')
    {
      new = malloc(sizeof(char) * 1);
      new[0] = '\0';
      return (new);
    }
  while (is_in(str[i], ";|& ", 0) != 0 && i > 0)
    i--;
  new = malloc(sizeof(char) * (len - i + 2));
  if (is_in(str[i], ";|& ", 0) == 0)
    i++;
  j = 0;
  while (str[i])
    {
      new[j] = str[i];
      j++;
      i++;
    }  
  new[i] = '\0';
  return (new);
}

int	pre_tab(t_charl *list, t_caps *caps)
{
  int	ret;
  char	*str;
  char	*new;
  int	len;

  (void)caps;
  
  if (list->len > 1)
    {  
      str = recup_bf(list->top);
      len  = strlen(str) - 1; 
      if (len > 2)
	ret = is_binaire(str, len);
      new = str_to_compl(str, len);
      free(str);
    }
  else
    {
      new = malloc(sizeof(char) * 2);
      new[0] = '\0';
      ret = 0;
    }
  ret = 1;
  if (ret == 1)
    thats_bin(new);
 
  return (2);
}
