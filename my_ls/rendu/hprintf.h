/*
** hprintf.h for printf in /home/baron_l//local/rendu/piscine/projets/printf
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Nov 14 13:35:25 2012 louis-philippe baron
** Last update Fri Nov 30 12:34:04 2012 louis-philippe baron
*/

#ifndef	HPRINTF_H_
#define	HPRINTF_H_

#include	<stdarg.h>
#include	<unistd.h>

int		is_a_type(char);
void		simp_type(char, va_list);
void		comp_type(char, va_list);
void		do_print(char, va_list);
int		my_printf(char *, ...);

void		my_putchar(char);
void		my_putstr(char *);
int		my_putnbr(int);
int		my_strlen(char *);
int		my_putnbr_base(unsigned int, char *);
int		my_showstr(char *, char *);

#endif
