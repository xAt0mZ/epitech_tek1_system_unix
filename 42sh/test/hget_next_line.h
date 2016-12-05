/*
** get_next_line.h for get_next_line in /home/garner_p/Workplace/getnextline-2017-garner_p
** 
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
** 
** Started on  Wed Nov 21 15:02:35 2012 Garnero Philip
** Last update Sun May 26 21:41:02 2013 louis-philippe baron
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

typedef struct		s_charlist
{
  char			letter;
  struct s_charlist	*next;
}			t_charlist;

char		*get_next_line(const int fd);
int		my_put_in_char_list(t_charlist **list, char letter);

#define READ_AMOUNT (1)

#endif /* !GET_NEXT_LINE_H_ */
