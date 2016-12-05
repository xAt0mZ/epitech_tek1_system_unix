/*
** main.c for tp in /home/baron_l//local/rendu/projets/system_unix/minishell1/tp
** 
** Made by louis-philippe baron
** Login   <baron_l@epitech.net>
** 
** Started on  Mon Dec 17 15:46:56 2012 louis-philippe baron
** Last update Tue Dec 18 10:00:25 2012 louis-philippe baron
*/

int		main(int ac, char **av)
{
  int		pid;
  int		forkval;
  int		ppid;
  int		status;

  forkval = fork();
  pid = getpid();
  if (forkval == 0)
    {
      printf(">FILS : Debut du fils\n");
      sleep(3);
      printf(">FILS : Fin du fils\n");
      return (42);
    }
  else
    {
      wait(&status);
      printf(">PERE : Le fils a terminé, sa valeur de retour est : %d, soit %d / 256\n", status / 256, status);
    }
  return (0);
}
