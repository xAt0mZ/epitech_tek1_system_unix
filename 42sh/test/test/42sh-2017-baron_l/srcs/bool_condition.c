/*
** bool_condition.c for 42sh in /home/baron_l//local/rendu/projets/system_unix/42sh/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Fri May 17 17:38:50 2013 louis-philippe baron
** Last update Wed May 22 16:54:26 2013 Garnero Philip
*/

#include	"h42.h"

void		bool_condition(char *bool, char stri)
{
  if ((*bool == 1 && stri == '\'')
      || (*bool == 2 && stri == '\"'))
    *bool = 0;
  else if (*bool == 0 && stri == '\'')
    *bool = 1;
  else if (*bool == 0 && stri == '\"')
    *bool = 2;
}
