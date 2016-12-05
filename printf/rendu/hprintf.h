/*
** hprintf.h for printf in /home/baron_l//local/rendu/piscine/projets/printf
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Nov 14 13:35:25 2012 louis-philippe baron
** Last update Sat Nov 17 14:25:14 2012 louis-philippe baron
*/

#ifndef	HPRINTF_H_
#define	HPRINTF_H_

#include	<stdarg.h>

#define	C_IS_1	(c == 'd' || c == 'i' || c == 's' || c == 'u' || c == 'x' || c == 'X' || c == 'p' || c == 'b' || c == 'S' || c == 'c' || c == 'o')
#define	C_IS_2	( c == '.' || c == 'e' || c == 'E' || c == 'f' || c == 'F' || c == 'g' || c == 'G' || c == 'a' | c == 'A' || c == '#' || c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '-' || c == ' ' || c == '+' || c == '\'' || c ==  'I' || c == 'h' || c == 'l' || c == 'L' || c == 'q' || c == 'j' || c == 'z' || c == 't')
#define	VARL_UI	(str[i] == 'u' || str[i] == 'x' || str[i] == 'X' || str[i] == 'b' || str[i] == 'o')


int		is_a_type(char);
void		simp_type(char, va_list);
void		comp_type(char, va_list);
void		do_print(char, va_list);
int		my_printf(char *, ...);

#endif
