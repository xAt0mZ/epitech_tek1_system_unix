/*
** main.c for my_select in /home/baron_l//local/rendu/projets/system_unix/my_select/rendu
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Wed Jan 16 11:46:40 2013 louis-philippe baron
** Last update Tue Mar  5 14:29:33 2013 louis-philippe baron
*/

#include	"hselect.h"

int		modes(t_list *list)
{
  char		buffer[256];
  int		i;
  t_ptr		ptr;

  init_ptr(&ptr, list);
  clean_buffer(buffer);
  i = 1;
  while (i != 0)
    {
      show_list(&list);
      read(0, buffer, 256);
      exec_command(buffer, &ptr, &i);
      clean_buffer(buffer);
    }
  show_final_list(&ptr);
  return (0);
}

int		get_database(char *term, t_list *list)
{
  int		ent;

  ent = tgetent(NULL, term);
  if (ent == 0)
    my_putstr("Term specified is not the good one.\n", 2);
  else if (ent == -1)
    my_putstr("Terminfos database could not be found.\n", 2);
  if (ent == 0 || ent == -1)
    return (ERROR);
  if (raw_mode() == ERROR)
    return (ERROR);
  if (put("vi") == ERROR)
    my_putstr("Cursor will not disappear.\n", 2);
  if (put("cl") == ERROR)
    my_putstr("Screen will not be cleared, some display bugs may happen.\n", 2);
  modes(list);
  if (normal_mode() == ERROR)
    return (ERROR);
  if (put("ve") == ERROR)
    my_putstr("If cursor disappeared it may not appear after program's end.\n", 2);
  return (0);
}

int		my_select(int ac, char **av, char **env)
{
  t_list	*list;
  char		*term;

  if ((list = init_list(ac, av)) == NULL)
    {
      my_putstr("Error in memory allocation.\n", 2);
      return (ERROR);
    }
  if ((term = find_term(env)) == NULL)
    return (ERROR);
  if (get_database(term, list) == ERROR)
    return (ERROR);
  free(term);
  free_list(&list);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  if (ac >= 2)
    {
      if (my_select(ac, av, env) == ERROR)
	return (ERROR);
    }
  else
    my_putstr("Please, enter a list of parameters for the program\n", 2);
  return (0);
}
